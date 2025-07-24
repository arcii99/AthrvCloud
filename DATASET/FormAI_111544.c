//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>

int main() {
   float a, b, c; // lengths of the sides of the triangle
   float s; // semiperimeter
   float area; // area of the triangle

   printf("Enter the lengths of the sides of the triangle:\n");
   scanf("%f%f%f", &a, &b, &c);

   // Calculate the semiperimeter of the triangle
   s = (a + b + c) / 2;

   // Calculate the area of the triangle using Heron's formula
   area = sqrt(s * (s - a) * (s - b) * (s - c));

   // Print the area of the triangle
   printf("The area of the triangle is: %f", area);

   return 0;
}