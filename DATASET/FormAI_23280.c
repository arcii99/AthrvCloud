//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

struct Point {
    int x, y;
};

// Function to calculate the distance between two points
double distance(struct Point p1, struct Point p2) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

// Function to calculate the angle between three points
double angle(struct Point a, struct Point b, struct Point c) {
    double ab = distance(a, b);
    double bc = distance(b, c);
    double ac = distance(a, c);
    return acos((bc*bc + ab*ab - ac*ac) / (2*bc*ab)) * 180 / PI;
}

// Function to check if three points are collinear
int collinear(struct Point a, struct Point b, struct Point c) {
    return (b.y - a.y) * (c.x - b.x) == (c.y - b.y) * (b.x - a.x);
}

int main() {
    struct Point p1 = {0, 0};
    struct Point p2 = {3, 2};
    struct Point p3 = {4, 4};

    double d = distance(p1, p2);
    printf("Distance between p1 and p2: %.2lf\n", d);

    double a = angle(p1, p2, p3);
    printf("Angle between p1, p2, and p3: %.2lf degrees\n", a);

    if (collinear(p1, p2, p3)) {
        printf("p1, p2, and p3 are collinear\n");
    } else {
        printf("p1, p2, and p3 are not collinear\n");
    }

    return 0;
}