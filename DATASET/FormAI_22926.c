//FormAI DATASET v1.0 Category: Educational ; Style: brave
#include <stdio.h>

int main() {
   int x, y, sum, product, quotient, remainder;
   printf("Enter your first number: ");
   scanf("%d", &x);
   printf("Enter your second number: ");
   scanf("%d", &y);
   
   sum = x + y;
   product = x * y;
   quotient = x / y;
   remainder = x % y;

   printf("\nSum of %d and %d is %d", x, y, sum);
   printf("\nProduct of %d and %d is %d", x, y, product);
   printf("\nQuotient when %d is divided by %d is %d", x, y, quotient);
   printf("\nRemainder when %d is divided by %d is %d", x, y, remainder);

   return 0;
}