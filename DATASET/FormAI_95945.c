//FormAI DATASET v1.0 Category: Calculator ; Style: content
/* This program is a calculator that can perform the four basic arithmetic operations: addition, subtraction, multiplication, and division.
   It prompts the user to enter two numbers and an operator, then displays the result of the operation.*/

#include <stdio.h>

int main() {

   float num1, num2, result;
   char operator;

   printf("Enter a number: ");
   scanf("%f", &num1);

   printf("Enter an operator (+, -, *, /): ");
   scanf(" %c", &operator);

   printf("Enter another number: ");
   scanf("%f", &num2);

   switch(operator) {
      case '+':
         result = num1 + num2;
         printf("%.2f + %.2f = %.2f", num1, num2, result);
         break;

      case '-':
         result = num1 - num2;
         printf("%.2f - %.2f = %.2f", num1, num2, result);
         break;

      case '*':
         result = num1 * num2;
         printf("%.2f * %.2f = %.2f", num1, num2, result);
         break;

      case '/':
         if(num2 != 0) {
            result = num1 / num2;
            printf("%.2f / %.2f = %.2f", num1, num2, result);
         } else {
            printf("Error: division by zero");
         }
         break;

      default:
         printf("Error: invalid operator");
   }

   return 0;
}