//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point
{
    int x;
    int y;
};

// find the distance between two points
float distance(struct Point a, struct Point b)
{
    int xsq = (a.x - b.x) * (a.x - b.x);
    int ysq = (a.y - b.y) * (a.y - b.y);
    return sqrt(xsq + ysq);
}

// find the perimeter of a triangle
float perimeter(struct Point a, struct Point b, struct Point c)
{
    float d1 = distance(a,b);
    float d2 = distance(b,c);
    float d3 = distance(c,a);
    return d1 + d2 + d3;
}

// find the area of a triangle
float area(struct Point a, struct Point b, struct Point c)
{
    float d1 = distance(a,b);
    float d2 = distance(b,c);
    float d3 = distance(c,a);
    float s = (d1 + d2 + d3) / 2;
    return sqrt(s*(s-d1)*(s-d2)*(s-d3));
}

int main()
{
    struct Point a = {0,0};
    struct Point b = {3,0};
    struct Point c = {0,4};
    
    float peri = perimeter(a,b,c);
    float ar = area(a,b,c);
    
    printf("Perimeter of Triangle: %f\n", peri);
    printf("Area of Triangle: %f\n", ar);
    
    return 0;
}