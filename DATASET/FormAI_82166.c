//FormAI DATASET v1.0 Category: Random ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num, guess, tries = 0;
  srand(time(0));
  num = rand() % 100 + 1;

  printf("\n\nWelcome to the random number guessing game!\n");
  printf("I have a number between 1 to 100, can you guess it?\n");

  do {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    tries++;

    if (guess > num) {
      printf("Ha! My number is lower than %d. Guess again!\n", guess);
    }
    else if (guess < num) {
      printf("Lol! My number is higher than %d. Keep guessing!\n", guess);
    }
    else {
      printf("\nCongratulations! You guessed my number in %d tries!\n", tries);
      break;
    }
  } while (guess != num);

  printf("\nThanks for playing! Run the program again to play another round.\n");

  return 0;
}