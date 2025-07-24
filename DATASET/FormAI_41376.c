//FormAI DATASET v1.0 Category: System administration ; Style: mathematical
#include <stdio.h>

int main() {
   int num1, num2;
   char operation;
   
   // get input
   printf("Enter two numbers: ");
   scanf("%d %d", &num1, &num2);
   
   // get operation
   printf("Enter the operation (+, -, *, /): ");
   scanf(" %c", &operation);
   
   // perform operation
   switch(operation) {
      case '+':
         printf("%d + %d = %d", num1, num2, num1 + num2);
         break;
      case '-':
         printf("%d - %d = %d", num1, num2, num1 - num2);
         break;
      case '*':
         printf("%d * %d = %d", num1, num2, num1 * num2);
         break;
      case '/':
         printf("%d / %d = %d", num1, num2, num1 / num2);
         break;
      default:
         printf("Invalid operation");
   }
   
   return 0;
}