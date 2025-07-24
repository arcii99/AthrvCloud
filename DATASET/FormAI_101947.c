//FormAI DATASET v1.0 Category: Calculator ; Style: grateful
#include <stdio.h>

int main() {
   printf("Welcome to the Grateful Calculator!\n");
   printf("Enter two numbers:\n");
   
   int num1, num2;
   scanf("%d%d", &num1, &num2);
   
   printf("Choose an operation: +, -, * or /:\n");
   char op;
   scanf(" %c", &op);
   
   float result;
   if (op == '+') {
      result = num1 + num2;
      printf("The sum of %d and %d is %.2f.\nThank you for using the Grateful Calculator!\n", num1, num2, result);
   } else if (op == '-') {
      result = num1 - num2;
      printf("The difference between %d and %d is %.2f.\nThank you for using the Grateful Calculator!\n", num1, num2, result);
   } else if (op == '*') {
      result = num1 * num2;
      printf("The product of %d and %d is %.2f.\nThank you for using the Grateful Calculator!\n", num1, num2, result);
   } else if (op == '/') {
      if (num2 == 0) {
         printf("Error: Division by zero is undefined.\n");
      } else {
         result = (float) num1 / num2;
         printf("%d divided by %d is %.2f.\nThank you for using the Grateful Calculator!\n", num1, num2, result);
      }
   } else {
      printf("Error: Invalid operation.\n");
   }
   
   return 0;
}