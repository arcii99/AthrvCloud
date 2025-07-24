//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
   float num1, num2, result;
   char op;

   printf("Welcome to the surrealist scientific calculator!\n");
   printf("Please enter your first number: ");
   scanf("%f", &num1);

   printf("Please enter your operation (+, -, *, /, ^): ");
   scanf(" %c", &op);

   if (op == '^') {
      printf("%f ^ ?\n", num1);
      scanf("%f", &num2);
      result = pow(num1, num2);
   }
   else {
      printf("Please enter your second number: ");
      scanf("%f", &num2);

      switch(op) {
         case '+':
            result = num1 + num2;
            break;
         case '-':
            result = num1 - num2;
            break;
         case '*':
            printf("Now enter a random number between 1 and 10: ");
            float random;
            scanf("%f", &random);
            result = (num1 * num2) / random;
            break;
         case '/':
            printf("Processing...");
            float delay = sqrt(num2);
            for (int i = 0; i < 10000; i++) {
               delay /= 2.0;
            }
            result = num1 / num2;
            break;
         default:
            printf("Invalid operation entered\n");
            exit(0);
      }
   }

   printf("The result is: %f\n", result);
   printf("Thank you for using the surrealist scientific calculator!\n");

   return 0;
}