//FormAI DATASET v1.0 Category: Arithmetic ; Style: active
#include <stdio.h>

int main() {
   int num1, num2, sum, diff, prod, quo, rem; // declaration of variables
   
   printf("Enter the first number: ");
   scanf("%d", &num1); // takes input from user

   printf("Enter the second number: ");
   scanf("%d", &num2); // takes input from user

   sum = num1 + num2; // addition of numbers

   if(num1 > num2) {
       diff = num1 - num2; // subtraction of numbers
   } else {
       diff = num2 - num1;
   }

   prod = num1 * num2; // multiplication of numbers

   if(num2 != 0) {
       quo = num1 / num2; // division of numbers
       rem = num1 % num2; // remainder of numbers
   }

   // output print statements
   printf("Sum of the two numbers is: %d\n", sum);
   printf("Difference between the two numbers is: %d\n", diff);
   printf("Product of the two numbers is: %d\n", prod);

   if(num2 != 0) {
       printf("Quotient when %d is divided by %d is: %d\n", num1, num2, quo);
       printf("Remainder when %d is divided by %d is: %d\n", num1, num2, rem);
   } else {
       printf("Cannot divide by zero!\n");
   }
   return 0;
}