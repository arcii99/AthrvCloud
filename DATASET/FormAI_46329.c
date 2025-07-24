//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: cheerful
/* Let's have some fun with geometric algorithms! */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Define a structure for a point in 2D space */
struct Point {
    double x, y;
};

/* Define a function to calculate the slope between two points */
double Slope(struct Point p1, struct Point p2) {
    return (p2.y - p1.y) / (p2.x - p1.x);
}

/* Define a function to calculate the distance between two points */
double Distance(struct Point p1, struct Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

/* Define a function to calculate the area of a triangle given its three vertices */
double TriangleArea(struct Point p1, struct Point p2, struct Point p3) {
    double a = Distance(p1, p2);
    double b = Distance(p2, p3);
    double c = Distance(p3, p1);
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    /* Let's create some points and calculate the slope between them */
    struct Point p1 = {0, 0};
    struct Point p2 = {1, 1};
    double m = Slope(p1, p2);

    /* Print the slope between the two points */
    printf("The slope between (%f, %f) and (%f, %f) is %f\n", p1.x, p1.y, p2.x, p2.y, m);

    /* Let's create some more points and calculate the distance between them */
    struct Point p3 = {2, 2};
    struct Point p4 = {3, 5};
    double d = Distance(p3, p4);

    /* Print the distance between the two points */
    printf("The distance between (%f, %f) and (%f, %f) is %f\n", p3.x, p3.y, p4.x, p4.y, d);

    /* Let's create still more points and calculate the area of a triangle using them */
    struct Point p5 = {5, 5};
    struct Point p6 = {7, -2};
    struct Point p7 = {-3, 4};
    double area = TriangleArea(p5, p6, p7);

    /* Print the area of the triangle */
    printf("The area of the triangle with vertices (%f, %f), (%f, %f), and (%f, %f) is %f\n", p5.x, p5.y, p6.x, p6.y, p7.x, p7.y, area);

    /* We're done! */
    return 0;
}