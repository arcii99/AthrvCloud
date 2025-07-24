//FormAI DATASET v1.0 Category: Educational ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed the random number generator with time
  int number = rand() % 100 + 1; // generate a random number between 1 and 100
  int guess, numGuesses = 0;
  
  printf("I'm thinking of a number between 1 and 100... can you guess it?\n");
  do {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    numGuesses++;
    if (guess > number) {
      printf("Too high! Try again.\n");
    } else if (guess < number) {
      printf("Too low! Try again.\n");
    }
  } while (guess != number);
  
  printf("Congratulations! You guessed the number in %d tries.\n", numGuesses);
  return 0;
}