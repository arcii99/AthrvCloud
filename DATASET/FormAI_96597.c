//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the Euclidean distance between two points
double euclideanDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to check if a point is inside a triangle or not
int isInsideTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y) {
    // Calculate the area of the three triangles formed by the point and the vertices of the triangle
    double area1 = 0.5 * abs((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2)));
    double area2 = 0.5 * abs((x * (y2 - y3)) + (x2 * (y3 - y)) + (x3 * (y - y2)));
    double area3 = 0.5 * abs((x1 * (y - y3)) + (x * (y3 - y1)) + (x3 * (y1 - y)));

    // If the sum of the areas of the three triangles is equal to the area of the original triangle, the point is inside the triangle
    return area1 == area2 + area3;
}

int main() {
    int x1, y1, x2, y2, x3, y3, x, y;

    // Get the coordinates of the three vertices of the triangle
    printf("Enter the coordinates of vertex 1: ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the coordinates of vertex 2: ");
    scanf("%d %d", &x2, &y2);

    printf("Enter the coordinates of vertex 3: ");
    scanf("%d %d", &x3, &y3);

    // Get the coordinates of the point to be checked
    printf("Enter the coordinates of the point to be checked: ");
    scanf("%d %d", &x, &y);

    // Calculate the Euclidean distances between the three pairs of vertices
    double a = euclideanDistance(x1, y1, x2, y2);
    double b = euclideanDistance(x2, y2, x3, y3);
    double c = euclideanDistance(x3, y3, x1, y1);

    // Calculate the perimeter and the semiperimeter of the triangle
    double perimeter = a + b + c;
    double semiperimeter = perimeter / 2.0;

    // Calculate the area of the triangle using Heron's formula
    double area = sqrt(semiperimeter * (semiperimeter - a) * (semiperimeter - b) * (semiperimeter - c));

    // Check if the point is inside the triangle or not
    if (isInsideTriangle(x1, y1, x2, y2, x3, y3, x, y)) {
        printf("The point (%d,%d) is inside the triangle.\n", x, y);
    } else {
        printf("The point (%d,%d) is outside the triangle.\n", x, y);
    }

    // Print the perimeter and area of the triangle
    printf("Perimeter of the triangle: %.2f\n", perimeter);
    printf("Area of the triangle: %.2f\n", area);

    return 0;
}