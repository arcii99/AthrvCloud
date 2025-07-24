//FormAI DATASET v1.0 Category: Calculator ; Style: synchronous
#include <stdio.h>

int main() {
   char operator;
   double num1, num2, result;

   // take input from user
   printf("Enter an operator (+, -, *, /): ");
   scanf("%c", &operator);

   printf("Enter two numbers: ");
   scanf("%lf %lf", &num1, &num2);

   // perform operations based on operator input
   switch(operator) {
      case '+':
         result = num1 + num2;
         printf("%.2lf + %.2lf = %.2lf", num1, num2, result);
         break;

      case '-':
         result = num1 - num2;
         printf("%.2lf - %.2lf = %.2lf", num1, num2, result);
         break;

      case '*':
         result = num1 * num2;
         printf("%.2lf * %.2lf = %.2lf", num1, num2, result);
         break;

      case '/':
         if(num2 == 0) {
            printf("Error: division by zero");
         }
         else {
            result = num1 / num2;
            printf("%.2lf / %.2lf = %.2lf", num1, num2, result);
         }
         break;

      default:
         printf("Error: invalid operator");
   }

   return 0;
}