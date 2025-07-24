//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
  float x1, y1, x2, y2, x3, y3;
  float m1, m2;
  float ma, mb, md, p, s, a, b, c;

  printf("Enter the coordinates of the first point (x1, y1): ");
  scanf("%f %f", &x1, &y1);

  printf("Enter the coordinates of the second point (x2, y2): ");
  scanf("%f %f", &x2, &y2);

  printf("Enter the coordinates of the third point (x3, y3): ");
  scanf("%f %f", &x3, &y3);
    //finding slope of line between points 1 and 2
    m1 = (y2 - y1) / (x2 - x1);

    //finding slope of line between points 2 and 3
    m2 = (y3 - y2) / (x3 - x2);

    //finding midpoints of lines between points 1 and 2, and points 2 and 3
    ma = (x1 + x2) / 2;
    mb = (y1 + y2) / 2;
    md = (x2 + x3) / 2;

    //finding perpendicular slopes to lines between points 1-2 and 2-3
    p = -1 / m1;
    s = -1 / m2;

    //finding intersection point of the two perpendicular bisectors
    a = mb - (ma * p);
    b = md - (md * s);
    float xi = (b - a) / (p - s);
    float yi = (p * xi) + a;

    //finding distances between the midpoint and intersection point
    float dist1 = sqrt(pow((xi - ma), 2) + pow((yi - mb), 2));
    float dist2 = sqrt(pow((xi - md), 2) + pow((yi - (y2 + y3) / 2), 2));

    //finding the length of the side between points 1 and 2
    float side1 = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

    //finding the length of the side between points 2 and 3
    float side2 = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));

    //finding the length of the side between points 1 and 3
    float side3 = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));

    //finding the area of the triangle using Heron's formula
    float s1 = (side1 + side2 + side3) / 2; //Semi-perimeter of the triangle
    float area = sqrt(s1 * (s1 - side1) * (s1 - side2) * (s1 - side3)); 

    //checking if the triangle is equilateral, isosceles or scalene
    if(side1 == side2 && side2 == side3) {
        printf("The triangle is equilateral.\n");
    } else if(side1 == side2 || side2 == side3 || side1 == side3) {
        printf("The triangle is isosceles.\n");
    } else {
        printf("The triangle is scalene.\n");
    }

    //checking if the intersection point is inside or outside the triangle
    if(dist1 <= area && dist2 <= area){
        printf("\nThe intersection point (%.2f, %.2f) is inside the triangle.\n", xi, yi);
    } else {
        printf("\nThe intersection point (%.2f, %.2f) is outside the triangle.\n", xi, yi);
    }

    return 0;
}