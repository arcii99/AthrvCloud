//FormAI DATASET v1.0 Category: Educational ; Style: authentic
/* This program calculates the area and perimeter of a rectangle */

#include <stdio.h>

int main() {
   float length, width, area, perimeter;
   
   // Ask the user for the dimensions of the rectangle
   printf("Enter the length of the rectangle: ");
   scanf("%f", &length);
   
   printf("Enter the width of the rectangle: ");
   scanf("%f", &width);
   
   // Calculate the area and perimeter of the rectangle
   area = length * width;
   perimeter = 2 * (length + width);
   
   // Output the results
   printf("\n");
   printf("The area of the rectangle is: %.2f\n", area);
   printf("The perimeter of the rectangle is: %.2f\n", perimeter);
   
   return 0;
}