//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

struct point
{
    double x;
    double y;
};

// Function to calculate the distance between two points
double calc_distance(struct point p1, struct point p2)
{
    double distance;
    distance = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
    return distance;
}

// Function to calculate the area of a circle
double calc_circle_area(double radius)
{
    double area;
    area = PI * pow(radius, 2);
    return area;
}

// Function to calculate the area of a triangle
double calc_triangle_area(struct point p1, struct point p2, struct point p3)
{
    double side_1, side_2, side_3, semi_perimeter, area;
    side_1 = calc_distance(p1, p2);
    side_2 = calc_distance(p2, p3);
    side_3 = calc_distance(p3, p1);
    semi_perimeter = (side_1 + side_2 + side_3) / 2;
    area = sqrt(semi_perimeter * (semi_perimeter - side_1) * (semi_perimeter - side_2) * (semi_perimeter - side_3));
    return area;
}

int main()
{
    // Initializing the points
    struct point p1 = {1.0, 1.0};
    struct point p2 = {4.0, 5.0};
    struct point p3 = {7.0, 4.0};

    // Calculating the distance between two points
    printf("Distance between p1 and p2 = %.2lf\n", calc_distance(p1, p2));
    printf("Distance between p2 and p3 = %.2lf\n", calc_distance(p2, p3));
    printf("Distance between p3 and p1 = %.2lf\n", calc_distance(p3, p1));

    // Calculating the area of a circle with radius 5.0
    printf("Area of circle with radius 5.00 = %.2lf\n", calc_circle_area(5.0));

    // Calculating the area of a triangle formed by the points p1, p2, and p3
    printf("Area of triangle formed by p1, p2, and p3 = %.2lf\n", calc_triangle_area(p1, p2, p3));

    return 0;
}