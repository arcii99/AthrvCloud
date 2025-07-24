//FormAI DATASET v1.0 Category: Educational ; Style: all-encompassing
/* A program that generates a random number within a range 
and prompts the user to guess the number*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int guess, number, count = 0;
  srand(time(0)); //seed for random number generation

  printf("\nWelcome to the Number Guessing Game!\n");
  printf("\nI am thinking of a number between 1 and 100.\n");
  number = rand() % 100 + 1; //random number between 1-100

  do {
    printf("\n Guess the number: ");
    scanf("%d", &guess);
    count++; //keep track of number of guesses

    if (guess > number) {
      printf("Too high! Try again.\n");
    } else if (guess < number) {
      printf("Too low! Try again.\n");
    } else {
      printf("\nCongratulations, you guessed the number in %d tries!\n", count);
      printf("\nThe number was: %d\n\n", number);
    }
  } while (guess != number);

  return 0;
}