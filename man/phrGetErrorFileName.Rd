\name{phrGetErrorFileName}
\alias{phrGetErrorFileName}
\title{Retrieve the name of the error file.}
\usage{
phrGetErrorFileName()
}
\value{
The name of the error file as a string.
}
\description{
Retrieves the name of the error file. The default value is
phreeqc.0.err.
}
\details{
The error file switch must be set using the
\code{\link{phrSetErrorFileOn}} function.
}
\references{
\url{ftp://brrftp.cr.usgs.gov/pub/charlton/iphreeqc/IPhreeqc.pdf}
}
\seealso{
Other Error: \code{\link{phrGetErrorFileOn}};
\code{\link{phrGetErrorStringsOn}};
\code{\link{phrGetErrorStrings}};
\code{\link{phrSetErrorFileName}};
\code{\link{phrSetErrorFileOn}};
\code{\link{phrSetErrorStringsOn}}
}
