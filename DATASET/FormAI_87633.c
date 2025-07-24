//FormAI DATASET v1.0 Category: Math exercise ; Style: Romeo and Juliet
#include <stdio.h>
#include <math.h>

int main()
{
   int x1, y1, x2, y2;
   float distance;

   printf("Enter the coordinates of point 1 (x1, y1): ");
   scanf("%d %d", &x1, &y1);

   printf("Enter the coordinates of point 2 (x2, y2): ");
   scanf("%d %d", &x2, &y2);

   distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

   printf("The distance between points (%d, %d) and (%d, %d) is %.2f units.\n", x1, y1, x2, y2, distance);

   return 0;
}