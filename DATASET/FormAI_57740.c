//FormAI DATASET v1.0 Category: Educational ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int guess, number, num_guesses = 0;

  srand(time(0));
  number = rand() % 100 + 1;

  printf("**********************************\n");
  printf("* Welcome to Retro Guessing Game *\n");
  printf("**********************************\n\n");
  
  do {
    printf("Guess a number between 1 and 100: ");
    scanf("%d", &guess);
    num_guesses++;
  
    if (guess > number) {
      printf("Too high!\n\n");
    }
    else if (guess < number) {
      printf("Too low!\n\n");
    }
    else {
      printf("\n**********\n");
      printf("*** You guessed it! ***\n");
      printf("The number was %d\n", number);
      printf("It took you %d guesses.\n", num_guesses);
      printf("**********\n");
    }
  } while (guess != number);
  
  printf("\nThanks for playing Retro Guessing Game!\n");

  return 0;
}