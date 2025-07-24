//FormAI DATASET v1.0 Category: Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int number, guess, tries=0;
  srand(time(0)); // generates random number based on current time
  number = rand() % 100 + 1; // generates a random number between 1 and 100
  printf("Welcome to the Number Guessing Game!\n");
  printf("I am thinking of a number between 1 and 100...\n");
  do {
    printf("Guess the number: ");
    scanf("%d", &guess);
    tries++;
    if (guess > number) {
      printf("Too high! Try again.\n");
    } else if (guess < number) {
      printf("Too low! Try again.\n");
    } else {
      printf("Congratulations! You guessed the number in %d tries.\n", tries);
      break;
    }
  } while (1);
  return 0;
}