//FormAI DATASET v1.0 Category: Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int guess, num, tries = 0;
   srand(time(0)); // seeds the random number generator with the current time
   num = rand() % 100 + 1; // generates number between 1 and 100
   
   printf("Welcome to Guess the Number!\n");
   printf("I'm thinking of a number between 1 and 100.\n");
   
   // loops until user guesses the correct number
   while (guess != num) {
      printf("Guess the number: ");
      scanf("%d", &guess);
      tries++;

      // if guess is too high
      if (guess > num) {
         printf("Too high! Guess again.\n");
      }
      // if guess is too low
      else if (guess < num) {
         printf("Too low! Guess again.\n");
      }
   }
   
   // displays number of tries it took to guess correctly
   printf("Congratulations! You guessed the number in %d tries.", tries);

   return 0;
}