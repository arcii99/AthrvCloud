//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // initialize random seed
  
  int guess, correct, score = 0, count = 0; // variables for the game
  char choice; // variable to store user's choice to play again
  
  do {
    correct = rand() % 10 + 1; // generate a random number between 1 and 10

    printf("\nGuess a number between 1 and 10: ");
    scanf("%d", &guess); // ask user to guess

    while (guess != correct) { // while guess is incorrect, keep looping
      if (guess < correct) {
        printf("Too low. Guess again: ");
      } else {
        printf("Too high. Guess again: ");
      }
      scanf("%d", &guess);
      count++; // increment the number of guesses
    }

    score += 10 - count; // calculate the score based on the number of guesses
    printf("Congratulations, you guessed it right in %d guesses!\n", count+1);
    printf("Your score is: %d\n", score);

    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &choice); // ask user if they want to play again
    count = 0; // reset the number of guesses for the new game

  } while (choice == 'y' || choice == 'Y');

  printf("Thank you for playing!\n");
  return 0;
}