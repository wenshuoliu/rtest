#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
void vecIndex() {

  /*
  //test for LogicalVector as indices
  NumericVector x = rnorm(10, 0, 1.);
  Rcout<<x<<std::endl;
  LogicalVector b = x>0;
  Rcout<<b<<std::endl;
  NumericVector y = x[b];
  Rcout<<y<<std::endl;
  */
  
  //test for index operator [] and () for NumericalMatrix
  NumericMatrix Amat(4, 3);
  for (int j = 0; j < 3; j++)
    for (int i = 0; i < 4; i++)
      Amat(i, j) = j*4 + i;
  Rcout<<Amat<<std::endl;
  for (int i = 0; i < 4; i++)
    for (int j =0; j < 3; j++)
      Rcout<<Amat(i, j)<<", ";
  Rcout<<std::endl;
  for (int i = 0; i < 12; i++)
    Rcout<<Amat[i]<<", ";
  Rcout<<std::endl;

  NumericVector row = Amat(1, _);
  Rcout<<row<<std::endl;
  NumericVector col = Amat(_, 1);
  Rcout<<col<<std::endl;

  LogicalVector ind = LogicalVector::create(TRUE, FALSE, TRUE, FALSE);
  NumericVector part = Amat(_, 1);
  Rcout<<part<<std::endl;
  NumericVector slice = part[ind];
  Rcout<<slice<<std::endl;
}


// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically
// run after the compilation.
//

/*** R

*/
