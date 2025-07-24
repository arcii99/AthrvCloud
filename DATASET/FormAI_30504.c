//FormAI DATASET v1.0 Category: Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num, guess, tries = 0;
  srand(time(0)); //seed random number generator
  num = rand() % 100 + 1; //random number between 1 and 100
  printf("Welcome to the Guessing Game! \n");
  printf("I am thinking of a number between 1 and 100. \n");
  printf("Can you guess the number? \n");

  do {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    tries++;

    if (guess > num) {
      printf("Too high. Guess lower!\n");
    } else if (guess < num) {
      printf("Too low. Guess higher!\n");
    } else {
      printf("\nCongratulations! You guessed the number in %d tries!\n", tries);
      break;
    }
  } while (guess != num);

  return 0;
}