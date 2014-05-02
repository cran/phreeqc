\name{phrSetDumpFileOn}
\alias{phrSetDumpFileOn}
\title{Set the dump file on/off.}
\usage{
phrSetDumpFileOn(value)
}
\arguments{
  \item{value}{if TRUE, captures output normally sent to
  the dump file into a buffer.}
}
\description{
Sets the dump file switch on or off. This switch controls
whether or not phreeqc writes to the dump file. The initial
setting is off.
}
\examples{
# This example equilibrates pure water with calcite and writes the
# dump results to file.
phrLoadDatabaseString(phreeqc.dat)
phrSetDumpFileOn(TRUE)
input <- c(
  'SOLUTION 1 Pure water     ',
  'EQUILIBRIUM_PHASES 1      ',
  '    Calcite 0 10          ',
  'SAVE solution 1           ',
  'SAVE equilibrium_phases 1 ',
  'DUMP                      ',
  '    -solution 1           ',
  '    -equilibrium_phases 1 '
  )

if (is.null(phrRunString(input))) {
  cat("see", phrGetDumpFileName(), "\\n")
}
}
\references{
\url{ftp://brrftp.cr.usgs.gov/pub/charlton/iphreeqc/IPhreeqc.pdf}
}
\seealso{
Other Dump: \code{\link{phrGetDumpFileName}};
\code{\link{phrGetDumpFileOn}};
\code{\link{phrGetDumpStringsOn}};
\code{\link{phrGetDumpStrings}};
\code{\link{phrSetDumpFileName}};
\code{\link{phrSetDumpStringsOn}}
}

