//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// This program calculates the area of a triangle

int main() {
    float a, b, c;
    float s, area;
    
    printf("Enter the length of side A: ");
    scanf("%f", &a);
    
    printf("Enter the length of side B: ");
    scanf("%f", &b);
    
    printf("Enter the length of side C: ");
    scanf("%f", &c);
    
    // Check if the sides form a triangle
    if(a + b > c && a + c > b && b + c > a) {
        // Calculate the perimeter of the triangle
        float perimeter = a + b + c;
        
        // Calculate the semi-perimeter
        s = perimeter / 2;
        
        // Calculate the area of the triangle using Heron's formula
        area = sqrt(s * (s - a) * (s - b) * (s - c));
        
        printf("The area of the triangle is: %f\n", area);
    } else {
        printf("The given sides do not form a triangle. Please try again.\n");
    }
    
    return 0;
}