#include<RcppEigen.h>

// [[Rcpp::depends(RcppEigen)]]

using namespace Rcpp;
using Eigen::MatrixXd;
using Eigen::VectorXd;
using Eigen::VectorXi;
using Eigen::MatrixXi;
using Eigen::MatrixXf;
using Eigen::VectorXf;

//'C++ function to call the R function quadprog::solve.QP
//'
//'Call the R function quadprog::solve.QP to solve a quadratic programming problem
//'
//'@param Dmat,dvec,Amat See \code{\link[quadprog]{solve.QP}} for explanation.
//'
//'@return a list containing the solution
//'
//'@export
//[[Rcpp::export]]
List quadprog_solve(const MatrixXd & Dmat, const VectorXd & dvec, const MatrixXd & Amat)
{
  List result;
  Environment myEnv = Environment::namespace_env("quadprog");
  Function quadR = myEnv["solve.QP"];
  result = quadR(Dmat, dvec, Amat);
  return result;
}
