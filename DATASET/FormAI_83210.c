//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: lively
#include <stdio.h>
#include <math.h>

// Function to calculate the distance between two points (x1, y1) and (x2, y2)
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to calculate the area of a triangle given three points (x1, y1), (x2, y2), and (x3, y3)
double triangle_area(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = distance(x1, y1, x2, y2);
    double b = distance(x2, y2, x3, y3);
    double c = distance(x1, y1, x3, y3);

    double s = (a + b + c) / 2.0;

    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    // Sample test cases
    double x1 = 0, y1 = 0;
    double x2 = 3, y2 = 4;
    double x3 = 5, y3 = 0;

    double area = triangle_area(x1, y1, x2, y2, x3, y3);

    printf("The area of the triangle with vertices (%.2f, %.2f), (%.2f, %.2f), and (%.2f, %.2f) is %.2f\n",
            x1, y1, x2, y2, x3, y3, area);

    return 0;
}