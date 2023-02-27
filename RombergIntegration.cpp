/**
 * @file   RombergIntegration.cpp
 * @author Liao Nizheng
 * 
 * 
 * @brief  A C++ solver for Romberg Integration Example 2 in book P215
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

  
  /// INPUT endpoints a, b; integer n
  double a = 0;
  double b = PI;
  int n = 6;

  /// Function value on endpoints

  /// Step size h_1 
  double h = (b - a);
  
  /// Approximation of the integration
  double R[n][n];
  /// R[1][1]
  R[0][0] = h/2 * (IntegrationFunction(a) + IntegrationFunction(b));
  
  /// OUTPUT R[1][1]
  std::cout<<"R_{1,1}= "<< R[0][0]<<";"<< std::endl;

  /// n-1?
  double sum = 0;
  for(int i = 2; i <= n; i++){
      for(int k = 1; k <= pow(2,i-2); k++){
         sum += IntegrationFunction(a + (k - 0.5) * h);
         R[1][0] = 0.5 * (R[0][0] + h * sum);
      }
      for(int j = 2; j <= i; j++){
          R[1][j-1] = R[1][j-2] + (R[1][j-2] - R[0][j-2])/(pow(4,j-1)-1); ///  std::cout<<"R_{2,j} are "<< R[1][j-1]<<std::endl;
      }
      for(int j = 1; j <= i; j++){
          std::cout<<"R_{2,j} are "<< R[1][j-1]<<std::endl;
      }
          h = h/2;
          for(int j = 1; j <= i; j++){
              R[0][j-1] = R[1][j-1];
          }
          sum = 0; 
    }
  
   
  return 0;
}

/**
 * end of file
 * 
 */

