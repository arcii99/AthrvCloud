//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: statistical
#include <stdio.h>

/*
This program calculates the area of a triangle 
given three points using the Shoelace Formula 
and determines if the triangle is acute, right, or obtuse.
*/

int main() {

   // Define variables for the three points
   int x1, y1, x2, y2, x3, y3;
   float area;

   // Take input from user for each point
   printf("Enter the coordinates of Point 1 (x1, y1):\n");
   scanf("%d %d", &x1, &y1);
   printf("Enter the coordinates of Point 2 (x2, y2):\n");
   scanf("%d %d", &x2, &y2);
   printf("Enter the coordinates of Point 3 (x3, y3):\n");
   scanf("%d %d", &x3, &y3);

   // Calculate the area using the Shoelace Formula
   area = 0.5 * abs((x1 * y2 + x2 * y3 + x3 * y1) - (x1 * y3 + x2 * y1 + x3 * y2));

   // Determine the type of triangle based on its angles
   int a = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
   int b = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
   int c = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);

   if (a + b == c || a + c == b || b + c == a) {
      printf("The triangle is a right triangle.\n");
   } else if (a + b < c || a + c < b || b + c < a) {
      printf("The triangle is an obtuse triangle.\n");
   } else {
      printf("The triangle is an acute triangle.\n");
   }

   // Output the area of the triangle
   printf("The area of the triangle is %f.\n", area);

   return 0;
}