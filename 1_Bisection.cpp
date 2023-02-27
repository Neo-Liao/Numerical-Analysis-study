/**
 * @file   1_Bisection.cpp
 * @author Liao Nizheng
 * 
 * 
 * @brief  A C++ solver for Bisection Example 1 in book P50
 * 
 * 
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

/// The definition of the funtion f
  double f(double px){
      return px * px * px + 4 * px * px - 10; 
  } 

/// minimize function
  double min(double px, double py){
      if( abs(px) < abs(py) ){
          return abs(px);
      }
      else{
          return abs(py);
      }
  }

int main(int argc, char* argv[])
{

  /// INPUT endpoints a, b
  double a = 1; 
  double b = 2;   

  /// INPUT The tolerance of the Relative error 
  double TOL = 1.0e-4; 

  /// INPUT maximum number of iterations
  int N0 = 10e4;
  
  int i = 1;
  double FA = f(a);

  while(i <= N0){
      double p = a + (b-a)/2;
      double FP = f(p);
      if(FP == 0 || (b-a)/min(a,b) < TOL){
          std::cout << "The root is " << p << std::endl;
          break;
      } 
      i = i + 1;
      if(FA * FP >0){
          a = p;
          FA = FP;
      }
      else{
          b = p;
      }

  }
  
  
  return 0;
}

/**
 * end of file
 * 
 */

