//FormAI DATASET v1.0 Category: Math exercise ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int num1, num2, answer, user_answer;
   int correct = 0, wrong = 0;
   char choice;

   // Seed the random number generator
   srand(time(NULL)); 

   printf("-- Math Quiz --\n\n");

   do {
      // Generate two random numbers between 0 and 10
      num1 = rand() % 11;
      num2 = rand() % 11;

      // Ask the user to solve the math problem
      printf("What is %d + %d? ", num1, num2);
      scanf("%d", &user_answer);

      // Compute the correct answer
      answer = num1 + num2;

      // Check the user's answer
      if (user_answer == answer) {
         printf("Correct!\n");
         correct++;
      }
      else {
         printf("Wrong! The answer is %d.\n", answer);
         wrong++;
      }

      // Ask the user if they want to continue
      printf("\nDo you want to continue? (y/n) ");
      scanf(" %c", &choice);

   } while (choice == 'y' || choice == 'Y');

   // Print the final results
   printf("\nYou got %d correct answers and %d wrong answers.\n", correct, wrong);

   return 0;
}