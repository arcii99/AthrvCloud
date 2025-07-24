//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: expert-level
#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, x2, y2, x3, y3;
    double a, b, c;
    double s, r, R;

    // Prompt user to input coordinates of three points
    printf("Enter coordinates of first point: ");
    scanf("%lf %lf", &x1, &y1);

    printf("Enter coordinates of second point: ");
    scanf("%lf %lf", &x2, &y2);

    printf("Enter coordinates of third point: ");
    scanf("%lf %lf", &x3, &y3);

    // Calculate lengths of sides of the triangle
    a = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    b = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    c = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

    // Calculate semiperimeter of the triangle
    s = (a + b + c) / 2;

    // Calculate area of the triangle
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    printf("Area of the triangle: %.2lf\n", area);

    // Calculate radius of inscribed circle of the triangle
    r = area / s;
    printf("Radius of inscribed circle: %.2lf\n", r);

    // Calculate radius of circumcircle of the triangle
    R = a * b * c / (4 * area);
    printf("Radius of circumcircle: %.2lf\n", R);

    // Calculate angles of the triangle
    double alpha = acos((b * b + c * c - a * a) / (2 * b * c));
    double beta = acos((a * a + c * c - b * b) / (2 * a * c));
    double gamma = acos((a * a + b * b - c * c) / (2 * a * b));
    
    // Convert angles from radians to degrees
    alpha = alpha * 180 / M_PI;
    beta = beta * 180 / M_PI;
    gamma = gamma * 180 / M_PI;

    // Output angles to user
    printf("Angle opposite to first point (in degrees): %.2lf\n", alpha);
    printf("Angle opposite to second point (in degrees): %.2lf\n", beta);
    printf("Angle opposite to third point (in degrees): %.2lf\n", gamma);

    return 0;
}