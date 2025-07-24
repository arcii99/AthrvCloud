//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: asynchronous
// Asynchronous implementation of Graham Scan Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

typedef struct Point {
    int x, y;
} Point;

// Check if 3 points make a counter clockwise turn
int ccw(Point a, Point b, Point c) {
    return (c.y - a.y) * (b.x - a.x) > (b.y - a.y) * (c.x - a.x);
}

// Swap two points
void swap(Point *a, Point *b) {
    Point temp = *a;
    *a = *b;
    *b = temp;
}

// Sort points based on polar angle
void sortPoints(Point *points, int n) {
    Point p0 = points[0];
    for(int i = 1; i < n; i++) {
        // Calculate polar angle from horizontal axis
        int dy = points[i].y - p0.y;
        int dx = points[i].x - p0.x;
        double angle = atan2(dy, dx);

        for(int j = i + 1; j < n; j++) {
            int dy2 = points[j].y - p0.y;
            int dx2 = points[j].x - p0.x;
            double angle2 = atan2(dy2, dx2);

            // Sort points based on polar angle
            if(angle2 < angle) {
                swap(&points[i],&points[j]);
                angle = angle2;
            }
        }
    }
}

// Function to implement Graham's scan algorithm
void graham_scan(Point *points, int n, Point *convexHull, int *hullSize) {
    // Find the bottom-most point
    int min_point = 0;
    for(int i = 1; i < n; i++) {
        if(points[i].y < points[min_point].y) {
            min_point = i;
        }
        // In case of a tie, choose the left-most point
        else if(points[i].y == points[min_point].y &&
                points[i].x < points[min_point].x) {
            min_point = i;
        }
    }

    // Move the bottom-most point to the first position
    swap(&points[0], &points[min_point]);

    // Sort points based on polar angle with respect to the first point
    sortPoints(points, n);

    convexHull[0] = points[0];
    convexHull[1] = points[1];
    int top = 1;

    // Find the remaining points of the convex hull
    #pragma omp parallel shared(top,convexHull,hullSize,points)
    {
        #pragma omp for
        for(int i = 2; i < n; i++) {
            while(top > 0 && !ccw(convexHull[top-1], convexHull[top], points[i])) {
                // Remove the top point from the stack
                top--;
            }
            // Add the new point to the stack
            convexHull[++top] = points[i];
        }
    }

    *hullSize = top + 1;
}

int main() {
    int n = 10;
    Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0},
                      {1, 2}, {3, 1}, {3, 3}, {4, 2}, {1, 0}};
    Point convexHull[n];
    int hullSize;

    graham_scan(points, n, convexHull, &hullSize);

    // Print the points in the convex hull
    printf("Convex Hull:\n");
    for(int i = 0; i < hullSize; i++) {
        printf("(%d, %d)\n", convexHull[i].x, convexHull[i].y);
    }

    return 0;
}