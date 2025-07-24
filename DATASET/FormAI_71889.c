//FormAI DATASET v1.0 Category: Educational ; Style: lively
#include <stdio.h>

int main() {
  printf("Welcome to the Guessing Game!\n");
  printf("I'm thinking of a number between 1 and 100. Can you guess what it is?\n");

  int answer = 42;
  int guess = 0;
  int tries = 0;

  while (guess != answer) {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    tries++;

    if (guess > answer) {
      printf("Too high! Guess again.\n");
    } else if (guess < answer) {
      printf("Too low! Guess again.\n");
    } else {
      printf("You got it! Congrats!\n");
      printf("It took you %d tries.\n", tries);
    }
  }

  return 0;
}