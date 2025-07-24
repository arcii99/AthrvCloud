//FormAI DATASET v1.0 Category: Arithmetic ; Style: future-proof
#include <stdio.h>

int main() {
   int num1, num2;
   char operator;

   printf("Enter your First number: ");
   scanf("%d", &num1);
   printf("Enter your Second number: ");
   scanf("%d", &num2);
   printf("Enter Operator (+, -, *, /): ");
   scanf(" %c", &operator);

   switch(operator) {
      case '+':
         printf("%d + %d = %d", num1, num2, num1 + num2);
         break;
      case '-':
         printf("%d - %d = %d", num1, num2, num1 - num2);
         break;
      case '*':
         printf("%d x %d = %d", num1, num2, num1 * num2);
         break;
      case '/':
         if(num2 != 0)
            printf("%d / %d = %.2f", num1, num2, num1 / (float)num2);
         else
            printf("Error: Divide by zero");
         break;
      default:
         printf("Invalid operator");
   }

   return 0;
}