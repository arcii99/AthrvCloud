//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Claude Shannon
/* A C program to calculate Intersection of two 2-D Lines */

#include <stdio.h>

// Structure to represent a Point in 2D space
typedef struct Point2D {
    double x, y;
} Point2D;

// Structure to represent a 2D Line between two Points
typedef struct Line2D {
    Point2D p1, p2;
} Line2D;

// Function to calculate the Intersection point of two 2D Lines
Point2D findIntersectionPoint(Line2D l1, Line2D l2) {
    double x1 = l1.p1.x;
    double x2 = l1.p2.x;
    double x3 = l2.p1.x;
    double x4 = l2.p2.x;

    double y1 = l1.p1.y;
    double y2 = l1.p2.y;
    double y3 = l2.p1.y;
    double y4 = l2.p2.y;

    double denom = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

    if (denom == 0) {
        printf("Lines are parallel, no intersection point exists.\n");
        exit(0);
    }

    double num1 = (x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4);
    double num2 = -1 * ((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3));

    double x = num1 / denom;
    double y = num2 / denom;

    return (Point2D){x, y};
}

int main() {
    // Define two Lines
    Line2D l1 = {{0, 0}, {5, 5}};
    Line2D l2 = {{0, 5}, {5, 0}};
    
    // Calculate the Intersection Point
    Point2D intersection = findIntersectionPoint(l1, l2);

    printf("Intersection Point: (%lf, %lf)\n", intersection.x, intersection.y);

    return 0;
}