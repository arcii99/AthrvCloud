//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846

int main()
{
   int i, numPoints, count = 0;
   float x, y, radius;
   
   printf("Enter the radius of the circle: ");
   scanf("%f", &radius);
   printf("Enter the number of random points to generate: ");
   scanf("%d", &numPoints);

   for (i = 0; i < numPoints; i++)
   {
      x = (float) rand()/RAND_MAX*2*radius - radius;
      y = (float) rand()/RAND_MAX*2*radius - radius;
      
      if (sqrt(x*x + y*y) <= radius)
      {
         printf("(%.2f,%.2f) is inside the circle.\n",x,y);
         count++;
      }
      else
      {
         printf("(%.2f,%.2f) is outside the circle.\n",x,y);
      }
   }
   
   printf("\nOut of %d random points, %d lie inside the circle.",numPoints,count);
   printf("The area of the circle is %.2f square units.",PI*radius*radius);
   
   return 0;
}