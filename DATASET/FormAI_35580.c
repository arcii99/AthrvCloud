//FormAI DATASET v1.0 Category: Arithmetic ; Style: calm
#include<stdio.h>

int main() {
   int num1, num2, sum, diff, prod, quot, rem;  
   
   printf("Enter the first number: ");
   scanf("%d", &num1);
   
   printf("Enter the second number: ");
   scanf("%d", &num2);
   
   sum = num1 + num2;   
   printf("\nSum of %d and %d is %d", num1, num2, sum);
   
   diff = num1 - num2;
   printf("\nDifference of %d and %d is %d", num1, num2, diff);
   
   prod = num1 * num2;
   printf("\nProduct of %d and %d is %d", num1, num2, prod);
   
   quot = num1 / num2;
   printf("\nQuotient of %d and %d is %d", num1, num2, quot);
   
   rem = num1 % num2;   
   printf("\nRemainder of %d and %d is %d\n", num1, num2, rem);
   
   return 0;
}