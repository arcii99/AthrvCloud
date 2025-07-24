//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// Define a Point struct to represent a point in a 2D plane
typedef struct {
    double x;
    double y;
} Point;

// Define a Circle struct to represent a circle in a 2D plane
typedef struct {
    Point center;
    double radius;
} Circle;

// Define a LineSegment struct to represent a line segment in a 2D plane
typedef struct {
    Point start;
    Point end;
} LineSegment;

// Define a function to calculate the distance between two points
double distance(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

// Define a function to check if a point is inside a circle
bool isPointInsideCircle(Point p, Circle c) {
    double d = distance(p, c.center);
    return d < c.radius;
}

// Define a function to check if a line segment intersects a circle
bool doesLineSegmentIntersectCircle(LineSegment ls, Circle c) {
    double r = c.radius;
    Point p1 = ls.start;
    Point p2 = ls.end;
    Point c1 = c.center;
    double distanceSquared = pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2);
    double dotProduct = ((c1.x - p1.x) * (p2.x - p1.x)) + ((c1.y - p1.y) * (p2.y - p1.y));
    double t_squared = pow(dotProduct, 2) / distanceSquared;
    Point closestPoint = {
        .x = p1.x + (dotProduct / distanceSquared) * (p2.x - p1.x),
        .y = p1.y + (dotProduct / distanceSquared) * (p2.y - p1.y),
    };
    if (!isPointInsideCircle(closestPoint, c)) {
        return false;
    }
    double distanceToIntersection = sqrt(pow(r, 2) - pow(distance(closestPoint, c1), 2));
    double tMin = t_squared - (distanceToIntersection / sqrt(distanceSquared));
    double tMax = t_squared + (distanceToIntersection / sqrt(distanceSquared));
    if ((tMin >= 0 && tMin <= 1) || (tMax >= 0 && tMax <= 1)) {
        return true;
    }
    return false;
}

int main() {
    // Create a circle centered at (0, 0) with a radius of 1
    Circle c = {
        .center = {.x = 0, .y = 0},
        .radius = 1,
    };

    // Create a line segment from (1, 1) to (-1, -1)
    LineSegment ls = {
        .start = {.x = 1, .y = 1},
        .end = {.x = -1, .y = -1},
    };

    // Check if the line segment intersects the circle
    bool intersects = doesLineSegmentIntersectCircle(ls, c);

    if (intersects) {
        printf("The line segment intersects the circle!\n");
    } else {
        printf("The line segment does not intersect the circle.\n");
    }

    return 0;
}