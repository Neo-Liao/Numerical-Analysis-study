/**
 * @file   CompositeSimpson'sRule.cpp
 * @author Liao Nizheng
 * 
 * 
 * @brief  A C++ solver for Composite Simpsom's Rule Example 2 in book P206
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
double IntegrationFunction(double px)
{
  return sin(px);
}


int main(int argc, char* argv[])
{

  
  /// INPUT endpoints a, b; integer n; even positive integer n (the number of the subinterval) 
  ///OUTPUT approximation XI to the integral I = \int_{a}^{b} f(x) dx
  double a = 0;
  double b = PI;
  int n = 100;
  
  double h = (b - a)/n;

  double XI0 = IntegrationFunction(a) + IntegrationFunction(b);
  double XI1 = 0;
  double XI2 = 0;

  for(int i=1; i <= n+1; i++){
      double X = a + i * h;
      if(i % 2 ==0){
          XI2 = XI2 + IntegrationFunction(X);
      }
      else{
          XI1 = XI1 + IntegrationFunction(X);
      }
  }

  double XI = h * (XI0 + 2 * XI2 + 4 * XI1) / 3;

  std::cout<<XI<<std::endl;
  
   
  return 0;
}

/**
 * end of file
 * 
 */

