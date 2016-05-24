#include <Rcpp.h>
using namespace Rcpp;

//'Function to test the Rcpp suger
//'
//'@param N number of samples
//'@param mu mean
//'@param sigma standard deviation
//'
//'@return Gaussian samples
// [[Rcpp::export]]
NumericVector sugerTest(int N, double mu, double sigma) {
  return rnorm(N, mu, sigma);
}

/*** R
sugerTest(100, 0, 1)
*/
