//FormAI DATASET v1.0 Category: Math exercise ; Style: Ada Lovelace
#include<stdio.h>

int main() {
   float radius, area, perimeter;
   const float PI = 3.14159265;

   printf("Enter the radius of the circle: ");
   scanf("%f", &radius);

   area = PI * radius * radius;
   perimeter = 2 * PI * radius;

   printf("The area of the circle is %f units^2 \n", area);
   printf("The perimeter of the circle is %f units \n", perimeter);

   return 0;
}