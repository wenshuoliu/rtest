#include<RcppEigen.h>

// [[Rcpp::depends(RcppEigen)]]

using namespace Rcpp;
using Eigen::MatrixXd;
using Eigen::VectorXd;

//'test for matrix transpose
//'
//'@param Amat a matrix to be transposed
//'
//'@return the transpose of matrix Amat
//'
//'@export
//[[Rcpp::export]]
MatrixXd transpose(MatrixXd Amat)
{
  return Amat.transpose();
}

//'test for matrix slicing
//'@export
//[[Rcpp::export]]
void matrix_test(MatrixXd Amat)
{
  MatrixXd Bmat = (Amat.array() > 2).select(Amat, 0);
  Rcpp::Rcout<<(Amat.array() > 2)<<std::endl;
  Rcpp::Rcout<<Bmat<<std::endl;
}

//'test for calling an R function
//'
//'Call the R function quadprog::solve.QP to solve a quadratic programming problem
//'
//'@param Dmat,dvec,Amat See \code{\link[quadprog]{solve.QP}} for explanation.
//'
//'@return a list containing the solution
//'
//'@export
//[[Rcpp::export]]
List callR(MatrixXd Dmat, VectorXd dvec, MatrixXd Amat, Function f)
{
  List result;
  result = f(Dmat, dvec, Amat);
  return result;
}
