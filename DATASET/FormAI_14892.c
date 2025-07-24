//FormAI DATASET v1.0 Category: Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a random number */
int generateRandomNumber(int limit) {
  srand(time(NULL));  // Seed the random number generator with current time
  return rand() % limit;  // Return a random number between 0 and the limit
}

/* Game function */
void game() {
  int limit = 20;  // Maximum number to guess
  int randomNumber = generateRandomNumber(limit);  // Generate a random number between 0 and limit
  int guess = -1;  // Initialize the guess to an invalid value

  printf("I am thinking of a number between 0 and %d. Can you guess what it is?\n", limit);

  while (guess != randomNumber) {
    printf("Enter your guess: ");
    scanf("%d", &guess);

    if (guess < randomNumber) {
      printf("Your guess is too low. Try again.\n");
    } else if (guess > randomNumber) {
      printf("Your guess is too high. Try again.\n");
    } else {
      printf("Congratulations! You guessed the number correctly.\n");
    }
  }
}

/* Main function */
int main() {
  char playAgain = 'y';

  while (playAgain == 'y' || playAgain == 'Y') {
    game();

    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &playAgain);
  }

  printf("Thanks for playing!\n");
 
  return 0;
}