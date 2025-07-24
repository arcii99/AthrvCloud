//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

typedef struct Point{
    double x;
    double y;
} Point;

typedef struct Circle{
    Point center;
    double radius;
} Circle;

double distance(Point p1, Point p2){
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

int main(){

    Point p1, p2, p3;
    printf("Enter the coordinates of three points to form a triangle: \n");
    scanf("%lf %lf %lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y);

    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p3, p1);
    double s = (a + b + c)/2;
    double area = sqrt(s*(s-a)*(s-b)*(s-c));

    printf("The area of the triangle is: %.2lf units.\n", area);

    Circle circ;
    printf("Enter the coordinates of the center and radius of a circle: \n");
    scanf("%lf %lf %lf", &circ.center.x, &circ.center.y, &circ.radius);

    Point p4;
    printf("Enter the coordinates of a point: \n");
    scanf("%lf %lf", &p4.x, &p4.y);

    double dist = distance(circ.center, p4);
    if(dist < circ.radius){
        printf("The point lies inside the circle.\n");
    }
    else if(dist == circ.radius){
        printf("The point lies on the circumference of the circle.\n");
    }
    else{
        printf("The point lies outside the circle.\n");
    }

    return 0;
}