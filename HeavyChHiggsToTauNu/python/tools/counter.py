import math
import copy
import re
import ROOT

import dataset

class CellFormatBase:
    """Base class for cell formats.

    The deriving classes must implement
    _formatValue(value)
    _formatValuePlusMinus(value, uncertainty)
    _formatValuePlusUpMinusLow(value, uncertaintyUp, uncertaintyLow)

    The value, uncertainty(Up|Low) are strings formatted with the
    value/uncertaintyFormats. The deriving class may then apply
    additional formatting for the value/uncertainties, and it must
    construct the plusminus string for single uncertainty, and plus
    upper minus lower string for unequal upper/lower uncertainties.
    """

    def __init__(self, **kwargs):
        """Constructor.

        Keyword arguments:
        valueFormat           Format string for float values (printf style; default: '%.4g')
        uncertaintyFormat     Format string for uncertainties (default: same as valueFormat)
        uncertaintyPrecision  Number of digits to use for comparing if
                              the lower and upper uncertainties are
                              equal (default: 4)
        valueOnly             Boolean, format the value only? (default: False)
        """
        self._valueFormat = kwargs.get("valueFormat", "%.4g")
        self._uncertaintyFormat = kwargs.get("uncertaintyFormat", self._valueFormat)
        self._valueOnly = kwargs.get("valueOnly", False)

        uncertaintyPrecision = kwargs.get("uncertaintyPrecision", 4)
        self._uncertaintyEpsilon = math.pow(10., -1.0*uncertaintyPrecision)

    def format(self, count):
        """Format the Count object."""
        value = self._valueFormat % count.value()
        uUp = count.uncertaintyUp()
        uLow = count.uncertaintyLow()

        if self._valueOnly or (uLow == None and uUp == None):
            return self._formatValue(value)

        if (uLow == 0.0 and uUp == 0.0) or (abs(uUp-uLow)/uUp < self._uncertaintyEpsilon):
            return self._formatValuePlusMinus(value, self._uncertaintyFormat % uLow)
        else:
            return self._formatValuePlusUpMinusLow(value, self._uncertaintyFormat % uUp, self._uncertaintyFormat % uLow)


class CellFormatText(CellFormatBase):
    """Text cell format."""
    def __init__(self, **kwargs):
        """Constructor.

        Keyword arguments:
        Same as CellFormatBase
        """
        CellFormatBase.__init__(self, **kwargs)

    def _formatValue(self, value):
        return value

    def _formatValuePlusMinus(self, value, uncertainty):
        return value + " +- " + uncertainty

    def _formatValuePlusUpMinusLow(self, value, uncertaintyUp, uncertaintyLow):
        return value + " +"+uncertaintyUp + " -"+uncertaintyLow

class CellFormatTeX(CellFormatBase):
    """TeX cell format."""
    def __init__(self, **kwargs):
        """Constructor.

        Keyword arguments
        texifyPower   Boolean, should the 1e4 to be converted to 1\\times 10^{4}? (default: True)
        Same as CellFormatBase
        """
        CellFormatBase.__init__(self, **kwargs)
        self._texifyPower = kwargs.get("texifyPower", True)
        self._texre = re.compile("(?P<sign>[+-])?(?P<mantissa>[^e]*)(e(?P<exponent>.*))?$")

    def _formatValue(self, value):
        return self._texify([value])[0]

    def _formatValuePlusMinus(self, value, uncertainty):
        (v, u) = self._texify([value, uncertainty])
        return v + " \\pm " + u

    def _formatValuePlusUpMinusLow(self, value, uncertaintyUp, uncertaintyLow):
        (v, ul, uh) = self._texify([value, uncertaintyUp, uncertaintyLow])
        return "%s^{+ %s}_{- %s}" % (v, ul, uh)

    def _texify(self, numbers):
        """TeXify the list of numbers.

        If the texifyPower is False, do nothing.

        Convert the numbers such that their exponent is the maximum
        one in the list.
        """
        if not self._texifyPower:
            return numbers

        # Check if none of the numbers have exponents
        if reduce(lambda x,y: x+y, map(lambda n: "e" in n, numbers)) == 0:
            return numbers

        maxExp = max([self._getExponent(n) for n in numbers])
        expStr = "\\times 10^{%d}" % maxExp

        # Only one number
        if len(numbers) == 1:
            return [self._texifyOne(n, maxExp)+expStr]

        # Many numbers, show the exponent only in the last one, use parenthesis
        ret = [self._texifyOne(n, maxExp) for n in numbers]
        ret[0] = "\\left("+ret[0]
        ret[-1] = ret[-1]+"\\right)"+expStr
        return ret

    def _getExponent(self, number):
        if not "e" in number:
            return 0
        m = self._texre.search(number)
        return int(m.group("exponent"))

    def _texifyOne(self, number, targetExp):
        m = self._texre.search(number)
        exp = m.group("exponent")
        if exp == None:
            exp = 0
        else:
            exp = int(exp)

        mantissa = m.group("mantissa")
        sign = m.group("sign")
        if sign == None:
            sign = ""

        if exp == targetExp:
            return mantissa
        elif exp < targetExp:
            return sign + "0."+ ("0"*(targetExp-exp-1)) + mantissa.replace(".", "")
        else:
            # Sanity check
            raise Exception("This condition should never happen")

class TableFormatBase:
    """Base class for table formats.

    The deriving classes must either give the
    (begin|end)(Table|Row|Column) as arguments to the constructor, or
    implement the corresponding method(s) themselvels.

    The format method should not be overridden by a deriving class.
    """

    def __init__(self, cellFormat, **kwargs):
        """Constructor.

        Arguments:
        cellFormat   CellFormatBase (or anything deriving from it) for the default cell format

        Keyword arguments:
        beginTable    String for table beginning
        endTable      String for table ending
        beginRow      String for row beginning
        endRow        String for for ending
        beginColumn   String for column beginning
        endColumn     String for column ending
        """
        self.defaultCellFormat = cellFormat

        for x in ["beginTable", "endTable", "beginRow", "endRow", "beginColumn", "endColumn"]:
            try:
                setattr(self, "_"+x, kwargs[x])
            except KeyError:
                setattr(self, "_"+x, "")

    def beginTable(self, ncolumns):
        """Format table beginning.

        Arguments:
        ncolumns   Number of columns in the table
        """
        return self._beginTable

    def endTable(self):
        """Format table ending."""
        return self._endTable

    def beginRow(self, firstRow):
        """Format row beginning.

        Arguments:
        firstRow   Boolean, is this the first row?
        """
        return self._beginRow

    def endRow(self, lastRow):
        """Format row ending.

        Arguments:
        lastRow   Boolean, is this the last row?
        """
        return self._endRow

    def beginColumn(self, firstColumn):
        """Format column beginning.

        Arguments:
        firstColumn   Boolean, is this the first column?
        """
        return self._beginColumn

    def endColumn(self, lastColumn):
        """Format column beginning.

        Arguments:
        lastColumn   Boolean, is this the last column?
        """
        return self._endColumn

    def formatCell(self, count):
        """Format a cell.

        Arguments:
        count   Count object to format
        """
        return self.defaultCellFormat.format(count)


class TableFormatText(TableFormatBase):
    """Text table format."""
    def __init__(self, cellFormat=CellFormatText(), beginRow="", columnSeparator = "  ", endRow = ""):
        """Constructor.

        Arguments:
        cellFormat        Cell formatting (default: CellFormatText())
        beginRow          String for row beginning (default: '')
        columnSeparator   String for column separation (default: '  ')
        endRow            String for row ending (default: '')
        """
        TableFormatBase.__init__(self, cellFormat, beginTable="", endTable="", beginRow=beginRow, endRow=endRow,
                                 beginColumn="")
        self._columnSeparator = columnSeparator

    def endColumn(self, lastColumn):
        if not lastColumn:
            return self._columnSeparator
        else:
            return ""

class TableFormatLaTeX(TableFormatBase):
    """LaTeX table (tabular) format."""
    def __init__(self, cellFormat=CellFormatTeX()):
        """Constructor.

        Arguments:
        cellFormat    Cell formatting (default: CellFromatTeX())
        """
        TableFormatBase.__init__(self, cellFormat, endTable="\\end{tabular}",
                                 beginRow="  ", endRow = " \\\\",
                                 beginColumn="")

    def beginTable(self, ncolumns):
        return "\\begin{tabular}{%s}" % ("l"*ncolumns)

    def endColumn(self, lastColumn):
        if not lastColumn:
            return " && "
        else:
            return ""

class TableFormatConTeXtTABLE(TableFormatBase):
    """ConTeXt TABLE format.

    For more information see http://wiki.contextgarden.net/TABLE
    """

    def __init__(self, cellFormat=CellFormatTeX()):
        """Constructor.

        Arguments:
        cellFormat    Cell formatting (default: CellFromatTeX())
        """
        TableFormatBase.__init__(self, cellFormat, beginTable="\\bTABLE", endTable="\\eTABLE",
                                 beginRow="  \\bTR", endRow="\\eTR",
                                 beginColumn="\\bTD ", endColumn=" \\eTD")

class TableSplitter:
    def __init__(self, separators, removeSeparators=False):
        if isinstance(separators, str):
            self._separators = [separators]
        else:
            self._separators = separators
        self._removeSeparators = removeSeparators

    def split(self, content):
        nrows = len(content)
        if nrows == 0:
            return
        ncols = len(content[0])
        if ncols == 0:
            return

        ret = [[] for x in xrange(0, nrows)]

        for icol in xrange(0, ncols):
            # Do the splitting, and the maximum number of splits in the column
            nsplits = 0
            rows = []
            for irow in xrange(0, nrows):
                n = 0
                row = []
                cell = content[irow][icol]

                start = 0
                ind = 0
                while ind < len(cell):
                    foundSeparator = False
                    for sep in self._separators:
                        if cell[ind:ind+len(sep)] == sep:
                            row.append(cell[start:ind])
                            if not self._removeSeparators:
                                row.append(sep)
                            ind += len(sep)
                            start = ind

                            foundSeparator = True
                            break
                    if not foundSeparator:
                        ind += 1
                row.append(cell[start:len(cell)])
                            
                rows.append(row)
                nsplits = max(len(row), nsplits)

            # Then append empty cells for those rows which had less splits than the maximum
            for irow, cell in enumerate(rows):
                if len(cell) > nsplits:
                    raise Exception("This should never happen!")
                if len(cell) < nsplits:
                    cell += ["" for x in xrange(0, nsplits-len(cell))]
                ret[irow].extend(cell)
   
        return ret


def counterEfficiency(counterTable):
    """Create a new counter table with the counter efficiencies."""
    result = counterTable.deepCopy()
    for icol in xrange(0, counterTable.getNcolumns()):
        prev = None
        for irow in xrange(0, counterTable.getNrows()):
            count = counterTable.getValue(irow, icol)
            value = None
            if count != None and prev != None:
                try:
                    value = dataset.Count(count.value() / prev.value(), None)
                except ZeroDivisionError:
                    pass
            prev = count
            result.setValue(irow, icol, value)
    return result

class CounterColumn:
    """Class represring a column in CounterTable."""
    def __init__(self, name, rowNames, values):
        self.name = name
        self.rowNames = rowNames
        self.values = values

        if len(rowNames) != len(values):
            raise Exception("len(rowNames) != len(values) (%d != %d)" % (len(rowNames), len(values)))

    def getName(self):
        return self.name

    def setName(self, name):
        self.name = name

    def getNrows(self):
        return len(self.values)

    def getRowName(self, irow):
        return self.rowNames[irow]

    def getValue(self, irow):
        return self.values[irow]

class CounterTable:
    """Class to represent a table of counts.

    It is separated from Counter class in order to contain only the
    table and to have certain table operations.
    """
    
    def __init__(self):
        self.rowNames = []
        self.columnNames = []
        self.table = [] # table[row][column]

    def deepCopy(self):
        return copy.deepcopy(self)

    def getNrows(self):
        return len(self.table)

    def getNcolumns(self):
        if self.getNrows() == 0:
            return 0
        return len(self.table[0])

    def getValue(self, irow, icol):
        return self.table[irow][icol]

    def setValue(self, irow, icol, value):
        self.table[irow][icol] = value

    def renameRows(self, mapping):
        for irow, row in enumerate(self.rowNames):
            if row in mapping:
                self.rowNames[irow] = mapping[row]

    def indexColumn(self, name):
        return self.columnNames.index(name)

    def appendColumn(self, column):
        self.insertColumn(self.getNcolumns(), column)

    def insertColumn(self, icol, column):
        iname = 0
        icount = 0

        beginColumns = 0
        if len(self.table) > 0:
            beginColumns = len(self.table[0])

        while iname < len(self.rowNames)  and icount < column.getNrows():
            # Check if the current indices give the same counter name for both
            if self.rowNames[iname] == column.getRowName(icount):
                self.table[iname].insert(icol, column.getValue(icount))
                iname += 1
                icount += 1
                continue

            # Search the list of names for the name of count
            found = False
            for i in xrange(iname, len(self.rowNames)):
                if self.rowNames[i] == column.getRowName(icount):
                    self.table[i].insert(icol, column.getValue(icount))
                    iname = i+1
                    icount += 1
                    found = True
                    break
                else:
                    self.table[i].insert(icol, None)
            if found:
                continue

            # Count not found, insert the count after the previous
            # found name
            self.rowNames.insert(iname, column.getRowName(icount))
            row = [None]*(beginColumns+1)
            row[icol] = column.getValue(icount)
            self.table.insert(iname, row)
            iname += 1
            icount += 1

        # Add the remaining counters from column
        for i in xrange(icount, column.getNrows()):
            self.rowNames.append(column.getRowName(i))
            row = [None]*(beginColumns+1)
            row[icol] = column.getValue(i)
            self.table.append(row)

        # Sanity check
        for row in self.table:
            if len(row) < beginColumns+1:
                print row
                raise Exception("Internal error: len(row) = %d, beginColumns = %d" % (len(row), beginColumns))

        self.columnNames.insert(icol, column.getName())

    def getColumn(self, icol):
        # Extract the data for the column
        rowNames = self.rowNames[:]
        colValues = [self.table[irow][icol] for irow in xrange(0, self.getNrows())]

        # Filter out Nones
        i = 0
        while i < len(colValues):
            if colValues[i] == None:
                del rowNames[i]
                del colValues[i]
                i -= 1
            i += 1

        # Construct the column object
        return CounterColumn(self.columnNames[icol], rowNames, colValues)

    def removeColumn(self, icol):
        def rowAllNone(row):
            for col in row:
                if col != None:
                    return False
            return True

        del self.columnNames[icol]
        irow = 0
        while irow < len(self.table):
            del self.table[irow][icol]
            if rowAllNone(self.table[irow]):
                del self.rowNames[irow]
                del self.table[irow]
                irow -= 1

            irow += 1

    def _getColumnWidth(self, icol):
        return self.columnWidths[icol]

    def _header(self, formatter):
        return ["Counter"] + self.columnNames

    def _content(self, formatter):
        content = []
        for irow in xrange(0, self.getNrows()):
            row = [self.rowNames[irow]]
            for icol in xrange(0, self.getNcolumns()):
                count = self.getValue(irow, icol)
                if count != None:
                    row.append(formatter.formatCell(count))
                else:
                    row.append("")
            content.append(row)
        return content

    def _columnWidths(self, content):
        widths = [0]*(len(content[0]))
        for row in content:
            for icol, col in enumerate(row):
                widths[icol] = max(widths[icol], len(col))
        return widths

    def format(self, formatter=TableFormatText(), splitter=None):
        if self.getNcolumns() == 0 or self.getNrows() == 0:
            return ""

        content = [self._header(formatter)] + self._content(formatter)

        if splitter != None:
            content = splitter.split(content)

        nrows = len(content)
        ncols = len(content[0])

        columnWidths = self._columnWidths(content)
        columnFormat = "{value:<{width}}"
        lines = [formatter.beginTable(ncols)]
        lastRow = nrows-1
        lastColumn = ncols-1
        for irow, row in enumerate(content):
            line = formatter.beginRow(irow==0)
            for icol, column in enumerate(row):
                line += formatter.beginColumn(icol==0)
                line += columnFormat.format(width=columnWidths[icol], value=column)
                line += formatter.endColumn(icol==lastColumn)
            line += formatter.endRow(irow==lastRow)
            lines.append(line)

        lines.append(formatter.endTable())
        return "\n".join(lines)

class SimpleCounter:
    """Counter for one dataset."""
    def __init__(self, datasetRootHisto, countNameFunction):
        self.datasetRootHisto = datasetRootHisto
        self.counter = None
        if countNameFunction != None:
            self.countNames = [countNameFunction(x) for x in datasetRootHisto.getBinLabels()]
        else:
            self.countNames = datasetRootHisto.getBinLabels()

    def normalizeToOne(self):
        if self.counter != None:
            raise Exception("Can't normalize after the counters have been created!")
        self.datasetRootHisto.normalizeToOne()

    def normalizeMCByCrossSection(self):
        if self.counter != None:
            raise Exception("Can't normalize after the counters have been created!")
        if self.datasetRootHisto.getDataset().isMC():
            self.datasetRootHisto.normalizeByCrossSection()

    def normalizeMCToLuminosity(self, lumi):
        if self.counter != None:
            raise Exception("Can't normalize after the counters have been created!")
        if self.datasetRootHisto.getDataset().isMC():
            self.datasetRootHisto.normalizeToLuminosity(lumi)

    def scale(self, value):
        if self.counter != None:
            raise Exception("Can't scale after the counters have been created!")
        self.datasetRootHisto.scale(value)

    def _createCounter(self):
        self.counter = [x[1] for x in dataset._histoToCounter(self.datasetRootHisto.getHistogram())]

    def getName(self):
        return self.datasetRootHisto.getDataset().getName()

    def getNrows(self):
        return len(self.countNames)

    def getRowName(self, icount):
        return self.countNames[icount]

    def getValue(self, icount):
        if self.counter == None:
            self._createCounter()
        return self.counter[icount]

    def getCountByName(self, name):
        if self.counter == None:
            self._createCounter()
        for i, cn in enumerate(self.countNames):
            if cn == name:
                return self.counter[i]
        raise Exception("No counter '%s'" % name)

class Counter:
    """Counter for many datasets."""
    def __init__(self, datasetRootHistos, countNameFunction):
        self.counters = [SimpleCounter(h, countNameFunction) for h in datasetRootHistos]

    def forEachDataset(self, func):
        for c in self.counters:
            func(c)

    def normalizeToOne(self):
        self.forEachDataset(lambda x: x.normalizeToOne())

    def normalizeMCByCrossSection(self):
        self.forEachDataset(lambda x: x.normalizeMCByCrossSection())

    def normalizeMCByLuminosity(self):
        lumi = None
        for c in self.counters:
            if c.datasetRootHisto.getDataset().isData():
                if lumi != None:
                    raise Exception("Unable to normalize by luminosity, more than one data datasts (you might want to merge data datasets)")
                lumi = c.datasetRootHisto.getDataset().getLuminosity()
        if lumi == None:
            raise Exception("Unable to normalize by luminosity. no data datasets")

        self.normalizeMCToLuminosity(lumi)

    def normalizeMCToLuminosity(self, lumi):
        self.forEachDataset(lambda x: x.normalizeMCToLuminosity(lumi))

    def scale(self, value):
        self.forEachDataset(lambda x: x.scale(value))

    def getTable(self):
        table = CounterTable()
        for h in self.counters:
            table.appendColumn(h)
        return table

class EventCounter:
    """Many counters."""
    def __init__(self, datasets, countNameFunction=None):
        counterNames = {}

        if len(datasets.getAllDatasets()) == 0:
            raise Exception("No datasets")

        # Pick all possible names of counters
        counterDir = None
        for dataset in datasets.getAllDatasets():
            if counterDir == None:
                counterDir = dataset.getCounterDirectory()
            else:
                if counterDir != dataset.getCounterDirectory():
                    raise Exception("Sanity check failed, datasets have different counter directories!")

            for name in dataset.getDirectoryContent(counterDir, lambda obj: isinstance(obj, ROOT.TH1)):
                counterNames[name] = 1

        try:
            del counterNames["counter"]
        except KeyError:
            raise Exception("Error: no 'counter' histogram in the '%s' directories" % counterDir)

        self.mainCounter = Counter(datasets.getDatasetRootHistos(counterDir+"/counter"), countNameFunction)
        self.subCounters = {}
        for subname in counterNames.keys():
            self.subCounters[subname] = Counter(datasets.getDatasetRootHistos(counterDir+"/"+subname), countNameFunction)

        self.normalization = "None"

    def _forEachCounter(self, func):
        func(self.mainCounter)
        for c in self.subCounters.itervalues():
            func(c)

    def normalizeToOne(self):
        self._forEachCounter(lambda x: x.normalizeToOne())
        self.normalization = "All normalized to unit area"

    def normalizeMCByCrossSection(self):
        self._forEachCounter(lambda x: x.normalizeMCByCrossSection())
        self.normalization = "MC normalized to cross section (pb)"

    def normalizeMCByLuminosity(self):
        self._forEachCounter(lambda x: x.normalizeMCByLuminosity())
        self.normalization = "MC normalized by data luminosity"

    def normalizeMCToLuminosity(self, lumi):
        self._forEachCounter(lambda x: x.normalizeMCToLuminosity(lumi))
        self.normalization = "MC normalized to luminosity %f pb^-1" % lumi

    def scale(self, value):
        self._forEachCounter(lambda x: x.scale(value))
        self.normalization += " (scaled with %g)" % value

    def getMainCounter(self):
        return self.mainCounter

    def getMainCounterTable(self):
        return self.mainCounter.getTable()

    def getSubCounterNames(self):
        return self.subCounters.keys()

    def getSubCounter(self, name):
        return self.subCounters[name]

    def getSubCounterTable(self, name):
        return self.subCounters[name].getTable()

    def getNormalizationString(self):
        return self.normalization
