//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: high level of detail
/* This program calculates the area of a triangle given the coordinates of its vertices using the Shoelace Formula */

#include <stdio.h>

int main() {
    // Define variables
    float x1, y1, x2, y2, x3, y3;
    float area;

    // Ask user for coordinates
    printf("Enter coordinates of the three vertices of the triangle:\n");
    printf("Vertex 1 (x,y): ");
    scanf("%f,%f", &x1, &y1);
    printf("Vertex 2 (x,y): ");
    scanf("%f,%f", &x2, &y2);
    printf("Vertex 3 (x,y): ");
    scanf("%f,%f", &x3, &y3);

    // Calculate area using Shoelace Formula
    area = 0.5 * abs((x1*y2 + x2*y3 + x3*y1) - (y1*x2 + y2*x3 + y3*x1));
    
    // Print results
    printf("The area of the triangle is: %f\n", area);

    return 0;
}