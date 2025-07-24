//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
   double num1, num2, result;
   char operator;

   printf("Enter an operator (+, -, *, /, ^, !, %%) and two numbers: ");
   scanf("%c %lf %lf", &operator, &num1, &num2);

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
         if (num2 == 0) {
            printf("Error: Division by zero");
            exit(0);
         }
         result = num1 / num2;
         printf("%.2lf / %.2lf = %.2lf", num1, num2, result);
         break;

      case '^':
         result = pow(num1, num2);
         printf("%.2lf ^ %.2lf = %.2lf", num1, num2, result);
         break;

      case '!':
         result = 1;
         for (int i = 1; i <= num1; i++) {
           result *= i;
         }
         printf("%.2lf! = %.2lf", num1, result);
         break;

      case '%':
         result = fmod(num1, num2);
         printf("%.2lf %% %.2lf = %.2lf", num1, num2, result);
         break;

      default:
         printf("Invalid operator");
         break;
   }

   return 0;
}