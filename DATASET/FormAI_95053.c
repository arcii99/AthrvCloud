//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: rigorous
#include <stdio.h>
#include <math.h>

// Function to calculate the Euclidean distance between two points
double euclidean_distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

// Function to calculate the area of a triangle given its three side lengths
double heron_formula(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Function to check if a point is inside a triangle
int is_inside_triangle(double x1, double y1, double x2, double y2, double x3, double y3, double px, double py) {
    // Calculate the area of the triangle
    double triangle_area = heron_formula(euclidean_distance(x1, y1, x2, y2), euclidean_distance(x2, y2, x3, y3), euclidean_distance(x3, y3, x1, y1));
    
    // Calculate the area of three smaller triangles formed by the point and each side of the triangle
    double area1 = heron_formula(euclidean_distance(px, py, x1, y1), euclidean_distance(px, py, x2, y2), euclidean_distance(x1, y1, x2, y2));
    double area2 = heron_formula(euclidean_distance(px, py, x2, y2), euclidean_distance(px, py, x3, y3), euclidean_distance(x2, y2, x3, y3));
    double area3 = heron_formula(euclidean_distance(px, py, x3, y3), euclidean_distance(px, py, x1, y1), euclidean_distance(x3, y3, x1, y1));

    // If the sum of the three smaller areas is equal to the area of the triangle, the point is inside the triangle
    return triangle_area == (area1 + area2 + area3);
}

int main() {
    // Define the coordinates of the triangle
    double x1 = 0, y1 = 0;
    double x2 = 3, y2 = 0;
    double x3 = 0, y3 = 4;

    // Define the point to be checked
    double px = 1, py = 1;

    // Check if the point is inside the triangle
    int inside_triangle = is_inside_triangle(x1, y1, x2, y2, x3, y3, px, py);

    // Output the result
    if (inside_triangle) {
        printf("The point (%lf, %lf) is inside the triangle.\n", px, py);
    } else {
        printf("The point (%lf, %lf) is outside the triangle.\n", px, py);
    }

    return 0;
}