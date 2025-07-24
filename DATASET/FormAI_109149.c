//FormAI DATASET v1.0 Category: Table Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* C Table Game */

int main() {
   int number, guess, attempts = 0;
   srand(time(0));
   number = rand() % 100 + 1; // generate random number between 1 and 100
   printf("\nWelcome to the C Table Game!\n\n");
   printf("Guess the number between 1 and 100:\n");

   do {
      scanf("%d", &guess);
      attempts++;

      if(guess > number)
         printf("\nLower!\n");
      else if(guess < number)
         printf("\nHigher!\n");
      else // found the number
         printf("\nCongratulations! You guessed the number in %d attempts!\n", attempts);
   } while(guess != number);

   return 0;
}