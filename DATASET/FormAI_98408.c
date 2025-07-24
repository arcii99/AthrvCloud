//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int guess, number, tries = 0;
  srand(time(0));
  number = rand() % 100 + 1;
  printf("\nWelcome to the Number Guessing Game!\n\n");
  printf("Guess a number between 1 and 100: ");

  do {
    tries++;
    scanf("%d", &guess);

    if (guess > number) {
      printf("Too high! Try again: ");
    }
    else if (guess < number) {
      printf("Too low! Try again: ");
    }
    else {
      printf("\nCongratulations! You guessed the number in %d tries!\n", tries);
      break;
    }
  } while (1);

  return 0;
}