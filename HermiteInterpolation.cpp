/**
 * @file   HermiteInterpolation.cpp
 * @author Liao Nizheng
 * 
 * 
 * @brief  A C++ solver for Hermite Interpolation Example 2 in book P138
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
  int n = 2;  
  /// INPUT n+1 distinct points we have already know the function values
  double x[3];
  x[0] = 1.3; x[1] = 1.6; x[2] = 1.9;  
  /// INPUT point x that we want to know the function value
  double px = 1.5;

  /// INPUT each values of function on each distinct points
  double f[3];
  f[0] = 0.6200860; f[1] = 0.4554022; f[2] = 0.2818186; 

  /// INPUT each values of the first derivative of function on each distinct points
  double f1[5];
  f1[0] = -0.5220232; f1[1] = -0.5698959; f1[2] = -0.5811571; 

  /// Where H(x)=Q[0][0]+Q[1][1](x-x_0)+Q[2][2](x-x_0)^2+Q[3][3](x-x_0)^2(x-x_1)+Q[4][4](x-x_0)^2(x-x_1)^2+...+Q[2n+1][2n+1](x-x_0)^2(x-x_1)^2...(x-x_{n-1})^2(x-x_n)
  double Q[2*n+2][2*n+2];
  /// let z[2i]=z[2i+1]=x[i]
  double z[2*n+2];

  for(int i = 0; i<=n; i++){
      z[2*i] = x[i];
      z[2*i+1] = x[i];
      Q[2*i][0] = f[i];
      Q[2*i+1][0] = f[i];
      Q[2*i+1][1] = f1[i];
      if(i!=0){
          Q[2*i][1] = (Q[2*i][0] - Q[2*i-1][0])/(z[2*i] - z[2*i-1]);
      }
  }

  for(int i = 2; i<=2*n+1; i++){
      for(int j = 2; j<=i; j++){
          Q[i][j] = (Q[i][j-1] - Q[i-1][j-1])/(z[i]-z[i-j]);
      }
  }
  

   std::cout << Q[0][0] << std::endl;
  

  return 0;
}

/**
 * end of file
 * 
 */

