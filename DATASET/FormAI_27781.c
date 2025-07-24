//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a structure to hold a 2D point
typedef struct {
    double x;
    double y;
} Point;

// Define a function to calculate the area of a polygon using the shoelace formula
double polygonArea(Point* vertices, int numVertices) {
    double area = 0.0;
    int j = numVertices - 1;
    
    // Iterate over each vertex
    for (int i = 0; i < numVertices; i++) {
        // Calculate the cross product of the two adjacent vertices and sum it to the total area
        area += (vertices[j].x + vertices[i].x) * (vertices[j].y - vertices[i].y);
        j = i; // Update the previous vertex index
    }
    
    // Return the absolute area divided by 2
    return fabs(area / 2.0);
}

int main() {
    // Define a simple square polygon with 4 vertices
    Point vertices[4] = {
        {0.0, 0.0},
        {0.0, 1.0},
        {1.0, 1.0},
        {1.0, 0.0}
    };
    
    // Calculate the area of the polygon
    double area = polygonArea(vertices, 4);
    
    // Print the result to the console
    printf("The area of the square polygon is: %f", area);
    
    return 0;
}