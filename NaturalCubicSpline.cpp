/**
 * @file   NaturalCubicSpline.cpp
 * @author Liao Nizheng
 * 
 * 
 * @brief  A C++ solver for Natural Cubic Spline Example 2 in book P148
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
  int n = 3;  
  /// INPUT n+1 distinct points we have already know the function values
  double x[4];
  x[0] = 0; x[1] = 1; x[2] = 2; x[3] = 3;  

  /// INPUT each values of function on each distinct points
  double f[4];
  f[0] = 1; f[1] = exp(1); f[2] = exp(2); f[3] = exp(3); 

  /// coefficient a[i] = f(x_I)
  double a[n+1];
  for(int i = 0; i<=n; i++){
      a[i] = f[i];
  }

  /// Step size
  double h[n+1];
  for(int i = 0; i <= n-1; i++){
      h[i] = x[i+1] - x[i];
  }

  /// the entry of vector b is 3/h[i]*(a[i+1] - a[i])-3/h[i-1]*(a[i] - a[i-1])
  double alpha[n+1];
  for(int i = 1; i <= n-1; i++){
      alpha[i]=3/h[i]*(a[i+1] - a[i])-3/h[i-1]*(a[i] - a[i-1]);
  }

  /// solve a tridiagonal linear system using a method described in Algorithm 6.7.
  double l[n+1]; l[0] = 1;
  double u[n+1]; u[0] = 0;
  double z[n+1]; z[0] = 0;

  for(int i = 1; i <= n-1; i++){
      l[i] = 2 * (x[i+1] - x[i-1]) - h[i-1] * u[i-1];
      u[i] = h[i]/l[i];
      z[i] = (alpha[i] - h[i-1] * z[i-1])/l[i];
  }

  /// coefficient b, c, d
  double b[n+1];
  double c[n+1];
  double d[n+1]; 
  
  l[n] = 1;
  z[n] = 0;
  c[n] = 0;

  for(int j = n-1; j >= 0; j--){
      c[j] = z[j] - u[j] * c[j+1];
      b[j] = (a[j+1] - a[j])/h[j] - h[j] * (c[j+1] + 2*c[j])/3;
      d[j] = (c[j+1] - c[j])/(3 * h[j]);
  }
  /// OUTPUT a, b, c, d

  for(int i = 0; i <= n-1; i++ ){
      std::cout <<"Coefficients a,b,c,d on interval [" <<x[i]<<","<<x[i+1]<<"] are "<< a[i]<<", "<< b[i]<<", "<<c[i]<<", "<<d[i]<< std::endl;
  }
   
  return 0;
}

/**
 * end of file
 * 
 */

