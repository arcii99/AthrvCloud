//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: creative
#include <stdio.h>
#include <math.h>

// Function to find the area of a triangle given the length of three sides
double area_of_triangle(double side1, double side2, double side3) {
    // Using Heron's formula to calculate the area of a triangle
    double s = (side1 + side2 + side3) / 2;
    double area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
    return area;
}

// Function to find the centroid of a triangle given the coordinates of its three vertices
void centroid_of_triangle(double x1, double y1, double x2, double y2, double x3, double y3, double *x, double *y) {
    // Using the formula for the centroid of a triangle
    *x = (x1 + x2 + x3) / 3;
    *y = (y1 + y2 + y3) / 3;
}

int main() {
    // Example usage of the functions above
    double side1 = 3;
    double side2 = 4;
    double side3 = 5;
    double area = area_of_triangle(side1, side2, side3);
    printf("Area of triangle with sides %.2lf, %.2lf, and %.2lf is %lf\n", side1, side2, side3, area);
    
    double x1 = 0;
    double y1 = 0;
    double x2 = 3;
    double y2 = 0;
    double x3 = 0;
    double y3 = 3;
    double x, y;
    centroid_of_triangle(x1, y1, x2, y2, x3, y3, &x, &y);
    printf("Centroid of triangle with vertices (%.2lf, %.2lf), (%.2lf, %.2lf), and (%.2lf, %.2lf) is (%.2lf, %.2lf)\n", x1, y1, x2, y2, x3, y3, x, y);
    
    return 0;
}