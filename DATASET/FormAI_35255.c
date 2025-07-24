//FormAI DATASET v1.0 Category: Arithmetic ; Style: detailed
#include <stdio.h>

int main() {
   int num1, num2, sum, diff, product, quotient, remainder;
   
   printf("Enter two integers: ");
   scanf("%d %d", &num1, &num2);

   // performing basic arithmetic operations
   sum = num1 + num2;
   diff = num1 - num2;
   product = num1 * num2;
   quotient = num1 / num2;
   remainder = num1 % num2;
   
   // printing the results
   printf("Sum: %d\n", sum);
   printf("Difference: %d\n", diff);
   printf("Product: %d\n", product);
   printf("Quotient: %d\n", quotient);
   printf("Remainder: %d\n", remainder);
   
   return 0;
}