/**
 * @file   GaussianEliminationwithBackwardSubstitution.cpp
 * @author Liao Nizheng
 * 
 * 
 * @brief  A C++ solver for Gaussian Elimination with Backward Substitution in book P368
 * 
 * 
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

/// INPUT numbers of unknowns and equations n; augmented matrix A = aij, 1<=i<=n, 1<=j<=n+1.

const int n = 84;

int main(int argc, char* argv[])
{ 
  int i, j, k;
  /// INPUT the entries of the original marix A

  double a[n][n+1] = {};/// Initialize all entries 0;
  double x[n]; /// n unknowns which will be stored in array x[n]; 

  for(i = 0; i < n; i++){
    a[i][i+1] = 1;
    a[i][i] = 6;
    a[i+1][i] = 8;
} 

  /// INPUt the b column
  a[0][84] = 7;
  a[83][84] = 14;
  for(i = 1; i < n-1; i++){
     a[i][84] = 15;
  }
/// Elinimation process

    for(i=0; i<n; i++) 
    {                   
        for(j=i+1; j<n; j++)
        {
            if(abs(a[i][i]) < abs(a[j][i]))
            {
                for(k=0; k<n+1; k++)
                {
                    /* swapping a[i][k] and a[j][k] */
        a[i][k] = a[i][k] + a[j][k];
                    a[j][k] = a[i][k] - a[j][k];
                    a[i][k] = a[i][k] - a[j][k];
                }
            }
      }
    }
for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            double f = a[j][i] / a[i][i];
            for(k=0; k<n+1; k++)
            {
              a[j][k] = a[j][k] - f * a[i][k];
      }
        }
    }
for(i=n-1;i>=0;i--)          
    {                     
        x[i]=a[i][n];
                    
        for(j=i+1;j<n;j++)
        {
          if(i!=j)
          {
              x[i]=x[i]-a[i][j]*x[j];
    }          
  }
  x[i]=x[i]/a[i][i];  
    }
    
    std::cout<<"\nThe values of unknowns for the above equations are\n";
    for(i=0;i<n;i++)
    {
      std::cout<<x[i]<<"\n";
    }

  return 0;
}

/**
 * end of file
 * 
 */

