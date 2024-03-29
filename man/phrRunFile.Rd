% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/phreeqc.R
\name{phrRunFile}
\alias{phrRunFile}
\title{Run phreeqc input file}
\usage{
phrRunFile(filename)
}
\arguments{
\item{filename}{The file name of the phreeqc input file.}
}
\value{
This function returns NULL on success.
}
\description{
phrRunFile executes a phreeqc run using a file as input
}
\examples{

# load the phreeqc.dat database
phrLoadDatabaseString(phreeqc.dat)

# create ex2 if it doesn't exist
if (!file.exists("ex2")) writeLines(ex2, "ex2")

# run ex2
if (is.null(phrRunFile("ex2"))) {
  cat("use phrGetSelectedOutput() to see results.\n")
}

unlink("ex2")  # tidy up

}
\references{
\url{https://water.usgs.gov/water-resources/software/PHREEQC/IPhreeqc.pdf}
}
\seealso{
Other Run: 
\code{\link{phrRunAccumulated}()},
\code{\link{phrRunString}()}
}
\concept{Run}
