\name{phrAccumulateLine}
\alias{phrAccumulateLine}
\title{Accumulate line(s) for input to phreeqc.}
\usage{
phrAccumulateLine(line)
}
\arguments{
  \item{line}{the line(s) to add for input to phreeqc.}
}
\description{
Appends a line of text to the input buffer in order to be
run using \code{\link{phrRunAccumulated}}.
}
\examples{
# this example loads the phreeqc.dat database, accumulates input, and
# runs it
phrLoadDatabaseString(phreeqc.dat)
phrAccumulateLine("TITLE Example 2.--Temperature dependence of solubility")
phrAccumulateLine("                  of gypsum and anhydrite")
phrAccumulateLine("SOLUTION 1 Pure water")
phrAccumulateLine("        pH      7.0")
phrAccumulateLine("        temp    25.0")
phrAccumulateLine("EQUILIBRIUM_PHASES 1")
phrAccumulateLine("        Gypsum          0.0     1.0")
phrAccumulateLine("        Anhydrite       0.0     1.0")
phrAccumulateLine("REACTION_TEMPERATURE 1")
phrAccumulateLine("        25.0 75.0 in 51 steps")
phrAccumulateLine("SELECTED_OUTPUT")
phrAccumulateLine("        -file   ex2.sel")
phrAccumulateLine("        -temperature")
phrAccumulateLine("        -si     anhydrite  gypsum")
phrAccumulateLine("END")
phrSetOutputFileOn(TRUE)
if (is.null(phrRunAccumulated())) {
  cat(paste("see ", phrGetOutputFileName(), ".\\n", sep = ""))
}
}
\references{
\url{ftp://brrftp.cr.usgs.gov/pub/charlton/iphreeqc/IPhreeqc.pdf}
}
\seealso{
Other Accumulate: \code{\link{phrClearAccumulatedLines}};
\code{\link{phrGetAccumulatedLines}};
\code{\link{phrRunAccumulated}}
}

