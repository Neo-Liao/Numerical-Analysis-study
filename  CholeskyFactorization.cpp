/**
 * @file   CholeskyFactorization.cpp
 * @author Liao Nizheng
 * 
 * 
 * @brief  A C++ solver for Cholesky Factorization
 * 
 * 
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

/// INPUT numbers of unknowns and equations n; 
/// augmented matrix A = aij, 1<=i,j<=n.

const int n = 3;

int main(int argc, char* argv[])
{ 
  int i, j, k;
  /// INPUT the entries of the original marix A

  double a[n][n] = { {1, 0, 0},
                     {0, 2, 0},
                     {0, 0, 1} };
  double l[n][n] = {}; 

  l[0][0] = sqrt(a[0][0]);

  for(j = 1; j < n; j++){
      l[j][0] = a[j][0] / l[0][0];
  } 
  
  for(i = 1; i < n-1; i++){
      double f = 0;
      for(k = 0; k < i; k++){
         f += l[i][k] * l[i][k];
      }

      l[i][i] = sqrt(a[i][i] - f);
      f = 0;

      for(j=i+1;j<n;j++){
          double g = 0;
          for(k=0;k<i;k++){
              g += l[j][k] * l[i][k];
          }
          l[j][i] = (a[j][i] - g) / l[i][i];
          g = 0;
      }
  }

  double h = 0;
for(k = 0; k < n; k++){
         h += l[n-1][k] * l[n-1][k];
      }
l[n-1][n-1] = sqrt(a[n-1][n-1] - h);

///OUTPUT the lower triangular L if you want
// for(i = 0; i < n; i++){
//     for(j = 0; j < n; j++){
//         std::cout<<l[i][j]<<std::endl;
//     }
// }

/// INPUT Ax=b , the colume b;

double b[n] = {1,1,2};

double y[n] = {};
y[0] = b[0] / l[0][0];
for(i=1;i<n;i++){
    double p = 0;
    for(j=0;j<i;j++){
        p += l[i][j] * y[j]; 
    }
    y[i] = (b[i] - p) / l[i][i];
    p = 0;
}


double x[n] = {};
 x[n-1] = y[n-1] / l[n-1][n-1];

for(i=n-2;i>=0;i--){
    double q = 0;
    for(j=i+1;j<n;j++){
        q += l[j][i] * x[j];
    }
    x[i] = (y[i] - q) / l[i][i];
    q = 0;
}

for(i=0;i<n;i++){
    std::cout<<x[i]<<std::endl;
}
 

  return 0;
}

/**
 * end of file
 * 
 */

