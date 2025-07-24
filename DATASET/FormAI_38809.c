//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Alan Touring
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main()
{
   int radius;
   printf("Enter radius of circle: ");
   scanf("%d",&radius);

   int x = 0, y = radius;
   int d = 3 - 2 * radius;
   while (x <= y)
   {
      printf("(%d,%d)\n", x, y);
      printf("(%d,%d)\n", -x, y);
      printf("(%d,%d)\n", x, -y);
      printf("(%d,%d)\n", -x, -y);
      printf("(%d,%d)\n", y, x);
      printf("(%d,%d)\n", -y, x);
      printf("(%d,%d)\n", y, -x);
      printf("(%d,%d)\n", -y, -x);

      if (d < 0)
      {
         d = d + 4 * x + 6;
      }
      else
      {
         d = d + 4 * (x - y) + 10;
         y--;
      }
      x++;
   }

   return 0;
}