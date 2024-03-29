% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/phreeqc.R
\name{phrGetLogStrings}
\alias{phrGetLogStrings}
\title{Retrieve log output.}
\usage{
phrGetLogStrings()
}
\value{
A character vector containing phreeqc log output.
}
\description{
Retrieves the string buffer containing phreeqc log output.
}
\examples{

# This example equilibrates pure water with gypsum with the output file on.
phrLoadDatabaseString(phreeqc.dat)
phrSetLogStringsOn(TRUE)

input <- vector(mode="character")
input <- c(input, "SOLUTION 1 Pure water ")
input <- c(input, "EQUILIBRIUM_PHASES 1  ")
input <- c(input, "  Gypsum 0 10         ")
input <- c(input, "KNOBS                 ")
input <- c(input, "  -logfile TRUE       ")

if (is.null(phrRunString(input))) {
  log <- phrGetLogStrings()
}

}
\references{
\url{https://water.usgs.gov/water-resources/software/PHREEQC/IPhreeqc.pdf}
}
\seealso{
Other Log: 
\code{\link{phrGetLogFileName}()},
\code{\link{phrGetLogFileOn}()},
\code{\link{phrGetLogStringsOn}()},
\code{\link{phrSetLogFileName}()},
\code{\link{phrSetLogFileOn}()},
\code{\link{phrSetLogStringsOn}()}
}
\concept{Log}
