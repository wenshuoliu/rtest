#'Function convolve in R version
#'
#'The function to calculate convolution implemented by R. It comes from the famous
#'  example of \href{https://cran.r-project.org/doc/manuals/r-release/R-exts.html}{
#'  Writing R extensions}.
#'
#'@param a,b two vectors to be convolved
#'@return a vector as the convolution of a and b
#'
#'@examples
#'convolveR(1:3, 2:5)
#'@export
convolveR <- function(a, b)
{
  na <- length(a)
  nb <- length(b)
  nab <- na + nb - 1
  ab <- vector(mode = "numeric", length = nab)
  for (i in 1:na)
    for (j in 1:nb)
      ab[i+j-1] <- ab[i+j-1] + a[i]*b[j]
  return(ab)
}
