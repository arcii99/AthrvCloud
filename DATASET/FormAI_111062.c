//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793

typedef struct point{
    double x, y;
} Point;

typedef struct lineSegment {
    Point p1, p2;
} LineSegment;

double Distance(Point p1, Point p2){
    return sqrt(pow(p2.x-p1.x,2)+pow(p2.y-p1.y,2));
}

double Slope(Point p1, Point p2){
    return (p2.y-p1.y)/(p2.x-p1.x);
}

double Angle(LineSegment ls1, LineSegment ls2){
    double m1 = Slope(ls1.p1, ls1.p2);
    double m2 = Slope(ls2.p1, ls2.p2);
    return atan(fabs((m2-m1)/(1+(m1*m2))));
}

double AreaTriangle(Point p1, Point p2, Point p3){
    return fabs(0.5*((p1.x*(p2.y-p3.y))+(p2.x*(p3.y-p1.y))+(p3.x*(p1.y-p2.y))));
}

double PerimeterTriangle(Point p1, Point p2, Point p3){
    double a = Distance(p1, p2);
    double b = Distance(p2, p3);
    double c = Distance(p1, p3);
    return a + b + c;
}

int main(){
    Point p1 = {0, 0};
    Point p2 = {5, 0};
    Point p3 = {2, 3};
    
    double distance = Distance(p1, p2);
    double slope = Slope(p1, p2);
    double angle = Angle((LineSegment){p1, p2}, (LineSegment){p1, p3});
    double area = AreaTriangle(p1, p2, p3);
    double perimeter = PerimeterTriangle(p1, p2, p3);
    
    printf("Distance between points p1(%.2lf, %.2lf) and p2(%.2lf, %.2lf): %.2lf\n", p1.x, p1.y, p2.x, p2.y, distance);
    printf("Slope of line between points p1(%.2lf, %.2lf) and p2(%.2lf, %.2lf): %.2lf\n", p1.x, p1.y, p2.x, p2.y, slope);
    printf("Angle between line segment p1-p2 and line segment p1-p3: %.2lf degrees\n", angle*180/PI);
    printf("Area of triangle formed by points p1(%.2lf, %.2lf), p2(%.2lf, %.2lf) and p3(%.2lf, %.2lf): %.2lf\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, area);
    printf("Perimeter of triangle formed by points p1(%.2lf, %.2lf), p2(%.2lf, %.2lf) and p3(%.2lf, %.2lf): %.2lf\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, perimeter);
    
    return 0;
}