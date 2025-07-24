//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: configurable
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point center;
    double radius;
} Circle;

double distance(Point A, Point B) {
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

double getCircleArea(Circle c) {
    return PI * pow(c.radius, 2);
}

int main() {
    Point A = {0, 0};
    Point B = {5, 5};
    Circle c = {{2, 2}, 3};

    double dist = distance(A, B);
    printf("The distance between A(%lf, %lf) and B(%lf, %lf) is %lf\n", 
           A.x, A.y, B.x, B.y, dist);

    double area = getCircleArea(c);
    printf("The area of circle with center(%lf, %lf) and radius %lf is %lf\n",
           c.center.x, c.center.y, c.radius, area);

    return 0;
}