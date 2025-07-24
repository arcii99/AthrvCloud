//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// function prototypes
float distance(float x1, float y1, float x2, float y2);
float area(float x1, float y1, float x2, float y2, float x3, float y3);

int main()
{
    // point coordinates
    float x1, y1, x2, y2, x3, y3;
    
    // read input
    printf("Enter coordinates of three points: ");
    scanf("%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &x3, &y3);
    
    // calculate area of triangle
    float t_area = area(x1, y1, x2, y2, x3, y3);
    
    // calculate circumference of triangle
    float t_perimeter = distance(x1, y1, x2, y2) + distance(x1, y1, x3, y3) + distance(x2, y2, x3, y3);
    
    // print output
    printf("\nArea of triangle: %f", t_area);
    printf("\nCircumference of triangle: %f", t_perimeter);
    
    return 0;
}

// function to calculate distance between two points
float distance(float x1, float y1, float x2, float y2)
{
    float d = sqrt(pow((x2-x1),2) + pow((y2-y1),2));
    return d;
}

// function to calculate area of triangle
float area(float x1, float y1, float x2, float y2, float x3, float y3)
{
    float a = distance(x1,y1,x2,y2);
    float b = distance(x1,y1,x3,y3);
    float c = distance(x2,y2,x3,y3);
    float s = (a+b+c)/2;
    float t_area = sqrt(s*(s-a)*(s-b)*(s-c));
    return t_area;
}