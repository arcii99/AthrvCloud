//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: future-proof
#include <stdio.h>
#include <math.h>

/*
 * Calculate the area of a regular n-sided polygon given the side length
 * using the formula: (n * s^2) / (4 * tan(pi/n))
 */
double calculate_polygon_area(int n, double s) {
    double pi = M_PI;
    double numerator = n * pow(s, 2);
    double denominator = 4 * tan(pi / n);
    return numerator / denominator;
}

/*
 * Calculate the distance between two points (x1, y1) and (x2, y2)
 * using the distance formula: sqrt((x2 - x1)^2 + (y2 - y1)^2)
 */
double calculate_distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(pow(dx, 2) + pow(dy, 2));
}

int main() {
    int n;
    double s, x1, y1, x2, y2;

    printf("Enter the number of sides of the polygon: ");
    scanf("%d", &n);

    printf("Enter the side length of the polygon: ");
    scanf("%lf", &s);

    double area = calculate_polygon_area(n, s);
    printf("The area of the polygon is: %lf\n", area);

    printf("Enter the coordinates of the first point (x1 y1): ");
    scanf("%lf %lf", &x1, &y1);

    printf("Enter the coordinates of the second point (x2 y2): ");
    scanf("%lf %lf", &x2, &y2);

    double distance = calculate_distance(x1, y1, x2, y2);
    printf("The distance between the two points is: %lf\n", distance);

    return 0;
}