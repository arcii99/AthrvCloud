//FormAI DATASET v1.0 Category: Math exercise ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   // Set up random seed generator
   srand(time(NULL));

   // Get two random numbers between 1 and 10
   int num1 = rand() % 10 + 1;
   int num2 = rand() % 10 + 1;

   // Multiply the numbers
   int answer = num1 * num2;

   // Print the equation for the user
   printf("What is %d * %d?\n", num1, num2);

   // Get user input
   int userAnswer;
   scanf("%d", &userAnswer);

   // Check if answer is correct and give feedback
   if (userAnswer == answer) {
      printf("Congratulations! You got the correct answer!\n");
   } else {
      printf("Sorry, that is not the correct answer.\n");
      printf("The correct answer is %d.\n", answer);
   }

   return 0;
}