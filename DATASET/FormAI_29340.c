//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: modular
#include <stdio.h>
#include <math.h>

/* Function to calculate the distance between two points */
double distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx*dx + dy*dy);
}

/* Function to calculate the slope of a line given two points */
double slope(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return dy / dx;
}

/* Function to calculate the area of a triangle given three points */
double area(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = distance(x1, y1, x2, y2);
    double b = distance(x2, y2, x3, y3);
    double c = distance(x3, y3, x1, y1);
    double s = (a + b + c) / 2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main() {
    double x1, y1, x2, y2, x3, y3;
    printf("Enter the x and y coordinates of three points (separated by spaces): ");
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    double d = distance(x1, y1, x2, y2);
    printf("The distance between (%.2lf,%.2lf) and (%.2lf,%.2lf) is %.2lf\n", x1, y1, x2, y2, d);
    double m = slope(x1, y1, x2, y2);
    printf("The slope of the line through (%.2lf,%.2lf) and (%.2lf,%.2lf) is %.2lf\n", x1, y1, x2, y2, m);
    double a = area(x1, y1, x2, y2, x3, y3);
    printf("The area of the triangle with vertices (%.2lf,%.2lf), (%.2lf,%.2lf), and (%.2lf,%.2lf) is %.2lf\n", x1, y1, x2, y2, x3, y3, a);
    return 0;
}