//FormAI DATASET v1.0 Category: Scientific ; Style: shocked
#include <stdio.h>
#include <math.h>

int main() {
   int num1, num2, num3;
   float result;

   printf("Enter 3 numbers separated by spaces: ");
   scanf("%d %d %d", &num1, &num2, &num3);

   result = pow(num1, 2) + pow(num2, 3) - sqrt(num3);

   printf("The result is: %f", result);

   return 0;
}