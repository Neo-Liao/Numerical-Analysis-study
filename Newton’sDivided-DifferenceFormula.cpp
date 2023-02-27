/**
 * @file   Newton’sDivided-DifferenceFormula.cpp
 * @author Liao Nizheng
 * 
 * 
 * @brief  A C++ solver Newton’s Divided-Difference Formula Example 1 in book P124
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
  int n = 4;  
  /// INPUT n+1 distinct points we have already know the function values
  double x[5];
  x[0] = 1.0; x[1] = 1.3; x[2] = 1.6; x[3] = 1.9; x[4] = 2.2; 

  /// INPUT each values of function on each distinct points
  double f[5];
  f[0] = 0.7651977; f[1] = 0.6200860; f[2] = 0.4554022; f[3] = 0.2818186; f[4] = 0.1103623;

  /// Set Q_{0,j}=f(j)
  double F[5][5];
  for(int i = 0; i<=4; i++){
      F[i][0] = f[i];
  }

  for(int i = 0; i<=n; i++){
      for(int j = 1; j<=i; j++){
          F[i][j] = (F[i][j-1] - F[i-1][j-1])/(x[i] - x[i-j]); ///F[i][j]=f[x_{i-j},...,x_{i}]
      }
  }
   
   /// OUTPUT F[i][i]=f[x_{0},...,x_{i}]
   for(int i = 0; i<=n; i++){
       std::cout << F[i][i] << std::endl;
   }
   
  

  return 0;
}

/**
 * end of file
 * 
 */

