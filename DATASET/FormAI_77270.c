//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} point;

double distance(point a, point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {

    // Create three points
    point a = {0, 0};
    point b = {3, 4};
    point c = {4, 0};

    // Compute the distance between each pair of points
    double ab = distance(a, b);
    double ac = distance(a, c);
    double bc = distance(b, c);

    // Compute the semiperimeter
    double s = (ab + ac + bc) / 2;

    // Compute the area using Heron's formula
    double area = sqrt(s * (s - ab) * (s - ac) * (s - bc));

    // Check if the points are collinear
    if ((b.x - a.x) * (c.y - a.y) == (c.x - a.x) * (b.y - a.y)) {
        printf("The points are collinear!\n");
    } else {
        printf("The area of the triangle is %f\n", area);
    }

    return 0;
}