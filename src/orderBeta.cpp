#include <Rcpp.h>
using namespace Rcpp;

class coord{
public:
  explicit coord(int i, int j){
    i_ = i;
    j_ = j;
  }
  int i(){
    return i_;
  }
  int j(){
    return j_;
  }
  friend std::ostream & operator<<(std::ostream & os, const coord & co){
    os<<co.i_<<","<<co.j_;
    return os;
  }
private:
  int i_;
  int j_;
};

//'Generating a partial ordered matrix of beta
//'
//'This function generates a matrix of beta with size p*q, with a partial order in both direction. A parameter
//' theta control the possibility of fusion of adjecent beta.
//'
//'@param p,q Dimensions of the beta matrix
//'@param theta Probability that adjacent beta's have the same value
//'@param ref Whether set the first beta to 0
//'
//'@return A matrix of beta's
//'@export
// [[Rcpp::export]]
NumericMatrix orderBeta(int p, int q, double theta, bool ref = 1) {
  NumericMatrix beta(p, q);
  std::fill(beta.begin(), beta.end(), NAN);
  int size = p*q;
  NumericVector incr_beta = rnorm(size, 0, 1.);
  incr_beta = abs(incr_beta);
  NumericVector spike = rbinom(size, 1, theta);
  incr_beta = incr_beta*spike;

  if (ref == 1)
    incr_beta[0] = 0.;
  else
    incr_beta[0] = rnorm(1, 0., 1.)[0];
  NumericVector beta_vec = cumsum(incr_beta);

  std::vector<coord> candid;
  candid.push_back(coord(0,0));



  Rcout<<coord(2,3)<<std::endl;
  return beta;
}



