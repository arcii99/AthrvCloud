//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: active
#include <stdio.h>

// function to calculate the area of a triangle given its sides
double triangle_area(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// function to calculate the distance between two points
double distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    double x1, y1, x2, y2, x3, y3;

    // read three points from user input
    printf("Enter first point coordinates: ");
    scanf("%lf %lf", &x1, &y1);
    printf("Enter second point coordinates: ");
    scanf("%lf %lf", &x2, &y2);
    printf("Enter third point coordinates: ");
    scanf("%lf %lf", &x3, &y3);

    // calculate the sides of the triangle
    double a = distance(x1, y1, x2, y2);
    double b = distance(x2, y2, x3, y3);
    double c = distance(x3, y3, x1, y1);

    // calculate the area of the triangle
    double area = triangle_area(a, b, c);

    // output the area of the triangle
    printf("The area of the triangle is %.2lf\n", area);

    return 0;
}