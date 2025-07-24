//FormAI DATASET v1.0 Category: Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random number between 1 and 100
int generateNumber() {
   srand(time(0));
   return(rand() % 100 + 1);
}

int main() {
   int hiddenNum = generateNumber(); // call function to generate the random number
   int guess, attempts=10; // initialize variables for user guess and number of attempts
   
   printf("\nWelcome to the Guessing Game!\n");
   printf("You have 10 attempts to guess the secret number between 1 and 100.\n");
   
   // while loop to prompt user for guesses and decrement attempts
   while (attempts > 0) {
      printf("\nAttempts Left: %d\n", attempts);
      printf("Guess the secret number: ");
      scanf("%d", &guess); // get user guess
      
      // validate user guess and provide hint
      if (guess < 1 || guess > 100) {
         printf("Invalid guess! Please guess a number between 1 and 100.\n");
         continue;
      } else if (guess < hiddenNum) {
         printf("Too low! Try again.\n");
      } else if (guess > hiddenNum) {
         printf("Too high! Try again.\n");
      } else {
         printf("\nCongratulations! You have guessed the secret number!\n");
         printf("You used %d attempts to guess the number.\n", 11 - attempts);
         break;
      }
      
      attempts--; // decrement number of attempts
   }
   
   if (attempts == 0) {
      printf("\nSorry, you have used all your attempts.\n");
      printf("The secret number was %d. Better luck next time!\n", hiddenNum);
   }
   
   printf("\nThank you for playing the Guessing Game! Goodbye!\n");
   
   return 0;
}