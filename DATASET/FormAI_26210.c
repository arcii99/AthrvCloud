//FormAI DATASET v1.0 Category: Calculator ; Style: excited
#include<stdio.h>

int main()
{
   int num1, num2, sum, diff, product, quotient, remainder;
   printf("Enter the first number: ");
   scanf("%d", &num1);
   printf("Enter the second number: ");
   scanf("%d", &num2);
   
   sum = num1 + num2;
   diff = num1 - num2;
   product = num1 * num2;
   quotient = num1 / num2;
   remainder = num1 % num2;
   
   printf("\n\n\t\t*** WELCOME TO EXCITING CALCULATOR ***\n\n\n");
   printf("\t\t  ----------------------------------\n\n");
   printf("\t\t|  The SUM of %d and %d is: %d\n\n", num1, num2, sum);
   printf("\t\t|  The DIFFERENCE of %d and %d is: %d\n\n", num1, num2, diff);
   printf("\t\t|  The PRODUCT of %d and %d is: %d\n\n", num1, num2, product);
   printf("\t\t|  The QUOTIENT of %d and %d is: %d\n\n", num1, num2, quotient);
   printf("\t\t|  The REMAINDER of %d and %d is: %d\n\n", num1, num2, remainder);
   printf("\t\t  ----------------------------------\n\n");
   
   return 0;
}