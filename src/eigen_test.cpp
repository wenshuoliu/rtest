#include<RcppEigen.h>

// [[Rcpp::depends(RcppEigen)]]

//using Eigen::Map;
using Eigen::MatrixXd;
//using Rcpp::as;

//typedef Eigen::Map<Eigen::MatrixXd> MapMatd;



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
