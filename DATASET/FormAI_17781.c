//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Linus Torvalds
#include<stdio.h>

#define PI 3.14159265359

int main() {
   double radius, area;

   printf("Enter the radius of circle: ");
   scanf("%lf", &radius);

   area = PI * radius * radius; 

   printf("Area of circle with radius %lf is %lf\n", radius, area);

   return 0;
}