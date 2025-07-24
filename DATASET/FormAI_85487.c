//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // initialize random seed
  srand(time(NULL));

  int number_to_guess = rand() % 100 + 1;
  int guess_count = 0;
  int guess;

  printf("Welcome to the Number Guessing Game!\n");
  printf("I'm thinking of a number between 1 and 100.\n");

  while (1) {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    guess_count++;

    // player guessed correctly
    if (guess == number_to_guess) {
      printf("Congratulations, you guessed it in %d tries!\n", guess_count);
      break;
    }
    // player guessed too high
    else if (guess > number_to_guess) {
      printf("Too high! Guess again.\n");
    }
    // player guessed too low
    else {
      printf("Too low! Guess again.\n");
    }
  }

  return 0;
}