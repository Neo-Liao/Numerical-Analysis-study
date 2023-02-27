/// 2PointsLine.cpp
#include <iostream>
#include <math.h>
 
int main()
{
    float slope, intercept;
    float x1, y1, x2, y2;
    float dx, dy;
 
    std::cout << "Program to find the equation of a line given two end points\n";
 
    std::cout << "Enter X1: ";
    std::cin >> x1;
 
    std::cout << "Enter Y1: ";
    std::cin >> y1;
 
    std::cout << "Enter X2: ";
    std::cin >> x2;
 
    std::cout << "Enter Y2: ";
    std::cin >> y2;
 
    dx = x2 - x1;
    dy = y2 - y1;
 
    slope = dy / dx;
    // y = mx + c
    // intercept c = y - mx
    intercept = y1 - slope * x1; // which is same as y2 - slope * x2
 
    std::cout << "Equation of the line with end points (" << x1 << ", " << y1 << ") and (" << x2 << ", " << y2 << ") : Y = ";
    std::cout << slope << "X " << ((intercept < 0) ? ' ' : '+') << intercept << "\n";
}