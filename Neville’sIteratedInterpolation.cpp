/**
 * @file   Neville’sIteratedInterpolation.cpp
 * @author Liao Nizheng
 * 
 * 
 * @brief  A C++ solver for Neville’s Iterated Interpolation Example 2 in book P118
 * 
 * 
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>


int main(int argc, char* argv[])
{

  /// INPUT how many points we have 
  int n = 5;  
  /// INPUT n distinct points we have already know the function values
  double x[6];
  x[0] = 1.0; x[1] = 1.3; x[2] = 1.6; x[3] = 1.9; x[4] = 2.2; 
  /// INPUT point x that we want to know the function value
  x[5] = 1.5;

  /// INPUT each values of function on each distinct points
  double f[5];
  f[0] = 0.7651977; f[1] = 0.6200860; f[2] = 0.4554022; f[3] = 0.2818186; f[4] = 0.1103623;

  /// Set Q_{0,j}=f(j)
  double Q[5][5];
  for(int i = 0; i<=4; i++){
      Q[i][0] = f[i];
  }

  for(int i = 0; i<=n; i++){
      for(int j = 1; j<=i; j++){
          Q[i][j] = ((x[5] - x[i-j]) * Q[i][j-1] - (x[5] - x[i]) * Q[i-1][j-1])/(x[i] - x[i-j]);
      }
  }
   
   /// OUTPUT Q(x) = Q[i][j], for which accuracy
   std::cout << Q[4][4] << std::endl;
  

  return 0;
}

/**
 * end of file
 * 
 */

