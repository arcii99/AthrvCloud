//FormAI DATASET v1.0 Category: Table Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  int num; // number chosen by player
  int guess; // number guessed by computer
  int tries = 0; // number of attempts

  // Seed the random number generator
  srand(time(0));

  // Get the number from the player
  printf("Please choose a number between 1 and 100: ");
  scanf("%d", &num);

  // Start guessing
  do {
    // Generate a random number between 1 and 100
    guess = rand() % 100 + 1;

    printf("Computer guesses %d\n", guess);
    
    // Increment the number of tries
    tries++;

    // Give feedback to the computer
    if (guess < num) {
      printf("Too low!\n");
    } else if (guess > num) {
      printf("Too high!\n");
    }

  } while (guess != num);

  // The computer guessed the number correctly!
  printf("Computer guessed the number %d in %d tries!", num, tries);

  return 0;
}