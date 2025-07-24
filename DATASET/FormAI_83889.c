//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

int main() {
   float x1, y1, x2, y2, x3, y3;
   float side1, side2, side3;
   float perimeter, s, area;

   // Getting the coordinates of the vertices of a triangle from the user
   printf("Enter the coordinates of the first vertex (x,y): ");
   scanf("%f,%f", &x1, &y1);
   printf("Enter the coordinates of the second vertex (x,y): ");
   scanf("%f,%f", &x2, &y2);
   printf("Enter the coordinates of the third vertex (x,y): ");
   scanf("%f,%f", &x3, &y3);

   // Calculating the length of each side of the triangle
   side1 = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
   side2 = sqrt(pow(x3-x2,2)+pow(y3-y2,2));
   side3 = sqrt(pow(x1-x3,2)+pow(y1-y3,2));

   // Calculating the perimeter and semi-perimeter of the triangle
   perimeter = side1 + side2 + side3;
   s = perimeter / 2;

   // Calculating the area of the triangle using Heron's formula
   area = sqrt(s * (s - side1) * (s - side2) * (s - side3));

   // Outputting the results to the user
   printf("The length of the first side is %.2f\n", side1);
   printf("The length of the second side is %.2f\n", side2);
   printf("The length of the third side is %.2f\n", side3);
   printf("The perimeter of the triangle is %.2f\n", perimeter);
   printf("The area of the triangle is %.2f\n", area);

   return 0;
}