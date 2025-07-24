//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: decentralized
#include <stdio.h>

// Definition of a point in 2D space
typedef struct Point {
    double x;
    double y;
} Point;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {
    // Create an array of points
    Point points[5] = {{0, 0}, {1, 1}, {2, 1}, {3, 0}, {2, -1}};

    // Find the centroid of the polygon defined by the points
    Point centroid = {0, 0};
    double area = 0;
    for (int i = 0; i < 4; i++) {
        double xi = points[i].x;
        double yi = points[i].y;
        double xi1 = points[i + 1].x;
        double yi1 = points[i + 1].y;

        double ai = xi * yi1 - xi1 * yi;
        area += ai;

        centroid.x += (xi + xi1) * ai;
        centroid.y += (yi + yi1) * ai;
    }
    double xi = points[4].x;
    double yi = points[4].y;
    double xi1 = points[0].x;
    double yi1 = points[0].y;
    double a5 = xi * yi1 - xi1 * yi;
    area += a5;

    centroid.x += (xi + xi1) * a5;
    centroid.y += (yi + yi1) * a5;

    area *= 0.5;
    centroid.x /= (6 * area);
    centroid.y /= (6 * area);

    // Find the farthest point from the centroid
    double farthestDist = -1;
    Point farthestPoint = {0, 0};
    for (int i = 0; i < 5; i++) {
        double dist = distance(centroid, points[i]);
        if (dist > farthestDist) {
            farthestDist = dist;
            farthestPoint = points[i];
        }
    }

    // Print the results
    printf("Centroid: (%f, %f)\n", centroid.x, centroid.y);
    printf("Farthest point: (%f, %f)\n", farthestPoint.x, farthestPoint.y);

    return 0;
}