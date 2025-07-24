//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: single-threaded
#include<stdio.h>

// function to calculate the area of a triangle
float areaOfTriangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
    float area = 0.5 * ((x1*(y2-y3)) + (x2*(y3-y1)) + (x3*(y1-y2)));
    return area;
}

// function to check if a point lies inside a triangle
int pointInsideTriangle(float x1, float y1, float x2, float y2, float x3, float y3, float px, float py)
{
    float A = areaOfTriangle(x1, y1, x2, y2, x3, y3);
    float A1 = areaOfTriangle(px, py, x2, y2, x3, y3);
    float A2 = areaOfTriangle(x1, y1, px, py, x3, y3);
    float A3 = areaOfTriangle(x1, y1, x2, y2, px, py);
    if (A == A1 + A2 + A3)
        return 1;
    else
        return 0;
}

int main()
{
    // coordinates of the triangle
    float x1 = 0, y1 = 0, x2 = 10, y2 = 0, x3 = 5, y3 = 10;
    // coordinate of the point to be checked
    float px = 4, py = 3;

    if (pointInsideTriangle(x1, y1, x2, y2, x3, y3, px, py))
        printf("The point lies inside the triangle");
    else
        printf("The point lies outside the triangle");

    return 0;
}