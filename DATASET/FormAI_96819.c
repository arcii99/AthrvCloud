//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: optimized
#include<stdio.h>
#include<math.h>

struct point
{
    double x,y;
};

double findDistance(struct point p1, struct point p2)
{
    return sqrt((p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y));
}

double findPerimeter(double a, double b, double c)
{
    return a + b + c;
}

double findArea(double a, double b, double c)
{
    double s = (a + b + c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

void printPoints(struct point p1, struct point p2, struct point p3)
{
    printf("p1: (%.2lf, %.2lf)\n", p1.x, p1.y);
    printf("p2: (%.2lf, %.2lf)\n", p2.x, p2.y);
    printf("p3: (%.2lf, %.2lf)\n\n", p3.x, p3.y);
}

void findTriangleProperties(struct point p1, struct point p2, struct point p3)
{
    double a,b,c,perimeter,area;
    
    printf("Triangle coordinates:\n");
    printPoints(p1, p2, p3);
    
    printf("Side lengths:\n");
    a = findDistance(p1, p2);
    b = findDistance(p2, p3);
    c = findDistance(p1, p3);
    printf("a: %.2lf\n",a);
    printf("b: %.2lf\n",b);
    printf("c: %.2lf\n\n",c);

    perimeter = findPerimeter(a,b,c);
    printf("Perimeter: %.2lf\n\n",perimeter);

    area = findArea(a,b,c);
    printf("Area: %.2lf\n\n",area);
}

int main()
{
    struct point p1 = {0,0};
    struct point p2 = {0,4};
    struct point p3 = {3,0};
    
    findTriangleProperties(p1, p2, p3);
    
    return 0;
}