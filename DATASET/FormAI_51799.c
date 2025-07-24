//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: funny
#include <stdio.h>

int main() {
   int num1, num2;
   char operator;

   printf("Welcome to the Super Duper Scientific Calculator! \n\n");

   printf("Please enter the first number: ");
   scanf("%d",&num1);

   printf("Please enter the second number: ");
   scanf("%d",&num2);

   printf("Please enter the operator (+, -, *, /): ");
   scanf(" %c",&operator);

   switch(operator) {
      case '+':
         printf("Result: %d + %d = %d", num1, num2, num1 + num2);
         break;

      case '-':
         printf("Result: %d - %d = %d", num1, num2, num1 - num2);
         break;

      case '*':
         printf("Result: %d * %d = %d", num1, num2, num1 * num2);
         break;

      case '/':
         if(num2 == 0) {
            printf("You can't divide by zero! Try again.\n");
         } else {
            printf("Result: %d / %d = %d", num1, num2, num1 / num2);
         }
         break;

      default:
         printf("Invalid operator. Please try again.\n");
   }
   printf("\n\nThank you for using the Super Duper Scientific Calculator!\n");
   return 0;
}