//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 
This program uses a geometric algorithm to calculate the area of a polygon given the coordinates of its vertices. 
This algorithm is based on the Shoelace Formula and is commonly used in computer graphics and image processing.
*/

typedef struct Point {
    double x;
    double y;
} Point;

double calculatePolygonArea(Point *points, int numVertices) {
    // Initialize variables for the calculation
    double area = 0.0;
    int j = numVertices - 1;

    // Apply the Shoelace Formula
    for (int i = 0; i < numVertices; i++) {
        area += (points[j].x + points[i].x) * (points[j].y - points[i].y);
        j = i;
    }

    // Return the absolute value of the calculated area
    return fabs(area / 2.0);
}

int main() {
    // Define the vertices of the polygon
    Point points[] = {{0, 0}, {3, 0}, {3, 2}, {1, 1}, {0, 2}};

    // Calculate the area of the polygon
    double area = calculatePolygonArea(points, sizeof(points) / sizeof(points[0]));

    // Print the result
    printf("The area of the polygon is %.2f square units.\n", area);

    return 0;
}