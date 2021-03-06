# This file was generated by Rcpp::compileAttributes
# Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#'function convolve in C++ version
#'
#'The function to calculate the convolution of two vectors implemented by C++. It
#' plays as a performance comparison with \code{\link{convolveR}}.
#'
#'@param a,b two vectors to be convolved
#'
#'@return a vector as the convolution of vectors a and b
#'
#'@export
convolveCpp <- function(a, b) {
    .Call('rtest_convolveCpp', PACKAGE = 'rtest', a, b)
}

#'test for matrix transpose
#'
#'@param Amat a matrix to be transposed
#'
#'@return the transpose of matrix Amat
#'
#'@export
transpose <- function(Amat) {
    .Call('rtest_transpose', PACKAGE = 'rtest', Amat)
}

#'test for matrix slicing
#'@export
matrix_test <- function(Amat) {
    invisible(.Call('rtest_matrix_test', PACKAGE = 'rtest', Amat))
}

#'test for calling an R function
#'
#'Call the R function quadprog::solve.QP to solve a quadratic programming problem
#'
#'@param Dmat,dvec,Amat See \code{\link[quadprog]{solve.QP}} for explanation.
#'
#'@return a list containing the solution
callR <- function(Dmat, dvec, Amat, f) {
    .Call('rtest_callR', PACKAGE = 'rtest', Dmat, dvec, Amat, f)
}

#'C++ function to call the R function quadprog::solve.QP
#'
#'Call the R function quadprog::solve.QP to solve a quadratic programming problem
#'
#'@param Dmat,dvec,Amat See \code{\link[quadprog]{solve.QP}} for explanation.
#'
#'@return a list containing the solution
#'
#'@export
quadprog_solveR <- function(Dmat, dvec, Amat) {
    .Call('rtest_quadprog_solveR', PACKAGE = 'rtest', Dmat, dvec, Amat)
}

#'C++ function implemented by QuadProg++
#'
#'@param Dmat,dvec,Amat See \code{\link[quadprog]{solve.QP}} for explanation.
#'
#'@return a list containing the solution
#'
#'@export
quadprog_solveC <- function(Dmat, dvec, At) {
    .Call('rtest_quadprog_solveC', PACKAGE = 'rtest', Dmat, dvec, At)
}

vecIndex <- function() {
    invisible(.Call('rtest_vecIndex', PACKAGE = 'rtest'))
}

#'Generating a partial ordered matrix of beta
#'
#'This function generates a matrix of beta with size p*q, with a partial order in both direction. A parameter
#' theta control the possibility of fusion of adjecent beta.
#'
#'@param p,q Dimensions of the beta matrix
#'@param theta Probability that adjacent beta's have the same value
#'@param ref Whether set the first beta to 0
#'
#'@return A matrix of beta's
#'@export
orderBeta <- function(p, q, theta, ref = TRUE) {
    .Call('rtest_orderBeta', PACKAGE = 'rtest', p, q, theta, ref)
}

#'Function to test the Rcpp suger
#'
#'@param N number of samples
#'@param mu mean
#'@param sigma standard deviation
#'
#'@return Gaussian samples
sugerTest <- function(N, mu, sigma) {
    .Call('rtest_sugerTest', PACKAGE = 'rtest', N, mu, sigma)
}

#'Function timesTwo
#'
#'the function to multipy x by 2
#'
#'@param x a vector
#'@return the vector x*2
#'@examples
#'timesTwo(10)
#'@export
timesTwo <- function(x) {
    .Call('rtest_timesTwo', PACKAGE = 'rtest', x)
}

