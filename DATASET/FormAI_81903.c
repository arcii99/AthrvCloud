//FormAI DATASET v1.0 Category: Math exercise ; Style: accurate
#include <stdio.h>
#include <math.h>

int main() {
   double x1, y1, x2, y2, distance;

   //Prompt the user to enter the first point(x1,y1)      
   printf("Enter the first point (x1,y1):\n");
   scanf("%lf%lf", &x1, &y1);

   //Prompt the user to enter the second point(x2,y2)    
   printf("Enter the second point (x2,y2):\n");
   scanf("%lf%lf", &x2, &y2);

   //Calculate distance using Euclidean Distance Formula
   distance = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));

   printf("The distance between (%.2lf,%.2lf) and (%.2lf,%.2lf) is %.2lf\n", x1, y1, x2, y2, distance);

   return 0;
}