//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
    double x;
    double y;
} Point;

// comparator function to sort points based on x coordinate
int cmp(const void* a, const void* b) {
    Point *p1 = (Point *)a,  *p2 = (Point *)b;
    if (p1->x == p2->x)
        return (p1->y - p2->y);
    return (p1->x - p2->x);
}

// Determines whether a point lies to the left or right of a line segment
int orientation(Point p, Point q, Point r) {
    double val = ((q.y - p.y) * (r.x - q.x)) - ((q.x - p.x) * (r.y - q.y));
    if (val == 0)
        return 0;  // colinear
    return (val > 0) ? 1 : 2; // clockwise or counterclockwise
}

// Calculates the distance between two points
double dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

// Calculates the perimeter of a polygon
double perimeter(Point points[], int n) {
    if (n < 3)
        return 0;

    // Sort points based on x coordinate
    qsort(points, n, sizeof(Point), cmp);

    Point hull[2*n];
    int k = 0;

    // Calculate lower hull
    for (int i = 0; i < n; i++) {
        while (k >= 2 && orientation(hull[k-2], hull[k-1], points[i]) != 2)
            k--;
        hull[k++] = points[i];
    }

    // Calculate upper hull
    for (int i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && orientation(hull[k-2], hull[k-1], points[i]) != 2)
            k--;
        hull[k++] = points[i];
    }

    double perim = 0;
    for (int i = 1; i < k; i++) {
        perim += dist(hull[i-1], hull[i]);
    }

    return perim;
}

// Example usage
int main() {
    // Define the polygon using an array of points
    Point polygon[] = {{0, 0}, {0, 4}, {3, 6}, {6, 4}, {6, 0}};
    int n = sizeof(polygon)/sizeof(polygon[0]);
    printf("Perimeter of polygon is: %f\n", perimeter(polygon, n));
    return 0;
}