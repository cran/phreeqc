\docType{package}
\name{phreeqc-package}
\alias{phreeqc}
\alias{phreeqc-package}
\title{R interface to the PHREEQC geochemical modeling program.}
\description{
An interface to PHREEQC (Version 3). PHREEQC is a
geochemical modeling program developed by the US Geological
Survey that is designed to perform a wide variety of
aqueous geochemical calculations, including speciation,
batch-reaction, one-dimensional reactive-transport, and
inverse geochemical calculations.
}
\details{
\tabular{ll}{Package: \tab phreeqc\cr Type: \tab Package\cr
Version: \tab 1.0-8809\cr Date: \tab 2014-06-26\cr License:
\tab BSD_3_clause + file LICENSE\cr}
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
S.R. Charlton, D.L. Parkhurst, and C.A.J. Appelo, with
contributions from D. Gillespie for Chipmunk BASIC (p2c)
and S.D. Cohen, A.C. Hindmarsh, R. Serban, D. Shumaker, and
A.G. Taylor for CVODE (SUNDIALS) \cr Maintainer: S.R.
Charlton \email{charlton@usgs.gov}
}
\references{
\url{ftp://brrftp.cr.usgs.gov/pub/charlton/iphreeqc/IPhreeqc.pdf}\cr
\url{http://computation.llnl.gov/casc/sundials/main.html}
}
\keyword{package}

