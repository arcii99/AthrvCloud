//FormAI DATASET v1.0 Category: Game ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num, guess, tries = 0;
  srand(time(0)); // Seed for random number generator
  num = rand() % 100 + 1; // Generate random number between 1 and 100

  printf("\n\nWelcome to the Guessing Game!");
  printf("\n\nYou have to guess a number between 1 and 100.");
  printf("\nYou have only 10 tries.");

  do {
    printf("\nEnter your guess: ");
    scanf("%d", &guess);
    tries++;

    if (guess > num) {
      printf("Too high! Try again.\n");
    } 
    else if (guess < num) {
      printf("Too low! Try again.\n");
    } 
    else {
      printf("\nCongratulations! You guessed the number in %d attempts.\n", tries);
    }
  } while (guess != num && tries < 10);

  if (tries == 10) {
    printf("Sorry! You have run out of tries. The number was %d.\n", num);
  }
  return 0;
}