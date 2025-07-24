//FormAI DATASET v1.0 Category: Math exercise ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>

int main() {
   float radius, area;

   printf("Enter the radius of the circle: ");
   scanf("%f", &radius);

   // Calculate the area using the formula πr^2:
   area = M_PI * pow(radius, 2);

   printf("The area of the circle with radius %.2f is %.2f", radius, area);

   return 0;
}