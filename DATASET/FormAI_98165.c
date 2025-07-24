//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int number, guess, attempts=1;
   srand(time(0));
   number = rand()%100 + 1;
   printf("\tWelcome to the Guessing Game!\n\n");
   printf("Guess a number between 1 and 100:\n\n");

   do {
      scanf("%d", &guess);
      if(guess<number) {
         printf("Too low. Try again:\n\n");
         attempts++;
      } else if(guess>number) {
         printf("Too high. Try again:\n\n");
         attempts++;
      } else {
         printf("\nCongratulations! You guessed the number in %d attempts.", attempts);
      }
   } while(guess!=number);

   return 0;
}