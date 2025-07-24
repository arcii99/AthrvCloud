//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int y;
} point;

point p0; // Global variable to store the lowest and/or leftmost point

int swap(point* a, point* b) {
    point temp = *a;
    *a = *b;
    *b = temp;
}

// Find the orientation of three points
int orientation(point p, point q, point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;     // Collinear
    return (val > 0) ? 1 : 2;   // Clockwise or counterclockwise
}

// Compare function for qsort to sort the points by polar angle
int compare(const void* vp1, const void* vp2) {
    point* p1 = (point*)vp1;
    point* p2 = (point*)vp2;
    int o = orientation(p0, *p1, *p2);
    if (o == 0) return (p0.x - p1->x) * (p0.x - p1->x) + (p0.y - p1->y) * (p0.y - p1->y) < (p0.x - p2->x) * (p0.x - p2->x) + (p0.y - p2->y) * (p0.y - p2->y);
    return (o == 2) ? -1 : 1;
}

// Graham's scan algorithm to find the convex hull of a set of n points
void convexHull(point points[], int n) {
    // Find the lowest and/or leftmost point and put it at the beginning
    int ymin = points[0].y;
    int min = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x)) {
            ymin = points[i].y;
            min = i;
        }
    }
    swap(&points[0], &points[min]);
    p0 = points[0];
    // Sort the points by polar angle with respect to p0
    qsort(&points[1], n - 1, sizeof(point), compare);
    // Use a stack to keep track of the boundary points
    int stack[n];
    int top = 2;
    stack[0] = 0;
    stack[1] = 1;
    // Traverse the sorted points and add them to the stack if they make a left turn
    // Remove points from the stack if they make a right turn until only the boundary points are left
    for (int i = 2; i < n; i++) {
        while (top > 1 && orientation(points[stack[top - 2]], points[stack[top - 1]], points[i]) != 2) {
            top--;
        }
        stack[top] = i;
        top++;
    }
    // Print the boundary points in clockwise order
    printf("The convex hull consists of the following points:\n");
    for (int i = 0; i < top; i++) {
        printf("(%d, %d)\n", points[stack[i]].x, points[stack[i]].y);
    }
}

int main() {
    point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);
    convexHull(points, n);
    return 0;
}