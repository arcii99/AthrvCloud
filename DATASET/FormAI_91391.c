//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // initialize variables
  int answer, guess, num_guesses = 0;
  srand(time(NULL));
  answer = rand() % 100 + 1;

  printf("\n");
  printf("Welcome to the Guessing Game!\n");
  printf("\n");

  // loop for guessing
  while (guess != answer) {
    printf("Enter your guess (between 1 and 100): ");
    scanf("%d", &guess);
    num_guesses++;

    if (guess < answer) {
      printf("Too low!\n");
    } else if (guess > answer) {
      printf("Too high!\n");
    } else {
      printf("Congratulations, you guessed it right in %d attempts!\n", num_guesses);
    }
  }

  return 0;
}