//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: immersive
#include <stdio.h>
#include <math.h>

// calculate distance between two points
float distance(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// calculate angle between two lines
float angle(float x1, float y1, float x2, float y2, float x3, float y3) {
    float a = distance(x2, y2, x3, y3);
    float b = distance(x1, y1, x2, y2);
    float c = distance(x1, y1, x3, y3);
    return acos((pow(c, 2) - pow(a, 2) - pow(b, 2)) / (-2 * a * b));
}

// find convex hull of given set of points
void convexHull(int n, float x[], float y[]) {
    int hull[n];
    int idx = 0;
    
    // find leftmost point
    for (int i = 1; i < n; i++) {
        if (x[i] < x[idx]) {
            idx = i;
        }
    }
    
    int p = idx, q;
    do {
        hull[idx] = p;
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (angle(x[p], y[p], x[i], y[i], x[q], y[q]) < M_PI) {
                q = i;
            }
        }
        p = q;
    } while (p != idx);
    
    // print hull points
    for (int i = 0; i < n; i++) {
        if (hull[i] != -1) {
            printf("(%f, %f)\n", x[hull[i]], y[hull[i]]);
        }
    }
}

int main() {
    // example usage
    float x[] = { 0, 1, 1, 0 };
    float y[] = { 0, 0, 1, 1 };
    convexHull(4, x, y);
    return 0;
}