//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: rigorous
#include <stdio.h>
#include <math.h>

// Define a struct to represent a point in 2D space
typedef struct {
    double x;
    double y;
} Point;

// Calculate the distance between two points using the Pythagorean theorem
double distance(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

// Calculate the angle between two points and the origin
double angle(Point a, Point b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    return atan2(dy, dx);
}

int main() {
    // Define two points on a Cartesian grid
    Point a = {0, 0};
    Point b = {3, 4};

    // calculate the distance and angle between the two points
    double dist = distance(a, b);
    double ang = angle(a, b);

    printf("Distance between points: %f\n", dist);
    printf("Angle between points: %f radians\n", ang);

    return 0;
}