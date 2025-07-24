//FormAI DATASET v1.0 Category: Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

   // initialize random seed
   srand(time(0));

   // generate random number between 1 and 100
   int randomNumber = rand() % 100 + 1;
   int guess;

   // display welcome message and instructions
   printf("Welcome to the Guessing Game!\n");
   printf("I am thinking of a number between 1 and 100.\n");
   printf("Can you guess what it is?\n");

   // loop until correct guess is made
   do {
      // prompt for guess
      printf("Enter your guess: ");
      scanf("%d", &guess);

      // check if guess is correct
      if (guess == randomNumber) {
         printf("Congratulations! You guessed the number!\n");
      }
      // check if guess is too low
      else if (guess < randomNumber) {
         printf("Too low. Try again.\n");
      }
      // guess must be too high
      else {
         printf("Too high. Try again.\n");
      }
   } while (guess != randomNumber);

   return 0;
}