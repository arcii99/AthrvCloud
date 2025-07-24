//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <math.h>

// Define a point with x and y coordinates
typedef struct Point {
    double x;
    double y;
} Point;

// Define a line with slope and y-intercept
typedef struct Line {
    double m; // slope
    double b; // y-intercept
} Line;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Function to calculate the slope of a line
double slope(Point p1, Point p2) {
    return (p2.y - p1.y) / (p2.x - p1.x);
}

// Function to calculate the y-intercept of a line using the slope and a point on the line
double y_intercept(double slope, Point p) {
    return p.y - slope * p.x;
}

// Function to find the line that passes through two points
Line line_through_points(Point p1, Point p2) {
    double m = slope(p1, p2);
    double b = y_intercept(m, p1);
    Line line = {m, b};
    return line;
}

// Function to find the intersection point of two lines
Point intersection(Line l1, Line l2) {
    double x = (l2.b - l1.b) / (l1.m - l2.m);
    double y = l1.m * x + l1.b;
    Point intersection = {x, y};
    return intersection;
}

int main() {
    Point p1 = {0, 0};
    Point p2 = {1, 1};
    Point p3 = {0, 1};
    Point p4 = {1, 0};
    
    Line l1 = line_through_points(p1, p2);
    Line l2 = line_through_points(p3, p4);
    
    Point intersection_point = intersection(l1, l2);
    
    double d1 = distance(p1, intersection_point);
    double d2 = distance(p2, intersection_point);
    double d3 = distance(p3, intersection_point);
    double d4 = distance(p4, intersection_point);
    
    printf("Intersection point: (%.2lf, %.2lf)\n", intersection_point.x, intersection_point.y);
    printf("Distance from point 1 to intersection: %.2lf\n", d1);
    printf("Distance from point 2 to intersection: %.2lf\n", d2);
    printf("Distance from point 3 to intersection: %.2lf\n", d3);
    printf("Distance from point 4 to intersection: %.2lf\n", d4);
    
    return 0;
}