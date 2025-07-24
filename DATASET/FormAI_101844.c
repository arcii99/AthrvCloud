//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: peaceful
#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

double area_of_triangle(Point a, Point b, Point c)
{
    double ab = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
    double bc = sqrt(pow(c.x - b.x, 2) + pow(c.y - b.y, 2));
    double ca = sqrt(pow(a.x - c.x, 2) + pow(a.y - c.y, 2));
    double s = (ab + bc + ca) / 2.0;
    return sqrt(s * (s - ab) * (s - bc) * (s - ca));
}

int main()
{
    Point a = {0.0, 0.0};
    Point b = {5.0, 0.0};
    Point c = {2.5, 4.33};
    
    double area = area_of_triangle(a, b, c);
    
    printf("The area of the triangle formed by points ");
    printf("(%lf, %lf), (%lf, %lf), and (%lf, %lf) ", a.x, a.y, b.x, b.y, c.x, c.y);
    printf("is %lf\n", area);
    
    return 0;
}