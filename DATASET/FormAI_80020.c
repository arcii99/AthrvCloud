//FormAI DATASET v1.0 Category: Calculator ; Style: enthusiastic
#include <stdio.h>

int main() {

   float num1, num2, result;
   char operator;

   printf("Welcome! Let's do some math!\n");

   printf("Enter an operator (+, -, *, /): ");
   scanf("%c", &operator);

   printf("Enter two numbers separated by a space: ");
   scanf("%f %f", &num1, &num2);

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
         printf("%.2f x %.2f = %.2f", num1, num2, result);
         break;
      case '/':
         if(num2 != 0) {
            result = num1 / num2;
            printf("%.2f / %.2f = %.2f", num1, num2, result);
         } else {
            printf("Error! Division by zero is not allowed.");
         }
         break;
      default:
         printf("Invalid operator! Please enter one of the following operators (+, -, *, /)");
   }

   return 0;
}