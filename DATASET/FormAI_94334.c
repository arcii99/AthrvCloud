//FormAI DATASET v1.0 Category: Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num, guess, tries = 0;
  srand(time(0));
  num = rand() % 100 + 1;

  printf("\nWelcome to the Number Guessing Game!\n");
  printf("You have to guess a number between 1 and 100 within 5 attempts\n");

  while (tries < 5) {
    printf("\nAttempt %d: ", tries + 1);
    scanf("%d", &guess);

    if (guess == num) {
      printf("\nCongrats! You guessed the number in %d attempts\n", tries + 1);
      return 0;
    } else if (guess < num) {
      printf("Too low!\n");
    } else {
      printf("Too high!\n");
    }

    tries++;
  }

  printf("\nGame over! The number was %d\n", num);

  return 0;
}