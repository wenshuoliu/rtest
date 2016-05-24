#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
void vecIndex() {
  NumericVector x = rnorm(10, 0, 1.);
  Rcout<<x<<std::endl;
  LogicalVector b = x>0;
  Rcout<<b<<std::endl;
  NumericVector y = x[b];
  Rcout<<y<<std::endl;
}


// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically
// run after the compilation.
//

/*** R

*/
