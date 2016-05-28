#include <Rcpp.h>
using namespace Rcpp;

//Class coord: coordinate class
class coord{
public:
  explicit coord(int i, int j, int p, int q){
    i_ = i;
    j_ = j;
    maxi = p;
    maxj = q;
  }
  int i(){
    return i_;
  }
  int j(){
    return j_;
  }
  const bool is_valid(){
    return (i_ > -1) && (i_ < maxi) && (j_ > -1) && (j_ < maxj);
  }
  friend std::ostream & operator<<(std::ostream & os, const coord & co){
    os<<co.i_<<","<<co.j_;
    return os;
  }
private:
  int i_;
  int j_;
  int maxi;
  int maxj;
};

//Function to sample one object from a std::list, with equally probability, remove that object from the list,
//  and return that object.
template<typename T>
T sample_vec(std::vector<T> & vec){
  int loc = int(runif(1)[0]*vec.size());
  T obj = vec[loc];
  vec.erase(vec.begin() + loc);
  return obj;
}

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
  //increment of beta
  NumericVector incr_beta = rnorm(size, 0, 1.);
  incr_beta = abs(incr_beta);
  //shrink the increment, i.e. fuse
  NumericVector spike = rbinom(size, 1, theta);
  incr_beta = incr_beta*spike;

  if (ref == 1)
    incr_beta[0] = 0.;
  else
    incr_beta[0] = rnorm(1, 0., 1.)[0];
  //put the values of beta's in an ordered vector
  NumericVector beta_vec = cumsum(incr_beta);
  //Rcout<<beta_vec<<std::endl;

  //maintain a list of candidate coordinates
  std::vector<coord> candid;
  candid.push_back(coord(0, 0, p, q));

  //every time, randomly choose one from the candidates, and fill that coordinate with the next valuse in beta_vec
  for (int itt = 0; itt < size; itt++){
    coord chosen = sample_vec(candid);
    beta(chosen.i(), chosen.j()) = beta_vec[itt];
    //update the candidate list: every time of filling two potential candidates are generated. They are tested to be valid candidate
    //before being pushed into the candidate list
    coord p_cand(chosen.i() +1, chosen.j(), p, q);
    if (p_cand.is_valid()){
      coord neighbor(p_cand.i(), p_cand.j() -1, p, q);
      if (!neighbor.is_valid()) candid.push_back(p_cand);
      else if (beta(neighbor.i(), neighbor.j())>=0.) candid.push_back(p_cand);
    }
    p_cand = coord(chosen.i(), chosen.j() + 1, p, q);
    if (p_cand.is_valid()){
      coord neighbor(p_cand.i() - 1, p_cand.j(), p, q);
      if (!neighbor.is_valid()) candid.push_back(p_cand);
      else if (beta(neighbor.i(), neighbor.j())>= 0.) candid.push_back(p_cand);
    }
    /*
    Rcout<<beta<<std::endl;
    for (int k = 0; k<candid.size(); k++) Rcout<<candid[k]<<";";
    Rcout<<std::endl;
    */
  }
  return beta;
}



