//FormAI DATASET v1.0 Category: Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Set up random number generator
  srand(time(NULL));

  // Introduce the game
  printf("Welcome to the Number Guessing Game!\n");
  printf("I have chosen a number between 1 and 100.\n");
  printf("You have 7 tries to guess the number.\n");

  // Generate the random number
  int secretNumber = rand() % 100 + 1;

  // Loop through the game
  for (int i = 1; i <= 7; i++) {
    // Get the user's guess
    int guess;
    printf("Guess #%d: ", i);
    scanf("%d", &guess);

    // Check if the guess is correct
    if (guess == secretNumber) {
      printf("Congratulations! You guessed the number in %d tries.\n", i);
      return 0;
    }

    // Give a hint if the guess is incorrect
    if (guess < secretNumber) {
      printf("Sorry, that's not the number. Hint: it's higher.\n");
    } else {
      printf("Sorry, that's not the number. Hint: it's lower.\n");
    }
  }

  // Game over
  printf("Sorry, you weren't able to guess the number. The number was %d.\n", secretNumber);

  return 0;
}