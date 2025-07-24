//FormAI DATASET v1.0 Category: Table Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int guess, number, num_guesses = 0, max_guesses;

   // get max guesses from user input
   printf("How many guesses do you want? (max is 10): ");
   scanf("%d", &max_guesses);
   while (max_guesses > 10) {
       printf("Please enter a number between 1 and 10: ");
       scanf("%d", &max_guesses);
   }

   // initialize random number generator
   srand(time(0));

   // generate random number
   number = rand() % 100 + 1;

   // game loop
   do {
      printf("\nEnter a guess between 1 and 100: ");
      scanf("%d", &guess);
      num_guesses++;
      if (guess > number) {
         printf("Too high\n");
      }
      else if (guess < number) {
         printf("Too low\n");
      }
      else {
         printf("You win! The number was %d\n", number);
         break;
      }
   } while (num_guesses < max_guesses);

   // if player can't guess in max_guesses, game over
   if (num_guesses == max_guesses) {
      printf("Sorry, you lose. The number was %d\n", number);
   }

   return 0;
}