//FormAI DATASET v1.0 Category: Arithmetic ; Style: future-proof
#include <stdio.h>

int main() {
   // Declare variables
   int num1, num2, sum, diff, prod, quo, rem;

   // Get user input
   printf("Enter two integers: ");
   scanf("%d %d", &num1, &num2);

   // Perform arithmetic operations
   sum = num1 + num2;
   diff = num1 - num2;
   prod = num1 * num2;
   quo = num1 / num2;
   rem = num1 % num2;

   // Display the result
   printf("\nArithmetic Operations on %d and %d:\n\n", num1, num2);
   printf("Sum: %d\n", sum);
   printf("Difference: %d\n", diff);
   printf("Product: %d\n", prod);
   printf("Quotient: %d\n", quo);
   printf("Remainder: %d\n", rem);

   return 0;
}