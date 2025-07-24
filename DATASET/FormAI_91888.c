//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: unmistakable
#include<stdio.h>
#include<math.h>

// This program calculates the distance between two points on the Cartesian plane.

typedef struct Point {
    double x;
    double y;
} point;

double distance(point a, point b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    point p1, p2;
    printf("Enter the x coordinate of the first point: ");
    scanf("%lf", &p1.x);
    printf("Enter the y coordinate of the first point: ");
    scanf("%lf", &p1.y);
    printf("Enter the x coordinate of the second point: ");
    scanf("%lf", &p2.x);
    printf("Enter the y coordinate of the second point: ");
    scanf("%lf", &p2.y);
    double d = distance(p1, p2);
    printf("The distance between (%.2lf, %.2lf) and (%.2lf, %.2lf) is %.2lf.\n", p1.x, p1.y, p2.x, p2.y, d);
    return 0;
}