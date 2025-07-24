//FormAI DATASET v1.0 Category: Math exercise ; Style: content
#include <stdio.h>

int main()
{
   int num1, num2, sum, diff, mul, div;

   printf("Enter first number: ");
   scanf("%d", &num1);

   printf("Enter second number: ");
   scanf("%d", &num2);

   sum = num1 + num2;
   diff = num1 - num2;
   mul = num1 * num2;
   div = num1 / num2;

   printf("\nSUM: %d\n", sum);
   printf("DIFFERENCE: %d\n", diff);
   printf("PRODUCT: %d\n", mul);
   printf("QUOTIENT: %d\n", div);

   return 0;
}