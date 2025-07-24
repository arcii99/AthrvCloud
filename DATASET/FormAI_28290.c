//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: detailed
#include <stdio.h>
#include <math.h>

//Function to calculate the distance between two points
double distance(double x1, double y1, double x2, double y2)
{
    double distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return distance;
}

//Function to calculate the area of a triangle
double area_triangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double a = distance(x1, y1, x2, y2);
    double b = distance(x1, y1, x3, y3);
    double c = distance(x2, y2, x3, y3);
    double s = (a + b + c) / 2.0;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}

//Function to check if a given point is inside a triangle
int is_inside(double x1, double y1, double x2, double y2, double x3, double y3, double x, double y)
{
    double A = area_triangle(x1, y1, x2, y2, x3, y3);
    double A1 = area_triangle(x, y, x2, y2, x3, y3);
    double A2 = area_triangle(x1, y1, x, y, x3, y3);
    double A3 = area_triangle(x1, y1, x2, y2, x, y);
    if (A == (A1 + A2 + A3))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    double x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of the first point: ");
    scanf("%lf %lf", &x1, &y1);
    printf("Enter the coordinates of the second point: ");
    scanf("%lf %lf", &x2, &y2);
    printf("Enter the coordinates of the third point: ");
    scanf("%lf %lf", &x3, &y3);
    double x, y;
    printf("Enter the coordinates of the point to check: ");
    scanf("%lf %lf", &x, &y);
    int result = is_inside(x1, y1, x2, y2, x3, y3, x, y);
    if (result == 1)
    {
        printf("The point is inside the triangle.");
    }
    else
    {
        printf("The point is outside the triangle.");
    }
    return 0;
}