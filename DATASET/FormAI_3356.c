//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* function to find the area of a regular polygon */
void find_area_of_polygon(int sides, float length){
    float area;
    int i;
    float angle = (360.0/sides);
    float apothem = length/(2*tan(180.0/sides));
    float perimeter = sides*length;

    area = (perimeter*apothem)/2;
    printf("\nArea of a %d-sided polygon with length %.2f units is %.2f square units.", sides, length, area);
}

/* function to find the coordinates of the center of a circle given three points */
void find_circle_center(float x1, float y1, float x2, float y2, float x3, float y3){
    float a,b,c,d,e,f,g,h,k,r;
    a = x1 - x2;
    b = y1 - y2;
    c = x1 - x3;
    d = y1 - y3;
    e = ((x1*x1 - x2*x2) + (y1*y1 - y2*y2))/2.0;
    f = ((x1*x1 - x3*x3) + (y1*y1 - y3*y3))/2.0;
    g = (b*f - d*e)/(b*c - a*d);
    h = (c*e - a*f)/(b*c - a*d);
    k = -1*((x1*x1 - x2*x2 + y1*y1 - y2*y2)/(2.0*b) - (x1*x1 - x3*x3 + y1*y1 - y3*y3)/(2.0*d))/(b/d - a/c);
    r = sqrt((x1-k)*(x1-k) + (y1-h)*(y1-h));
    printf("\nCenter of circle is at (%.2f,%.2f) with radius %.2f.", k, h, r);
}

int main(){
    int sides;
    float length;
    float x1, y1, x2, y2, x3, y3;

    /* 1 - Find the area of a regular polygon */
    printf("Enter number of sides of the polygon: ");
    scanf("%d", &sides);
    printf("Enter length of each side: ");
    scanf("%f", &length);
    find_area_of_polygon(sides, length);

    /* 2 - Find the coordinates of the center of a circle given three points */
    printf("\n\nEnter coordinates of three points to find the center of the circle.\n");
    printf("Enter coordinates of first point (x1,y1): ");
    scanf("%f %f", &x1, &y1);
    printf("Enter coordinates of second point (x2,y2): ");
    scanf("%f %f", &x2, &y2);
    printf("Enter coordinates of third point (x3,y3): ");
    scanf("%f %f", &x3, &y3);
    find_circle_center(x1, y1, x2, y2, x3, y3);

    return 0;
}