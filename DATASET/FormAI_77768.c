//FormAI DATASET v1.0 Category: Game ; Style: bold
#include <stdio.h>
#include <stdlib.h>

int main() {
  int secret_number = rand() % 101;
  int guessed_number = -1;
  int tries = 0;

  printf("Welcome to the Guessing Game!\n");
  printf("I am thinking of a number between 0 and 100...\n");

  while (guessed_number != secret_number) {
    printf("Can you guess the number? ");
    scanf("%d", &guessed_number);
    tries++;

    if (guessed_number < secret_number) {
      printf("Too low! Try again.\n");
    } else if (guessed_number > secret_number) {
      printf("Too high! Try again.\n");
    } else {
      printf("Congratulations! You guessed the number in %d attempts!\n", tries);
    }
  }

  return 0;
}