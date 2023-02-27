/**
 * @file   Simpson'sDoubleIntegral.cpp
 * @author Liao Nizheng
 * 
 * 
 * @brief  A C++ solver for Simpsom's Double Integral illustration in book P245
 * 
 * 
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

/// PI 3.14159265358979323846
const double PI = 4. * atan(1.);

/// The function we want to integrat
double IntegrationFunction(double px , double py)
{
  return  exp(py / px);
}

/// The integration area fucntion y = c(x) and y = d(x)
double dFunction(double px){
    return px * px;
}
double cFunction(double px){
    return px * px * px;
}


int main(int argc, char* argv[])
{

  
  /// INPUT endpoints a, b; integer n; positive integer n, m (the number of the subinterval) 
  ///OUTPUT approximation J to the double integral I = \int_{a}^{b} \int_{c(x)}^{d(x)} f(x,y) dy dx
  double a = 0.1;
  double b = 0.5;
  int n = 10;
  int m = 10;
  
  double h = (b - a)/n;
  double J1 = 0; /// end terms
  double J2 = 0; /// even terms
  double J3 = 0; /// odd terms

  for(int i = 0; i <= n; i++){
      double x = a + i * h;
      double HX = ( dFunction(x) - cFunction(x) )/m;
      double K1 = IntegrationFunction(x , cFunction(x)) + IntegrationFunction(x , dFunction(x)); /// end terms
      double K2 = 0; /// even terms
      double K3 = 0; /// odd terms
      for(int j = 1; j <= m-1; j++){
          double y = cFunction(x) + j * HX;
          double Q = IntegrationFunction(x,y);
          if(j % 2 == 0){
              K2 = K2 + Q;
          }
          else{
              K3 = K3 + Q;
          }
      }
    double L = (K1 + 2 * K2 + 4 * K3) * HX / 3;
    if( (i == 0) || (i == n) ){
        J1 = J1 + L;
    }
    else if(i % 2 == 0){
        J2 = J2 + L;
    }
    else{
        J3 = J3 + L;
    }
  }
  double J = h * (J1 + 2 * J2 + 4 * J3)/3;

  std::cout<<J<<std::endl;
  
   
  return 0;
}

/**
 * end of file
 * 
 */

