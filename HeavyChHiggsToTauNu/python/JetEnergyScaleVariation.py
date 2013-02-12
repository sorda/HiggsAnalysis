import FWCore.ParameterSet.Config as cms
import PhysicsTools.PatUtils.patPFMETCorrections_cff as patPFMETCorrections

def _doCommon(process, prefix, name, prototype, direction, postfix):
    if not postfix in ["", "Chs"]:
        raise Exception("There are several assumptions of standard PAT, or PF2PAT with Chs-postfix-only workflow")

    if direction not in ["Up", "Down"]:
        raise Exception("direction should be 'Up' or 'Down', was '%s'" % direction)

    analysisName = prefix+name
    pathName = analysisName+"Path"

    analysis = prototype.clone()
    setattr(process, analysisName, analysis)
    # Configure the event counter
    analysis.eventCounter.printMainCounter = cms.untracked.bool(False)

    path = cms.Path(
        process.commonSequence *
        analysis
    )
    setattr(process, pathName, path)

    return (analysis, analysisName)

def addJESVariation(process, prefix, name, prototype, direction, postfix=""):
    (analysis, name) = _doCommon(process, prefix, name, prototype, direction, postfix)

    analysis.jetSelection.src = "shiftedPatJetsEn%sForCorrMEt%s" % (direction, postfix)
    analysis.MET.rawSrc = "patPFMetJetEn%s%s" % (direction, postfix)
    analysis.MET.type1Src = "patType1CorrectedPFMetJetEn%s%s" % (direction, postfix)
    analysis.MET.type2Src = "patType1p2CorrectedPFMetJetEn%s%s" % (direction, postfix)

    return name

def addJERVariation(process, prefix, name, prototype, direction, postfix=""):
    (analysis, name) = _doCommon(process, prefix, name, prototype, direction, postfix)

    analysis.jetSelection.src = "smearedPatJetsRes%s%s" % (direction, postfix)
    analysis.MET.rawSrc = "patPFMetJetRes%s%s" % (direction, postfix)
    analysis.MET.type1Src = "patType1CorrectedPFMetJetRes%s%s" % (direction, postfix)
    analysis.MET.type2Src = "patType1p2CorrectedPFMetJetRes%s%s" % (direction, postfix)

    return name

def addUESVariation(process, prefix, name, prototype, direction, postfix=""):
    (analysis, name) = _doCommon(process, prefix, name, prototype, direction, postfix)

    analysis.MET.rawSrc = "patPFMetUnclusteredEn%s%s" % (direction, postfix)
    analysis.MET.type1Src = "patType1CorrectedPFMetUnclusteredEn%s%s" % (direction, postfix)
    analysis.MET.type2Src = "patType1p2CorrectedPFMetUnclusteredEn%s%s" % (direction, postfix)

    return name

tauVariation = cms.EDProducer("ShiftedPATTauProducer",
    src = cms.InputTag("selectedPatTaus"),
    uncertainty = cms.double(0.03),
    shiftBy = cms.double(+1), # +1/-1 for +-1 sigma variation
)
objectVariationToMet = cms.EDProducer("ShiftedParticleMETcorrInputProducer",
    srcOriginal = cms.InputTag("selectedPatTaus"),
    srcShifted = cms.InputTag("selectedPatTausVariated")
)
def addTESVariation(process, prefix, name, prototype, direction, postfix=""):
    tauVariationName = name+"TauVariation"
    rawMetVariationName = name+"RawMetVariation"
    type1MetVariationName = name+"Type1MetVariation"
    type2MetVariationName = name+"Type2MetVariation"
    analysisName = prefix+name
    sequenceName = name+"VariationSequence"
    pathName = analysisName+"Path"

    sequence = cms.Sequence()
    setattr(process, sequenceName, sequence)
    def add(n, module):
        if not hasattr(process, n):
            setattr(process, n, module)
            mod = module
        else:
            mod = getattr(process, n)
        seq = getattr(process, sequenceName) # I don't know why accessing 'sequence' doesn't work
        seq *= mod
        return n

    tauv = tauVariation.clone(
        src = prototype.tauSelection.src.value(),
    )
    if direction == "Up":
        tauv.shiftBy = +1
    elif direction == "Down":
        tauv.shiftBy = -1
    else:
        raise Exception("direction should be 'Up' or 'Down', was '%s'" % direction)
    add(tauVariationName, tauv)

    # For tau variation for type I MET, we need the selected tau only
    m = cms.EDFilter("HPlusTauSelectorFilter",
        tauSelection = prototype.tauSelection.clone(),
        vertexSrc = prototype.primaryVertexSelection.src,
        filter = cms.bool(False),
        eventCounter = cms.untracked.PSet(counters=cms.untracked.VInputTag())
    )
    selectedTauName = add(name+"SelectedTauForVariation", m)
    m = tauVariation.clone(
        src = selectedTauName
    )
    selectedVariatedTauName = add(name+"SelectedTauVariated", m)
    metCorr = objectVariationToMet.clone(
        srcOriginal = selectedTauName,
        srcShifted = selectedVariatedTauName
    )
    variationMetCorrection = add(tauVariationName+"METCorr", metCorr)

    # Raw MET
    metrawv = patPFMETCorrections.patType1CorrectedPFMet.clone(
        src = prototype.MET.rawSrc.value(),
        srcType1Corrections = [cms.InputTag(variationMetCorrection)]
    )
    add(rawMetVariationName, metrawv)

    # Type I MET
    mettype1v = metrawv.clone(
        src = prototype.MET.type1Src.value(),
    )
    add(type1MetVariationName, mettype1v)

    # Type II MET
    mettype2v = mettype1v.clone(
        src = prototype.MET.type2Src.value()
    )
    add(type2MetVariationName, mettype2v)

    # Construct the signal analysis module for this variation
    analysis = prototype.clone()
    analysis.tauSelection.src = tauVariationName
    analysis.MET.rawSrc = rawMetVariationName
    analysis.MET.type1Src = type1MetVariationName
    analysis.MET.type2Src = type2MetVariationName
    setattr(process, analysisName, analysis)

    # Configure the event counter
    analysis.eventCounter.printMainCounter = cms.untracked.bool(False)

    # Construct the path
    path = cms.Path(
        process.commonSequence *
        sequence *
        analysis
    )
    setattr(process, pathName, path)

    return analysisName
