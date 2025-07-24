//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define a structure for a 2D point
typedef struct _point {
    double x;
    double y;
} Point;

// function to compute the distance between two points
double distance(Point p1, Point p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// function to compute the angle between 3 points (p1, p2, p3)
double angle(Point p1, Point p2, Point p3)
{
    double angle1 = atan2(p2.y - p1.y, p2.x - p1.x);
    double angle2 = atan2(p3.y - p2.y, p3.x - p2.x);
    double angle = fabs(angle2 - angle1);
    return angle < M_PI ? angle : 2 * M_PI - angle;
}

// function to compute the area of a polygon given its vertices
double polygon_area(Point* polygon, int num_vertices)
{
    double area = 0;
    for (int i = 0; i < num_vertices; i++) {
        Point p1 = polygon[i];
        Point p2 = polygon[(i + 1) % num_vertices];
        area += p1.x * p2.y - p2.x * p1.y;
    }
    return fabs(area / 2);
}

int main()
{
    // create some sample points
    Point p1 = { 0, 0 };
    Point p2 = { 2, 0 };
    Point p3 = { 1, 1 };
    Point p4 = { 1, -1 };

    // compute the distance between p1 and p2
    printf("Distance between p1 and p2: %f\n", distance(p1, p2));

    // compute the angle between p1, p2, and p3
    printf("Angle between p1, p2, and p3: %f\n", angle(p1, p2, p3));

    // compute the area of a polygon defined by p1, p2, p3, and p4
    Point polygon[] = { p1, p2, p3, p4 };
    int num_vertices = sizeof(polygon) / sizeof(Point);
    printf("Area of polygon: %f\n", polygon_area(polygon, num_vertices));

    return 0;
}