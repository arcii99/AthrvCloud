//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: grateful
#include <stdio.h>

// Define the structure of a point
typedef struct {
    double x;
    double y;
} Point;

// Calculate the area of a triangle using the Shoelace Formula
double shoelaceFormula(Point vertices[]) {
    double area = 0;
    int nVertices = sizeof(vertices) / sizeof(vertices[0]);

    for (int i = 0; i < nVertices; i++) {
        int j = (i + 1) % nVertices;
        area += vertices[i].x * vertices[j].y;
        area -= vertices[j].x * vertices[i].y;
    }

    return area / 2;
}

int main() {
    // Define the vertices of a triangle
    Point vertices[] = { {0, 0}, {3, 0}, {0, 4} };

    // Calculate the area of the triangle using the Shoelace Formula
    double area = shoelaceFormula(vertices);

    // Print the area of the triangle
    printf("The area of the triangle is: %.2f\n", area);

    return 0;
}