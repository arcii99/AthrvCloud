//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: sophisticated
#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, x2, y2, x3, y3;
    double p, A, l1, l2, l3, s, r, R;
    double a, b, c, alpha, beta, gamma;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    // Compute side lengths
    l1 = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    l2 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    l3 = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    // Compute the perimeter and area
    p = l1 + l2 + l3;
    s = p / 2;
    A = sqrt(s * (s - l1) * (s - l2) * (s - l3));
    // Compute circumradius
    r = 2 * A / p;
    R = (l1 * l2 * l3) / (4 * A);
    // Compute angles
    alpha = acos((l1 * l1 + l3 * l3 - l2 * l2) / (2 * l1 * l3));
    beta = acos((l1 * l1 + l2 * l2 - l3 * l3) / (2 * l1 * l2));
    gamma = acos((l2 * l2 + l3 * l3 - l1 * l1) / (2 * l2 * l3));
    // Compute sides of inscribed circle
    a = 2 * A / l1;
    b = 2 * A / l2;
    c = 2 * A / l3;
    printf("Perimeter: %.2lf\n", p);
    printf("Area: %.2lf\n", A);
    printf("Circumradius: %.2lf\n", R);
    printf("Inradius: %.2lf\n", r);
    printf("Angle alpha: %.2lf\n", alpha);
    printf("Angle beta: %.2lf\n", beta);
    printf("Angle gamma: %.2lf\n", gamma);
    printf("Side a of inscribed circle: %.2lf\n", a);
    printf("Side b of inscribed circle: %.2lf\n", b);
    printf("Side c of inscribed circle: %.2lf\n", c);
    return 0;
}