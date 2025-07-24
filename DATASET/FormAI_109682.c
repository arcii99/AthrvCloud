//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: authentic
#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, x2, y2, x3, y3;
    double a, b, c;
    double s, r, R, area, perimeter;
    double A, B, C, alpha, beta, gamma, sum;

    // prompt user for input
    printf("Enter the coordinates of three points in the plane:\n");
    printf("Point 1: ");
    scanf("%lf %lf", &x1, &y1);
    printf("Point 2: ");
    scanf("%lf %lf", &x2, &y2);
    printf("Point 3: ");
    scanf("%lf %lf", &x3, &y3);

    // compute side lengths using distance formula
    a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

    // compute area using Heron's formula
    s = (a + b + c) / 2;
    area = sqrt(s * (s - a) * (s - b) * (s - c));

    // compute perimeter
    perimeter = a + b + c;

    // compute circumference and radii of circumcircle and incircle
    A = acos((b*b + c*c - a*a)/(2*b*c));
    B = acos((c*c + a*a - b*b)/(2*c*a));
    C = acos((a*a + b*b - c*c)/(2*a*b));
    sum = A + B + C;
    alpha = A/sum;
    beta = B/sum;
    gamma = C/sum;

    s = perimeter / 2;
    r = area / s;
    R = a * b * c / (4 * area);

    // output results
    printf("\nTriangle sides: %.2lf, %.2lf, %.2lf\n", a, b, c);
    printf("Area: %.2lf\n", area);
    printf("Perimeter: %.2lf\n", perimeter);
    printf("Incircle radius: %.2lf\n", r);
    printf("Circumcircle radius: %.2lf\n", R);
    printf("Inner angles: %.2lf, %.2lf, %.2lf\n", alpha, beta, gamma);

    return 0;
}