//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: dynamic
#include <stdio.h>
#include <math.h>

typedef struct Point
{
    double x;
    double y;
} Point;

double distance(Point p1, Point p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double perimeter(Point *points, int num_points)
{
    double perimeter = 0.0;
    for(int i=0; i<num_points; i++)
    {
        perimeter += distance(points[i], points[(i+1)%num_points]);
    }
    return perimeter;
}

double area(Point *points, int num_points)
{
    double area = 0.0;
    for(int i=0; i<num_points; i++)
    {
        area += points[i].x * points[(i+1)%num_points].y;
        area -= points[i].y * points[(i+1)%num_points].x;
    }
    return 0.5 * fabs(area);
}

int main()
{
    int num_points = 4;
    Point square[] = {{0, 0}, {0, 1}, {1, 1}, {1, 0}};

    printf("Perimeter of square: %.2f\n", perimeter(square, num_points));
    printf("Area of square: %.2f\n", area(square, num_points));

    return 0;
}