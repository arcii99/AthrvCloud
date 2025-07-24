//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: shocked
#include <stdio.h>
#include <math.h>

int main() {
   char operator;
   double num1, num2, result;
   
   printf("Welcome to my Scientific Calculator!\n");
   printf("Please enter an operator (+, -, *, /, s, p, r, c, l): ");
   scanf("%c", &operator);

   switch(operator) {
      case '+':
         printf("Please enter first number: ");
         scanf("%lf", &num1);
         printf("Please enter second number: ");
         scanf("%lf", &num2);
         result = num1 + num2;
         printf("The result is: %.2lf", result);
         break;

      case '-':
         printf("Please enter first number: ");
         scanf("%lf", &num1);
         printf("Please enter second number: ");
         scanf("%lf", &num2);
         result = num1 - num2;
         printf("The result is: %.2lf", result);
         break;

      case '*':
         printf("Please enter first number: ");
         scanf("%lf", &num1);
         printf("Please enter second number: ");
         scanf("%lf", &num2);
         result = num1 * num2;
         printf("The result is: %.2lf", result);
         break;

      case '/':
         printf("Please enter first number: ");
         scanf("%lf", &num1);
         printf("Please enter second number: ");
         scanf("%lf", &num2);
         if (num2 == 0) {
            printf("Error: Division by zero is undefined.");
         }
         else {
            result = num1 / num2;
            printf("The result is: %.2lf", result);
         }
         break;

      case 's':
         printf("Please enter a number: ");
         scanf("%lf", &num1);
         result = sin(num1);
         printf("The sine of %lf is: %.2lf", num1, result);
         break;

      case 'p':
         printf("Please enter a number: ");
         scanf("%lf", &num1);
         result = pow(num1,2);
         printf("%lf raised to 2 is: %.2lf", num1, result);
         break;

      case 'r':
         printf("Please enter a number: ");
         scanf("%lf", &num1);
         result = sqrt(num1);
         printf("The square root of %lf is: %.2lf", num1, result);
         break;

      case 'c':
         printf("Please enter a number: ");
         scanf("%lf", &num1);
         result = cos(num1);
         printf("The cosine of %lf is: %.2lf", num1, result);
         break;

      case 'l':
         printf("Please enter a number: ");
         scanf("%lf", &num1);
         result = log10(num1);
         printf("The base-10 logarithm of %lf is: %.2lf", num1, result);
         break;

      default:
         printf("Error: Invalid operator");
   }

   return 0;
}