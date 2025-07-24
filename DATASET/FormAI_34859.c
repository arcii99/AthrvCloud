//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Dennis Ritchie
#include <stdio.h>

/* This program calculates the area of a triangle using Heron's formula */

int main() {
    float a, b, c;
    float s, area;
    
    printf("Enter the lengths of the sides of the triangle: ");
    scanf("%f %f %f", &a, &b, &c);
    
    s = (a + b + c) / 2; // Calculate the semi-perimeter
    area = sqrt(s * (s - a) * (s - b) * (s - c)); // Calculate the area using Heron's formula
    
    printf("The area of the triangle is %f \n", area);
    
    return 0; // Exit program with success code
}