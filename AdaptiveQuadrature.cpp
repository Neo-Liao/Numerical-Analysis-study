/**
 * @file   AdaptiveQuadrature.cpp
 * @author Liao Nizheng
 * 
 * 
 * @brief  A C++ solver for Adaptive Quadrature Example 2 in book P215
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

  
  /// INPUT endpoints a, b; integer n; limit N to number of levels; tolerance; 
  ///OUTPUT approximation APP or message that N is exceeded.
  double a = 0;
  double b = PI;
  int n = 6;
  int N = 10e2;
  double TOL[N]; TOL[0] = 10e-6;
  
  double APP = 0;
  int i = 1;
  TOL[i] = 10 * TOL[0];
  double newa[N];
  newa[i] = a;
  double h[N];
  h[i] = (b-a)/2;
  double FA[N];
  double FC[N];
  double FB[N];
  FA[i] = IntegrationFunction(a);
  FC[i] = IntegrationFunction(a + h[i]);
  FB[i] = IntegrationFunction(b);
  double S[N];
  S[i] = h[i] * (FA[i] + 4 * FC[i] +FB[i])/3;
  double L[N];
  L[i] = 1;
  
  while(i>0){
      double FD = IntegrationFunction(newa[i] + h[i]/2);
      double FE = IntegrationFunction(newa[i] + 3 * h[i]/2);
      double S1 = h[i] * (FA[i] + 4 * FD + FC[i])/6;
      double S2 = h[i] * (FC[i] + 4 * FE + FB[i])/6;
      double v1 = newa[i];
      double v2 = FA[i];
      double v3 = FC[i];
      double v4 = FB[i];
      double v5 = h[i];
      double v6 = TOL[i];
      double v7 = S[i];
      double v8 = L[i];

      i = i - 1;

      if( fabs(S1 + S2 - v7) < v6){
          APP = APP + (S1 + S2);
      } 
      else{
          if(v8 >= N){
              std::cout<<"LEVEL EXCEEDED"<<std::endl;
          }
          else{
              i = i + 1;
              newa[i] = v1 + v5;
              FA[i] = v3;
              FC[i] = FE;
              FB[i] = v4;
              h[i] = v5/2;
              TOL[i] = v6/2;
              S[i] = S2;
              L[i] = v8 + 1;

              i = i + 1;
              newa[i] = v1;
              FA[i] = v2;
              FC[i] = FD;
              FB[i] = v3;
              h[i] = h[i-1];
              TOL[i] = TOL[i-1];
              S[i] = S1;
              L[i] = L[i-1];
          }
      }
  }
  std::cout<<APP<<std::endl;







  
   
  return 0;
}

/**
 * end of file
 * 
 */

