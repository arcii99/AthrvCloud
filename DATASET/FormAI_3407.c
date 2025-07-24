//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Declare structures for Point and Line
typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point start;
    Point end;
} Line;

// Declare functions to calculate slope, distance and intersection of lines
double slope(Line line) {
    return (line.end.y - line.start.y) / (line.end.x - line.start.x);
}

double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

Point intersection(Line line1, Line line2) {
    double m1 = slope(line1);
    double m2 = slope(line2);
    double x = (m1 * line1.start.x - m2 * line2.start.x + line2.start.y - line1.start.y) / (m1 - m2);
    double y = m1 * (x - line1.start.x) + line1.start.y;
    Point intersection_point = {x, y};
    return intersection_point;
}

int main() {

    // Declare points and lines
    Point p1 = {1.0, 1.0};
    Point p2 = {3.0, 5.0};
    Point p3 = {4.0, 2.0};
    Point p4 = {2.0, 4.0};
    Line line1 = {p1, p2};
    Line line2 = {p3, p4};

    // Calculate and print slope of line1
    double m1 = slope(line1);
    printf("Slope of line1 is: %lf\n", m1);

    // Calculate and print distance between p1 and p2
    double d1 = distance(p1, p2);
    printf("Distance between p1 and p2 is: %lf\n", d1);

    // Calculate and print intersection of line1 and line2
    Point intersection_point = intersection(line1, line2);
    printf("Intersection point of line1 and line2 is: (%lf, %lf)\n", intersection_point.x, intersection_point.y);

    return 0;
}