//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: surrealist
#include <stdio.h>
#include <math.h>

int main()
{
   float side1, side2, hypotenuse;
   printf("Enter the length of one of the sides: ");
   scanf("%f", &side1);
   printf("Enter the length of the other side: ");
   scanf("%f", &side2);

   hypotenuse = sqrt(pow(side1,2) + pow(side2,2));
   printf("The hypotenuse is: %f\n", hypotenuse);

   float circle_x, circle_y, radius;
   printf("Enter the x-coordinate of the center of the circle: ");
   scanf("%f", &circle_x);
   printf("Enter the y-coordinate of the center of the circle: ");
   scanf("%f", &circle_y);
   printf("Enter the radius of the circle: ");
   scanf("%f", &radius);

   float point_x, point_y, distance;
   printf("Enter the x-coordinate of a point: ");
   scanf("%f", &point_x);
   printf("Enter the y-coordinate of a point: ");
   scanf("%f", &point_y);

   distance = sqrt(pow(point_x - circle_x,2) + pow(point_y - circle_y,2));
   if(distance <= radius)
      printf("The point is inside the circle.\n");
   else
      printf("The point is outside the circle.\n");

   return 0;
}