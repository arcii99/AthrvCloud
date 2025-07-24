//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: peaceful
#include <stdio.h>
#define PI 3.14159265

int main() {
   int radius, sides;
   double area, perimeter, apothem;

   printf("Welcome to the peaceful geometric algorithms program!\n\n");
   printf("Let's calculate the area and aperimeter of a polygon given the radius and number of sides.\n");
   printf("Please enter the radius: ");
   scanf("%d", &radius);
   printf("Please enter the number of sides: ");
   scanf("%d", &sides);

   //calculating the radius of the inscribed circle
   apothem = radius * cos(PI / sides);

  //calculating the area and perimeter using the apothem and radius
   area = (apothem * radius * sides) / 2;
   perimeter = radius * 2 * PI;

   //printing the results
   printf("\nA polygon with radius %d and %d sides has:\n", radius, sides);
   printf("An area of %.2lf square units\n", area);
   printf("A perimeter of %.2lf units\n\n", perimeter);

   printf("Thank you for using this peaceful geometric algorithms program!\n");

   return 0;
}