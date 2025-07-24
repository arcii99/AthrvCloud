//FormAI DATASET v1.0 Category: Calculator ; Style: creative
#include <stdio.h>

int main() {
   float num1, num2, result;
   char op;

   printf("Enter the first number: ");
   scanf("%f", &num1);

   printf("Enter the operator (+, -, *, /): ");
   scanf(" %c", &op);

   printf("Enter the second number: ");
   scanf("%f", &num2);

   if(op == '+') {
      result = num1 + num2;
      printf("%.2f + %.2f = %.2f\n", num1, num2, result);
   } else if(op == '-') {
      result = num1 - num2;
      printf("%.2f - %.2f = %.2f\n", num1, num2, result);
   } else if(op == '*') {
      result = num1 * num2;
      printf("%.2f * %.2f = %.2f\n", num1, num2, result);
   } else if(op == '/') {
      if(num2 == 0) {
         printf("Error: Cannot divide by zero!\n");
      } else {
         result = num1 / num2;
         printf("%.2f / %.2f = %.2f\n", num1, num2, result);
      }
   } else {
      printf("Error: Invalid operator entered!\n");
   }

   printf("Thank you for using this calculator!\n");
   return 0;
}