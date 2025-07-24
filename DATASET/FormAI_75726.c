//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: all-encompassing
#include <stdio.h>
#include <math.h>

/* Function to calculate distance between two points */
double dist(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

/* Function to calculate area of a triangle given its sides */
double triangleArea(double a, double b, double c)
{
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

/* Function to calculate area of a circle given its radius */
double circleArea(double r)
{
    return M_PI * r * r;
}

int main()
{
    double x1, y1, x2, y2, x3, y3, r;
    printf("Enter coordinates of triangle vertices: ");
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    double a = dist(x1, y1, x2, y2);
    double b = dist(x2, y2, x3, y3);
    double c = dist(x3, y3, x1, y1);
    double triArea = triangleArea(a, b, c);
    printf("The area of the triangle is: %lf\n", triArea);
    printf("Enter radius of circle: ");
    scanf("%lf", &r);
    double cirArea = circleArea(r);
    printf("The area of the circle is: %lf\n", cirArea);
    return 0;
}