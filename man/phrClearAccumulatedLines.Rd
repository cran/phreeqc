% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/phreeqc.R
\name{phrClearAccumulatedLines}
\alias{phrClearAccumulatedLines}
\title{Clear the accumulated input buffer.}
\usage{
phrClearAccumulatedLines()
}
\description{
Clears the accumulated input buffer. The input buffer is accumulated from
calls to the \code{\link{phrAccumulateLine}} method.
}
\examples{

# This example loads some keyword input, clears the input, and displays
# the results.
phrAccumulateLine("SOLUTION 1")
phrAccumulateLine("END")
cat("The accumulated input is:", phrGetAccumulatedLines(), sep = "\n")
phrClearAccumulatedLines()
cat("The accumulated input now is:\n", phrGetAccumulatedLines(), sep = "\n")

}
\references{
\url{https://water.usgs.gov/water-resources/software/PHREEQC/IPhreeqc.pdf}
}
\seealso{
Other Accumulate: 
\code{\link{phrAccumulateLine}()},
\code{\link{phrGetAccumulatedLines}()},
\code{\link{phrRunAccumulated}()}
}
\concept{Accumulate}
