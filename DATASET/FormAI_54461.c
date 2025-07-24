//FormAI DATASET v1.0 Category: Math exercise ; Style: immersive
#include <stdio.h>
#include <math.h>

int main() {
   float num1, num2, result;
   char operator;

   printf("Enter the expression to calculate (e.g., 5 + 6):\n");
   scanf("%f %c %f", &num1, &operator, &num2);

   switch (operator) {
      case '+':
         result = num1 + num2;
         printf("Result: %.2f", result);
         break;

      case '-':
         result = num1 - num2;
         printf("Result: %.2f", result);
         break;

      case '*':
         result = num1 * num2;
         printf("Result: %.2f", result);
         break;

      case '/':
         result = num1 / num2;
         printf("Result: %.2f", result);
         break;

      case '^':
         result = pow(num1, num2);
         printf("Result: %.2f", result);
         break;

      default:
         printf("Invalid operator.");
         break;
   }

   return 0;
}