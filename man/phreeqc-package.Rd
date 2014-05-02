\docType{package}
\name{phreeqc-package}
\alias{phreeqc}
\alias{phreeqc-package}
\title{R interface to the phreeqc geochemical modeling program.}
\description{
Provides an interface to PHREEQC (Version 3)--A Computer
Program for Speciation, Batch-Reaction, One-Dimensional
Transport, and Inverse Geochemical Calculations.
}
\details{
\tabular{ll}{ Package: \tab phreeqc\cr Type: \tab
Package\cr Version: \tab 1.0\cr Date: \tab 2014-02-05\cr
License: \tab Unlimited\cr }
}
\examples{
#########################################################################
# Run ex2 and plot results
#########################################################################

# load the phreeqc.dat database
phrLoadDatabaseString(phreeqc.dat)

# run example 2
phrRunString(ex2)

# retrieve selected_output as a list of data.frame
so <- phrGetSelectedOutput()

# plot the results
attach(so$n1)
title  <- "Gypsum-Anhydrite Stability"
xlabel <- "Temperature, in degrees celcius"
ylabel <- "Saturation index"
plot(temp.C., si_gypsum, main = title, xlab = xlabel, ylab = ylabel,
     col = "darkred", xlim = c(25, 75), ylim = c(-0.4, 0.0))
points(temp.C., si_anhydrite, col = "darkgreen")
legend("bottomright", c("Gypsum", "Anhydrite"),
       col = c("darkred", "darkgreen"), pch = c(1, 1))
}
\author{
David L. Parkhurst \email{dlpark@usgs.gov}\cr C.A.J. Appelo
\email{appt@hydrochemistry.eu}\cr Maintainer: Scott R.
Charlton \email{charlton@usgs.gov}
}
\references{
\url{ftp://brrftp.cr.usgs.gov/pub/charlton/iphreeqc/IPhreeqc.pdf}
}
\keyword{package}

