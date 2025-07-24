//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: inquisitive
#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, s, area;
    
    printf("Enter the lengths of all three sides of the triangle: ");
    scanf("%lf%lf%lf", &a, &b, &c);
    
    s = (a + b + c) / 2.0;  // Semi-perimeter of the triangle
    
    // Using Heron's formula to calculate the area of the triangle
    area = sqrt(s * (s - a) * (s - b) * (s - c));
    
    printf("The area of the triangle is: %lf", area);
    
    return 0;
}