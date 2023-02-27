/**
 * @file   2_Fixed-pointIteration.cpp
 * @author Liao Nizheng
 * 
 * 
 * @brief  A C++ solver for Fixed-point Iteration in book P60
 * 
 * 
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>


/// The funtion g is fixed-point form of the original function f
  double g(double px){
      return 0.5 * pow(10.0 - px * px * px , 0.5); 
  } 
  
int main(int argc, char* argv[])
{
  std::cout << g(1.0) << std::endl;
  /// INPUT initial approximation P0
  double P0 = 1.5;

  /// INPUT The tolerance of the Relative error 
  double TOL = 1.0e-5; 

  /// INPUT maximum number of iterations
  int N0 = 10e4;
  
  int i = 1;
  
  while(i <= N0){
      double p = g(P0);
      if(abs(p - P0) < TOL){
          std::cout << "The fixed-point is " << p << std::endl;
          break;
      } 
      i = i + 1;
      P0 = p; 
  }

  if(i > N0){
   std::cout << "The method failed after " << N0 << " iterations" << std::endl;
  }
  
   
  return 0;

}

/**
 * end of file
 * 
 */

