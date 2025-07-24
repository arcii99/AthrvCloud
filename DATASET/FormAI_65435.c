//FormAI DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int num1, num2, operator, result, answer, correct = 0, incorrect = 0;
   time_t t;
   srand((unsigned) time(&t));

   for(int i = 0; i < 10; i++) {
      num1 = rand() % 100;
      num2 = rand() % 100;
      operator = rand() % 4;

      if(operator == 0) {
         printf("What is %d + %d? ", num1, num2);
         result = num1 + num2;
      } else if(operator == 1) {
         printf("What is %d - %d? ", num1, num2);
         result = num1 - num2;
      } else if(operator == 2) {
         printf("What is %d * %d? ", num1, num2);
         result = num1 * num2;
      } else if(operator == 3) {
         printf("What is %d / %d? ", num1, num2);
         result = num1 / num2;
      }

      scanf("%d", &answer);

      if(answer == result) {
         printf("Correct!\n");
         correct++;
      } else {
         printf("Incorrect!\n");
         incorrect++;
      }
   }

   printf("\nYou got %d questions correct and %d questions incorrect.\n", correct, incorrect);
   if(correct >= 7) {
      printf("Congratulations, you passed the arithmetic test!");
   } else {
      printf("Sorry, you did not pass the arithmetic test. Please try again.");
   }

   return 0;
}