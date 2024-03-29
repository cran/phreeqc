% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/phreeqc.R
\name{phrRunString}
\alias{phrRunString}
\title{Runs phreeqc using the given string as input.}
\usage{
phrRunString(input)
}
\arguments{
\item{input}{character vector containing phreeqc input}
}
\value{
This function returns NULL on success.
}
\description{
Runs phreeqc using the given string as input. Returns the number of
errors encountered during the run.
}
\details{
The \code{RunString} method cannot be called until a database has
been successfully loaded by one of the following the LoadDatabase
methods \code{\link{phrLoadDatabase}}, \code{\link{phrLoadDatabaseString}}.
}
\examples{

#
# This example accumulates phreeqc input into a character vector
# and runs it.
#

# load phreeqc.dat file
phrLoadDatabaseString(phreeqc.dat)

# create input
input <- vector()
input <- c(input, "SOLUTION 1") 
input <- c(input, "  temp 25.0") 
input <- c(input, "  pH    7.0")

# turn on output
phrSetOutputFileOn(TRUE)
phrSetOutputFileName(file.path(tempdir(), "pure_water.out"))

# run input
phrRunString(input)
cat(paste("see ", phrGetOutputFileName(), ".\n", sep=""))

}
\references{
\url{https://water.usgs.gov/water-resources/software/PHREEQC/IPhreeqc.pdf}
}
\seealso{
Other Run: 
\code{\link{phrRunAccumulated}()},
\code{\link{phrRunFile}()}
}
\concept{Run}
\keyword{interface}
