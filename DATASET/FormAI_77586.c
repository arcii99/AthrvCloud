//FormAI DATASET v1.0 Category: Arithmetic ; Style: complete
#include <stdio.h>

int main() {
   int num1, num2, sum, prod, diff, quo, rem;
   
   printf("Enter two numbers: ");
   scanf("%d %d", &num1, &num2);
   
   // Add numbers
   sum = num1 + num2;
   
   // Multiply numbers
   prod = num1 * num2;
   
   // Find difference
   diff = num1 - num2;
   
   // Find quotient and remainder
   quo = num1 / num2;
   rem = num1 % num2;
   
   // Printing the results
   printf("The sum of %d and %d is %d\n", num1, num2, sum);
   printf("The product of %d and %d is %d\n", num1, num2, prod);
   printf("The difference between %d and %d is %d\n", num1, num2, diff);
   printf("The quotient of %d divided by %d is %d with remainder %d\n", num1, num2, quo, rem);
   
   return 0;
}