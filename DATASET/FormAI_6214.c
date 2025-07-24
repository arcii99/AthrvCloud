//FormAI DATASET v1.0 Category: Arithmetic ; Style: single-threaded
#include <stdio.h>

int main() {
   int num1, num2;
   char operand;

   printf("Enter two numbers and an operand (+,-,*,/): ");
   scanf("%d %d %c", &num1, &num2, &operand);

   switch (operand) {
      case '+': printf("%d + %d = %d \n", num1, num2, num1 + num2); break;
      case '-': printf("%d - %d = %d \n", num1, num2, num1 - num2); break;
      case '*': printf("%d * %d = %d \n", num1, num2, num1 * num2); break;
      case '/': 
         if (num2 == 0) {
            printf("Error: Cannot divide by zero!\n");
         } else {
            printf("%d / %d = %.2f \n", num1, num2, (float) num1 / num2); 
         } 
         break;
      default:
         printf("Error: Invalid operator!\n");
         break;
   }

   return 0;
}