//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a Point struct to represent a point using cartesian coordinates
typedef struct {
    double x;
    double y;
} Point;

// Define a Line struct to represent a line using two points
typedef struct {
    Point p1;
    Point p2;
} Line;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

// Function to calculate the area of a triangle using Heron's formula
double triangle_area(Point p1, Point p2, Point p3) {
    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p3, p1);
    double s = (a + b + c) / 2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

// Function to calculate the distance between a point and a line
double point_line_distance(Point p, Line l) {
    double dx = l.p2.x - l.p1.x;
    double dy = l.p2.y - l.p1.y;
    double numer = fabs(dy*p.x - dx*p.y + l.p2.x*l.p1.y - l.p2.y*l.p1.x);
    double denom = sqrt(dx*dx + dy*dy);
    return numer / denom;
}

// Main function to test the above functions
int main() {
    Point p1 = {0, 0};
    Point p2 = {3, 0};
    Point p3 = {0, 4};
    Line l1 = {p1, p2};
    Line l2 = {p2, p3};
    Line l3 = {p3, p1};
    printf("Area of triangle formed by (%.1f, %.1f), (%.1f, %.1f), and (%.1f, %.1f) = %.2f\n",
            p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, triangle_area(p1, p2, p3));
    printf("Distance between point (%.1f, %.1f) and line (%.1f, %.1f) to (%.1f, %.1f) = %.2f\n",
            p3.x, p3.y, l1.p1.x, l1.p1.y, l1.p2.x, l1.p2.y, point_line_distance(p3, l1));
    printf("Distance between point (%.1f, %.1f) and line (%.1f, %.1f) to (%.1f, %.1f) = %.2f\n",
            p1.x, p1.y, l2.p1.x, l2.p1.y, l2.p2.x, l2.p2.y, point_line_distance(p1, l2));
    printf("Distance between point (%.1f, %.1f) and line (%.1f, %.1f) to (%.1f, %.1f) = %.2f\n",
           p2.x, p2.y, l3.p1.x, l3.p1.y, l3.p2.x, l3.p2.y, point_line_distance(p2, l3));
    return 0;
}