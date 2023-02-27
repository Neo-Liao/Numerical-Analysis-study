///DoubleIntegralFunction.cpp

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

/// Function P
double IntegrationFunctionP(double px , double py){
      return 1;
  }
/// Triangle T5
double cFunction5(double px){
      return px - 0.4;
  }
double dFunction5(double px){
      return -px + 0.6;
  }
double DoubleIntegration5P(double a , double b , int n , int m){
  
  double h = (b - a)/n;
  double J1 = 0; /// end terms
  double J2 = 0; /// even terms
  double J3 = 0; /// odd terms

  for(int i = 0; i <= n; i++){
      double x = a + i * h;
      double HX = ( dFunction5(x) - cFunction5(x) )/m;
      double K1 = IntegrationFunctionP(x , cFunction5(x)) + IntegrationFunctionP(x , dFunction5(x)); /// end terms
      double K2 = 0; /// even terms
      double K3 = 0; /// odd terms
      for(int j = 1; j <= m-1; j++){
          double y = cFunction5(x) + j * HX;
          double Q = IntegrationFunctionP(x,y);
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
  return J;
}
  
int main() {
   
   double  apI = DoubleIntegration5P(0.4 , 0.5 , 10 , 10);

   std::cout<<apI<<std::endl; 

   return 0;
}