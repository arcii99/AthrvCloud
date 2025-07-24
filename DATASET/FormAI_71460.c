//FormAI DATASET v1.0 Category: Syntax parsing ; Style: peaceful
#include <stdio.h>

int main() {
   int num1, num2;
   char operation;
   
   printf("Enter the first number: ");
   scanf("%d", &num1);
   
   printf("Enter the second number: ");
   scanf("%d", &num2);
   
   printf("Enter the operation (+,-,*,/): ");
   scanf(" %c", &operation);
   
   switch (operation) {
      case '+':
         printf("The result is %d", num1 + num2);
         break;
      case '-':
         printf("The result is %d", num1 - num2);
         break;
      case '*':
         printf("The result is %d", num1 * num2);
         break;
      case '/':
         if (num2 == 0) {
            printf("Cannot divide by zero");
         } else {
            printf("The result is %d", num1 / num2);
         }
         break;
      default:
         printf("Invalid operation");
   }
   
   return 0;
}