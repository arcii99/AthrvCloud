//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: introspective
/* Let's write a program that allows users to draw geometric shapes and measures their properties. */

#include <stdio.h>
#include <math.h>

int main() {
   int option; // user selection
   
   // display menu
   printf("Welcome to the Geometric Calculator!\n");
   printf("1. Calculate the area of a circle\n");
   printf("2. Calculate the perimeter of a rectangle\n");
   printf("3. Calculate the area of a triangle\n");
   printf("Please enter your selection: ");
   scanf("%d", &option);
   
   // handle user selection
   switch(option) {
      case 1:
         // prompt user for circle radius
         double radius;
         printf("Please enter the radius of the circle: ");
         scanf("%lf", &radius);
         
         // calculate circle area
         double area = M_PI * pow(radius, 2);
         
         // display result
         printf("The area of the circle is: %lf\n", area);
         break;
         
      case 2:
         // prompt user for rectangle dimensions
         double length, width;
         printf("Please enter the length and width of the rectangle: ");
         scanf("%lf %lf", &length, &width);
         
         // calculate rectangle perimeter
         double perimeter = 2 * (length + width);
         
         // display result
         printf("The perimeter of the rectangle is: %lf\n", perimeter);
         break;
         
      case 3:
         // prompt user for triangle dimensions
         double base, height;
         printf("Please enter the base and height of the triangle: ");
         scanf("%lf %lf", &base, &height);
         
         // calculate triangle area
         double triangle_area = 0.5 * base * height;
         
         // display result
         printf("The area of the triangle is: %lf\n", triangle_area);
         break;
         
      default:
         printf("Invalid option selected. Please try again.\n");
   }
   
   return 0;
}