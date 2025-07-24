//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: innovative
#include <stdio.h>
#include <math.h>

// Function to calculate the area of a triangle
float area_of_triangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    float a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); // Length of side a
    float b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2)); // Length of side b
    float c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2)); // Length of side c
    
    // Semi-perimeter
    float s = (a + b + c) / 2;
    
    // Area
    float area = sqrt(s * (s - a) * (s - b) * (s - c));
    
    return area;
}

int main() {
    // Input coordinates of vertices of triangle
    float x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of vertex 1: ");
    scanf("%f %f", &x1, &y1);
    printf("Enter the coordinates of vertex 2: ");
    scanf("%f %f", &x2, &y2);
    printf("Enter the coordinates of vertex 3: ");
    scanf("%f %f", &x3, &y3);
    
    // Calculate area of triangle
    float area = area_of_triangle(x1, y1, x2, y2, x3, y3);
    
    // Output the area
    printf("The area of the triangle is: %f\n", area);
    
    return 0;
}