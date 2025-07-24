//FormAI DATASET v1.0 Category: Arithmetic ; Style: detailed
#include <stdio.h>

int main() {
   int num1, num2, sum, diff, prod, quotient, remainder;
   printf("Enter two integer numbers:\n");
   scanf("%d %d", &num1, &num2);

   sum = num1 + num2;
   diff = num1 - num2;
   prod = num1 * num2;
   quotient = num1 / num2;
   remainder = num1 % num2;

   printf("Sum of %d and %d is : %d\n", num1, num2, sum);
   printf("Difference between %d and %d is : %d\n", num1, num2, diff);
   printf("Product of %d and %d is : %d\n", num1, num2, prod);
   printf("Quotient when %d is divided by %d is : %d\n", num1, num2, quotient);
   printf("Remainder when %d is divided by %d is : %d\n", num1, num2, remainder);

   return 0;
}