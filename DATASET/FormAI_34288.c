//FormAI DATASET v1.0 Category: Math exercise ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int num1, num2, operator, answer, userAnswer;
   srand(time(0)); // Seed the random function with the current time

   // Generate random numbers and operator
   num1 = rand() % 100;
   num2 = rand() % 100;
   operator = rand() % 4;

   // Determine the answer based on the operator
   switch(operator) {
      case 0: // Addition
         answer = num1 + num2;
         printf("What is %d + %d?\n", num1, num2);
         break;
      case 1: // Subtraction
         answer = num1 - num2;
         printf("What is %d - %d?\n", num1, num2);
         break;
      case 2: // Multiplication
         answer = num1 * num2;
         printf("What is %d * %d?\n", num1, num2);
         break;
      case 3: // Division
         answer = num1 / num2;
         printf("What is %d / %d (answer should be an integer)?\n", num1, num2);
         break;
      default:
         break;
   }

   // Get the user's answer
   scanf("%d", &userAnswer);

   // Check if the user's answer is correct
   if(userAnswer == answer) {
      printf("Congratulations, you are correct!\n");
   } else {
      printf("Sorry, the correct answer is %d.\n", answer);
   }

   return 0;
}