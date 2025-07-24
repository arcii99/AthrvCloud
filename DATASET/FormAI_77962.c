//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    // Given three points (x1, y1), (x2, y2), and (x3, y3), find the circumcenter of the triangle. 

    double x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of first point (x1, y1): ");
    scanf("%lf %lf", &x1, &y1);
    printf("Enter the coordinates of second point (x2, y2): ");
    scanf("%lf %lf", &x2, &y2);
    printf("Enter the coordinates of third point (x3, y3): ");
    scanf("%lf %lf", &x3, &y3);

    // Calculate the midpoints of the sides of the triangle
    double mid_x12 = (x1 + x2) / 2;
    double mid_y12 = (y1 + y2) / 2;
    double mid_x13 = (x1 + x3) / 2;
    double mid_y13 = (y1 + y3) / 2;

    // Calculate the slopes of the sides of the triangle
    double slope12 = (x2 - x1) / (y2 - y1);
    double slope13 = (x3 - x1) / (y3 - y1);

    // Calculate the coordinates of the circumcenter
    double circumcenter_x = ((mid_y13 - mid_y12) + slope12 * mid_x12 - slope13 * mid_x13) / (2 * (slope12 - slope13));
    double circumcenter_y = (-1 / slope12) * (circumcenter_x - mid_x12) + mid_y12;

    // Calculate the radius of the circumcircle
    double radius = sqrt(pow(circumcenter_x - x1, 2) + pow(circumcenter_y - y1, 2));

    printf("\nThe coordinates of the circumcenter are (%lf, %lf).\n", circumcenter_x, circumcenter_y);
    printf("The radius of the circumcircle is %lf units.\n", radius);

    return 0;
}