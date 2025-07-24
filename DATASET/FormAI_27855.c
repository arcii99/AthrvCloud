//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: innovative
#include <stdio.h>
#include <math.h>

/* This program demonstrates the use of geometric algorithms to calculate the area
   and perimeter of a triangle */

int main() {

   double x1,x2,x3,y1,y2,y3;
   double a,b,c,s,area,perimeter;

   printf("Enter coordinates of first point: ");
   scanf("%lf %lf", &x1, &y1);

   printf("Enter coordinates of second point: ");
   scanf("%lf %lf", &x2, &y2);

   printf("Enter coordinates of third point: ");
   scanf("%lf %lf", &x3, &y3);

   a = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
   b = sqrt(pow(x3-x2,2)+pow(y3-y2,2));
   c = sqrt(pow(x3-x1,2)+pow(y3-y1,2));
   s = (a+b+c)/2;

   area = sqrt(s*(s-a)*(s-b)*(s-c));
   perimeter = a+b+c;

   printf("The area of the triangle is %lf\n", area);
   printf("The perimeter of the triangle is %lf\n", perimeter);

   return 0;
}