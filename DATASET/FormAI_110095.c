//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

int main() {
   // Declare variables
   float x1, y1, x2, y2, x3, y3;
   float a, b, c, s, area;
   
   // Ask user for input
   printf("Enter the coordinates of the first point (x1, y1): ");
   scanf("%f %f", &x1, &y1);
   printf("Enter the coordinates of the second point (x2, y2): ");
   scanf("%f %f", &x2, &y2);
   printf("Enter the coordinates of the third point (x3, y3): ");
   scanf("%f %f", &x3, &y3);
   
   // Calculate the length of each side
   a = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
   b = sqrt(pow(x3-x2, 2) + pow(y3-y2, 2));
   c = sqrt(pow(x3-x1, 2) + pow(y3-y1, 2));
   
   // Calculate the semi-perimeter
   s = (a + b + c) / 2;
   
   // Calculate the area using Heron's formula
   area = sqrt(s*(s-a)*(s-b)*(s-c));
   
   // Print out the area
   printf("The area of the triangle is: %f\n", area);
   
   return 0;
}