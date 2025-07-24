//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: funny
#include <stdio.h>

int main() {

   char op;
   float num1, num2;

   printf("Welcome to Chuck Norris' Ultra Scientific Calculator!\n\n");
   
   printf("Enter operator (+, -, *, /): ");
   scanf("%c", &op);

   printf("Enter first number: ");
   scanf("%f", &num1);

   printf("Enter second number: ");
   scanf("%f", &num2);

   switch(op) {
      case '+':
         printf("%f + %f = %f\n", num1, num2, num1 + num2);
         break;

      case '-':
         printf("%f - %f = %f\n", num1, num2, num1 - num2);
         break;

      case '*':
         printf("%f * %f = %f\n", num1, num2, num1 * num2);
         break;

      case '/':
         if(num2 == 0) {
            printf("Sorry, Chuck Norris does not divide by zero.\n");
         } else {
            printf("%f / %f = %f\n", num1, num2, num1 / num2);
         }
         break;

      default:
         printf("Invalid operator. Try again!\n");
   }

   return 0;
}