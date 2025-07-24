//FormAI DATASET v1.0 Category: Arithmetic ; Style: romantic
#include <stdio.h>

int main() {
   int num1, num2;
   printf("Enter the first number: ");
   scanf("%d", &num1);
   printf("Enter the second number: ");
   scanf("%d", &num2);
   int sum = num1 + num2;
   int diff = num1 - num2;
   int prod = num1 * num2;
   int quot = num1 / num2;
   printf("\nSum of %d and %d is: %d", num1, num2, sum);
   printf("\nDifference between %d and %d is: %d", num1, num2, diff);
   printf("\nProduct of %d and %d is: %d", num1, num2, prod);
   printf("\nQuotient of %d and %d is: %d", num1, num2, quot);
   return 0;
}