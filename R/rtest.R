#'rtest: a test package
#'
#'The rtest package is a package I write to learn to write a package.
#'
#'@section rtest functions:
#'The rtest package includes functions:
#'
#'\link{hello}: template function that prints "hello"
#'
#'\link{convolveR}: Function convolve in R version
#'
#'\link{convolveCpp}: function convolve in C++ version
#'
#'\link{transpose}: test for matrix transpose implemented in C++
#'
#'\link{matrix_test}: test for matrix manipulation in Rcpp classes and Eigen templates
#'
#'\link{callR}: test for calling an R function in C++ code
#'
#'\link{quadprog_solveR}: C++ function to call the R function quadprog::solve.QP
#'
#'\link{quadprog_solveC}: C++ function implemented by QuadProg++
#'
#'\link{orderBeta}: Generating a partial ordered matrix of beta
#'
#'\link{posdefmat}: function to generate random positive definite matrice
#'
#'@docType package
#'@name rtest
#'@useDynLib rtest
#'@importFrom Rcpp sourceCpp
NULL
