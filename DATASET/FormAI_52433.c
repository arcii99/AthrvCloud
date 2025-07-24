//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: statistical
/* This program calculates the area of a triangle using the Heron's formula */

#include <stdio.h>
#include <math.h>

int main() {
    // declare variables
    double a, b, c, s, area;
    
    // prompt user to input the sides of the triangle
    printf("Enter the three sides of the triangle:\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    // calculate the semi-perimeter of the triangle
    s = (a + b + c) / 2;
    
    // calculate the area using the Heron's formula
    area = sqrt(s * (s - a) * (s - b) * (s - c));
    
    // print the area of the triangle
    printf("The area of the triangle is: %.2lf\n", area);
    
    return 0;
}