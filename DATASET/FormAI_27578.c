//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: rigorous
/* This program computes the center of a circle given three non-collinear points on its circumference. */

#include <stdio.h>
#include <math.h>

// Define the Point struct
typedef struct {
    double x;
    double y;
} Point;

// Define the Circle struct
typedef struct {
    Point center; // center point of circle
    double radius; // radius of circle
} Circle;

// Compute the distance between two points
double distance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

// Compute the circle given three points on its circumference
Circle circleFromPoints(Point p1, Point p2, Point p3) {
    double ma, mb, centerX, centerY;
    Point midPoint12 = { (p1.x+p2.x)/2.0, (p1.y+p2.y)/2.0 };
    Point midPoint23 = { (p2.x+p3.x)/2.0, (p2.y+p3.y)/2.0 };
    ma = (p2.y-p1.y)/(p2.x-p1.x);
    mb = (p3.y-p2.y)/(p3.x-p2.x);
    centerX = (ma*mb*(p1.y-p3.y) + mb*(p1.x+p2.x) - ma*(p2.x+p3.x)) / (2.0*(mb-ma));
    centerY = (-1.0/ma) * (centerX - midPoint12.x) + midPoint12.y;
    Circle result = { {centerX, centerY}, distance(result.center, p1) };
    return result;
}

int main() {
    // Define three points on the circle's circumference
    Point p1 = {1, 3};
    Point p2 = {4, 9};
    Point p3 = {7, 2};
    
    Circle myCircle = circleFromPoints(p1, p2, p3);
    printf("Center = (%.2f, %.2f)\n", myCircle.center.x, myCircle.center.y);
    printf("Radius = %.2f\n", myCircle.radius);
    
    return 0;
}