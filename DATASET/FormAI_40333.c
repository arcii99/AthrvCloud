//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define structure for a point
typedef struct {
    double x;
    double y;
} Point;

// Function to calculate cross product of two vectors
double cross_product(Point a, Point b) {
    return a.x * b.y - b.x * a.y;
}

int main(void) {
    // Define variables
    int n;
    Point *points, pivot, tmp;
    int i, j, min_idx;
    double min_angle, angle;

    // Get number of points
    printf("Enter number of points: ");
    scanf("%d", &n);

    // Allocate memory for array of points
    points = malloc(n * sizeof(Point));

    // Get points from user input
    for (i = 0; i < n; i++) {
        printf("Enter x-coordinate of point %d: ", i+1);
        scanf("%lf", &points[i].x);
        printf("Enter y-coordinate of point %d: ", i+1);
        scanf("%lf", &points[i].y);
    }

    // Find point with lowest y-coordinate (tiebreaker: leftmost point)
    min_idx = 0;
    for (i = 1; i < n; i++) {
        if (points[i].y < points[min_idx].y || 
            (points[i].y == points[min_idx].y && points[i].x < points[min_idx].x)) {
            min_idx = i;
        }
    }

    // Set pivot point to lowest point
    pivot = points[min_idx];

    // Bubble sort points by angle (in counterclockwise order) around pivot point
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            // Calculate angles of points relative to pivot point
            Point a = {points[j].x - pivot.x, points[j].y - pivot.y};
            Point b = {points[j+1].x - pivot.x, points[j+1].y - pivot.y};
            angle = atan2(cross_product(a, b), a.x * b.x + a.y * b.y);

            // Check if jth point has smaller angle than (j+1)th point
            if (angle < 0) {
                tmp = points[j];
                points[j] = points[j+1];
                points[j+1] = tmp;
            }
        }
    }

    // Print out sorted points
    printf("\nSorted points (in counterclockwise order around pivot point):\n");
    for (i = 0; i < n; i++) {
        printf("(%lf, %lf)\n", points[i].x, points[i].y);
    }

    // Free memory
    free(points);

    return 0;
}