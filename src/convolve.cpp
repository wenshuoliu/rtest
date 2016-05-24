#include<Rcpp.h>

using namespace Rcpp;

//'function convolve in C++ version
//'
//'The function to calculate the convolution of two vectors implemented by C++. It
//' plays as a performance comparison with \code{\link{convolveR}}.
//'
//'@param a,b two vectors to be convolved
//'
//'@return a vector as the convolution of vectors a and b
//'
//'@export
//[[Rcpp::export]]
NumericVector convolveCpp(NumericVector a, NumericVector b){
  int na = a.size();
  int nb = b.size();
  int nab = na + nb - 1;
  NumericVector ab(nab);
  for (int i=0;i<na; i++)
    for (int j = 0; j<nb; j++){
      ab[i+j] += a[i]*b[j];
    }
  return ab;
}

