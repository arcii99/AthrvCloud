//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: inquisitive
#include <stdio.h>
#include <math.h>

int main() {

   double num1, num2, result;
   char operator;

   printf("Enter an equation (ex. 2 + 3): ");
   scanf("%lf %c %lf", &num1, &operator, &num2);

   switch(operator) {
      case '+':
         result = num1 + num2;
         printf("Result: %lf\n", result);
         break;

      case '-':
         result = num1 - num2;
         printf("Result: %lf\n", result);
         break;

      case '*':
         result = num1 * num2;
         printf("Result: %lf\n", result);
         break;

      case '/':
         if(num2 == 0) {
            printf("Error: Cannot divide by zero.\n");
         } else {
            result = num1 / num2;
            printf("Result: %lf\n", result);
         }
         break;

      case '^':
         result = pow(num1, num2);
         printf("Result: %lf\n", result);
         break;

      case 's':
         result = sin(num1);
         printf("Result: %lf\n", result);
         break;

      case 'c':
         result = cos(num1);
         printf("Result: %lf\n", result);
         break;

      case 't':
         result = tan(num1);
         printf("Result: %lf\n", result);
         break;

      case 'l':
         result = log(num1);
         printf("Result: %lf\n", result);
         break;

      default:
         printf("Error: Invalid operator.\n");
         break;
   }

   return 0;
}