//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to store 2D points
struct Point {
    double x;
    double y;
};

// Function to calculate the distance between two points
double distance(struct Point p1, struct Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

// Function to calculate the area of a polygon
double polygonArea(struct Point polygon[], int n) {
    double area = 0;
    int i, j;

    // Calculate area using shoelace formula
    for (i = 0; i < n; i++) {
        j = (i + 1) % n;
        area += polygon[i].x * polygon[j].y;
        area -= polygon[j].x * polygon[i].y;
    }
    area = fabs(area) / 2.0;

    return area;
}

// Function to check if a point lies inside a given polygon
int pointInPolygon(struct Point polygon[], int n, struct Point point) {
    int i, j, c = 0;
    for (i = 0, j = n - 1; i < n; j = i++) {
        if (((polygon[i].y <= point.y) && (point.y < polygon[j].y))
            || ((polygon[j].y <= point.y) && (point.y < polygon[i].y))) {
            if (point.x < ((polygon[j].x - polygon[i].x) * (point.y - polygon[i].y) / (polygon[j].y - polygon[i].y)) + polygon[i].x) {
                c = !c;
            }
        }
    }
    return c;
}

int main() {
    // Define a polygon with 4 points
    struct Point polygon[4] = {{0, 0}, {0, 1}, {1, 1}, {1, 0}};

    // Print the area of the polygon
    printf("The area of the polygon is: %f\n", polygonArea(polygon, 4));

    // Define a point inside the polygon
    struct Point insidePoint = {0.5, 0.5};

    // Check if the point lies inside the polygon
    if (pointInPolygon(polygon, 4, insidePoint)) {
        printf("The point (%f, %f) lies inside the polygon.\n", insidePoint.x, insidePoint.y);
    } else {
        printf("The point (%f, %f) lies outside the polygon.\n", insidePoint.x, insidePoint.y);
    }

    // Define a point outside the polygon
    struct Point outsidePoint = {2, 2};

    // Check if the point lies inside the polygon
    if (pointInPolygon(polygon, 4, outsidePoint)) {
        printf("The point (%f, %f) lies inside the polygon.\n", outsidePoint.x, outsidePoint.y);
    } else {
        printf("The point (%f, %f) lies outside the polygon.\n", outsidePoint.x, outsidePoint.y);
    }

    return 0;
}