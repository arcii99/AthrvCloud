//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: protected
#include<stdio.h>
#define INF 0x3f3f3f3f

struct Point {
    int x;
    int y;
};

// Function to find the distance between two points
float dist(struct Point a, struct Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Function to find the orientation of triplet (p, q, r)
// Returns 0 for colinear points, 1 for clockwise points and 2 for counterclockwise points
int orientation(struct Point p, struct Point q, struct Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0; // colinear

    return (val > 0) ? 1 : 2; // Clockwise or counterclockwise
}

// Function to find the convex hull of a set of n points
void convexHull(struct Point points[], int n) {
    // There must be at least 3 points
    if (n < 3)
        return;

    // Initialize result and stack
    int hull[n];
    int top = -1;

    // Find leftmost point
    int l = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[l].x)
            l = i;
    }

    // Start from leftmost point, keep moving counterclockwise until reaching the start point
    int p = l, q;
    do {
        hull[++top] = p;
        q = (p + 1) % n;

        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }

        p = q;
    } while (p != l);

    // Print points in convex hull order
    for (int i = 0; i <= top; i++)
        printf("(%d, %d)\n", points[hull[i]].x, points[hull[i]].y);
}

int main() {
    struct Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                             {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);
    convexHull(points, n);
    return 0;
}