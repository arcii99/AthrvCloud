//FormAI DATASET v1.0 Category: Arithmetic ; Style: cheerful
#include <stdio.h>

int main() {
   int num1, num2, sum, diff, prod;
   float quotient;

   printf("Hello! Let's do some arithmetic!\n");
   
   // get first number from user
   printf("Please enter the first number: ");
   scanf("%d", &num1);
   
   // get second number from user
   printf("Please enter the second number: ");
   scanf("%d", &num2);
   
   // do the arithmetic
   sum = num1 + num2;
   diff = num1 - num2;
   prod = num1 * num2;
   quotient = (float)num1 / (float)num2;

   // print out the results
   printf("The sum of %d and %d is %d\n", num1, num2, sum);
   printf("The difference between %d and %d is %d\n", num1, num2, diff);
   printf("The product of %d and %d is %d\n", num1, num2, prod);
   printf("%d divided by %d is %.2f\n", num1, num2, quotient);
   
   // be cheerful
   printf("Thanks for doing arithmetic with me! Have a great day!\n");
   
   return 0;
}