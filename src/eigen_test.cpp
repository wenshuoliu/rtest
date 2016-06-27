#include<RcppEigen.h>
#include "eiquadprog.hpp"

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
//[[Rcpp::export]]
List callR(MatrixXd Dmat, VectorXd dvec, MatrixXd Amat, Function f)
{
  List result;
  result = f(Dmat, dvec, Amat);
  return result;
}

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
List quadprog_solveR(const MatrixXd & Dmat, const VectorXd & dvec, const MatrixXd & Amat)
{
  List result;
  Environment myEnv = Environment::namespace_env("quadprog");
  Function quadR = myEnv["solve.QP"];
  result = quadR(Dmat, dvec, Amat);
  return result;
}

//'C++ function implemented by QuadProg++
//'

//'@param Dmat,dvec,Amat See \code{\link[quadprog]{solve.QP}} for explanation.
//'
//'@return a list containing the solution
//'
//'@export
//[[Rcpp::export]]
List quadprog_solveC(const MatrixXd & Dmat, const VectorXd & dvec, const MatrixXd & Amat)
{
  MatrixXd D = Dmat;
  VectorXd d = (-1.)*dvec; //different definition in R package quadprog and QuadProg++

  int n = d.size();
  int m = Amat.rows();

  VectorXd x(n); //to store the solution

  MatrixXd CE = MatrixXd::Zero(n, 1);

  VectorXd ce0(1);
  ce0(0) = 0.;

  VectorXd ci0 = VectorXd::Zero(m);

  double value = solve_quadprog(D, d, CE, ce0, -1.*Amat, ci0, x);
  List res = List::create(Named("solution") = x, Named("value") = value);
  return res;
}

