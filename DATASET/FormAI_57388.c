//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: real-life
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
} Point;

double distance(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    Point a, b, c;
    printf("Enter coordinates of Point A (x y): ");
    scanf("%lf %lf", &a.x, &a.y);
    printf("Enter coordinates of Point B (x y): ");
    scanf("%lf %lf", &b.x, &b.y);
    printf("Enter coordinates of Point C (x y): ");
    scanf("%lf %lf", &c.x, &c.y);

    // Calculate lengths of sides of triangle ABC
    double ab = distance(a, b);
    double bc = distance(b, c);
    double ca = distance(c, a);

    // Calculate angles of triangle ABC using law of cosines
    double A = acos((bc * bc + ca * ca - ab * ab) / (2 * bc * ca));
    double B = acos((ca * ca + ab * ab - bc * bc) / (2 * ca * ab));
    double C = acos((ab * ab + bc * bc - ca * ca) / (2 * ab * bc));

    // Print results
    printf("Side AB = %lf\n", ab);
    printf("Side BC = %lf\n", bc);
    printf("Side CA = %lf\n", ca);
    printf("Angle A = %lf degrees\n", A * 180 / PI);
    printf("Angle B = %lf degrees\n", B * 180 / PI);
    printf("Angle C = %lf degrees\n", C * 180 / PI);

    return 0;
}