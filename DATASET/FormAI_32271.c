//FormAI DATASET v1.0 Category: Math exercise ; Style: Ken Thompson
#include <stdio.h>
#include <math.h>

int main() {
   float x, y, z, result1, result2, result3;

   printf("Enter x: ");
   scanf("%f", &x);

   printf("\nEnter y: ");
   scanf("%f", &y);

   printf("\nEnter z: ");
   scanf("%f", &z);

   result1 = pow(x, y);
   result2 = sqrt(x*y) + pow(z, 2);
   result3 = fabs(x) + fabs(y) + fabs(z);

   printf("\nResult 1 is: %.2f", result1);
   printf("\nResult 2 is: %.2f", result2);
   printf("\nResult 3 is: %.2f", result3);

   return 0;
}