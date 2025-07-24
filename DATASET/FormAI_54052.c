//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: light-weight
#include <stdio.h>
#include <math.h>

/* Define a structure to represent a point in 2D space */
typedef struct {
    double x; // x-coordinate
    double y; // y-coordinate
} Point;

/* Define a function to calculate the Euclidean distance between two points */
double euclidean_distance(Point p1, Point p2) {
    double dx = p1.x - p2.x; // calculate the x-distance
    double dy = p1.y - p2.y; // calculate the y-distance
    return sqrt(dx*dx + dy*dy); // calculate the Euclidean distance
}

/* Define a function to calculate the area of a triangle given its three vertices */
double triangle_area(Point p1, Point p2, Point p3) {
    double a = euclidean_distance(p1, p2); // calculate the length of side a
    double b = euclidean_distance(p2, p3); // calculate the length of side b
    double c = euclidean_distance(p3, p1); // calculate the length of side c
    double s = (a + b + c) / 2.0; // calculate the semiperimeter
    return sqrt(s*(s-a)*(s-b)*(s-c)); // calculate the area of the triangle using Heron's formula
}

int main() {
    /* Define three points to represent the vertices of a triangle */
    Point p1 = {0.0, 0.0};
    Point p2 = {3.0, 0.0};
    Point p3 = {0.0, 4.0};

    /* Calculate the area of the triangle */
    double area = triangle_area(p1, p2, p3);

    /* Print the area of the triangle */
    printf("The area of the triangle with vertices (%.1f, %.1f), (%.1f, %.1f), and (%.1f, %.1f) is %.1f\n", 
           p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, area);

    return 0;
}