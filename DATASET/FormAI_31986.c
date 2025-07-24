//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand((unsigned) time(NULL)); // initialize random number generator
   int guess, random_num, tries = 0;

   printf("Welcome to the Guessing Game!\n");
   printf("You have five tries to guess the number between 1 to 10\n");
   random_num = rand() % 10 + 1; // generate random number between 1 to 10

   do {
      printf("Guess a number: ");
      scanf("%d", &guess);
      tries++;

      if (guess > random_num) {
         printf("Too high! Try again.\n");
      } else if (guess < random_num) {
         printf("Too low! Try again.\n");
      } else {
         printf("Congratulations! You guessed the number in %d tries!\n", tries);
         return 0;
      }
   } while(tries < 5);

   printf("Sorry, you have exceeded the maximum number of tries. The number was %d.\n", random_num);
   return 0;
}