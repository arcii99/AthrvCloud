//FormAI DATASET v1.0 Category: Game ; Style: sophisticated
/* A unique C game example program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int number, guess, tries = 0;
  srand(time(0));   // Seed random number generator
  number = rand() % 100 + 1;  // Random number between 1 and 100
  printf("\nWelcome to the Guessing Game!");
  printf("\n\nTry to guess the number between 1 and 100.\n");
  do {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    tries++;
    if (guess > number) {
      printf("Too high! Try again.\n");
    } else if (guess < number) {
      printf("Too low! Try again.\n");
    } else {
      printf("\nCongratulations! You guessed the number in %d tries!\n", tries);
    }
  } while (guess != number);
  return 0;
}