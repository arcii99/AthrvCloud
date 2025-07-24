//FormAI DATASET v1.0 Category: Arithmetic ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main() {

   int num1, num2;
   char operator;

   printf("Enter a mathematical expression (e.g. 2 + 3): ");

   scanf("%d %c %d", &num1, &operator, &num2);

   if (operator == '+') {
      printf("%d + %d = %d", num1, num2, num1 + num2);
   }
   else if (operator == '-') {
      printf("%d - %d = %d", num1, num2, num1 - num2);
   }
   else if (operator == '*') {
      printf("%d * %d = %d", num1, num2, num1 * num2);
   }
   else if (operator == '/') {
      if (num2 == 0) {
         printf("Error: Division by zero");
      }
      else {
         printf("%d / %d = %d", num1, num2, num1 / num2);
      }
   }
   else if (operator == '%') {
      printf("%d %% %d = %d", num1, num2, num1 % num2);
   }
   else {
      printf("Error: Invalid operator");
   }

   return 0;
}