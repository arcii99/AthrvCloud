//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float x1, y1, x2, y2, x3, y3, a, b, c, s, area;
    
    // Take user input for coordinates of the 3 vertices of the triangle
    printf("Enter the coordinates (x, y) of the 1st vertex: ");
    scanf("%f %f", &x1, &y1);
    printf("Enter the coordinates (x, y) of the 2nd vertex: ");
    scanf("%f %f", &x2, &y2);
    printf("Enter the coordinates (x, y) of the 3rd vertex: ");
    scanf("%f %f", &x3, &y3);
    
    // Calculate the sides of the triangle
    a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    
    // Calculate the semi-perimeter of the triangle
    s = (a + b + c) / 2;
    
    // Calculate the area of the triangle using Heron's formula
    area = sqrt(s * (s - a) * (s - b) * (s - c));
    
    // Print the area of the triangle
    printf("The area of the triangle is: %f\n", area);
    
    return 0;
}