//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int guess, number, tries = 0;
  srand(time(0));
  number = rand() % 100 + 1;
  printf("\n\n\tWelcome to the Guessing Game!\n\n");
  printf("Guess a number between 1 and 100: ");
  do {
    scanf("%d", &guess);
    tries++;
    if (guess > number) {
      printf("\nToo high! Guess again: ");
    } else if (guess < number) {
      printf("\nToo low! Guess again: ");
    } else {
      printf("\nCongratulations, you guessed it!\n");
    }
  } while (guess != number);
  printf("\nYou took %d tries to guess the number.\n", tries);
  return 0;
}