//FormAI DATASET v1.0 Category: Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int mysteryNumber = rand() % 100; // generate a random number between 0 and 99
  int guess;

  printf("Welcome to the Mind-Bending Mystery Number Game\n");
  printf("Your goal is to guess the mystery number between 0 and 99\n\n");

  do {
    printf("Enter your guess (0-99): ");
    scanf("%d", &guess);
    if (guess < mysteryNumber) {
      printf("Your guess is too low\n\n");
    } else if (guess > mysteryNumber) {
      printf("Your guess is too high\n\n");
    } else {
      printf("Congratulations! You guessed the mystery number!\n");
    }
  } while (guess != mysteryNumber);

  printf("\nThanks for playing the Mind-Bending Mystery Number Game\n");
  return 0;
}