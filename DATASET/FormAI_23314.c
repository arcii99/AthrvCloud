//FormAI DATASET v1.0 Category: Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int guess, number, num_guesses=0;

  printf("I'm thinking of a number between 1 and 100. Try to guess it!\n");
  srand(time(NULL)); //initialize random seed

  number = rand() % 100 + 1; //generate random number between 1 and 100

  do {
    printf("Guess: ");
    scanf("%d", &guess); //get user's guess

    if (guess > number) {
      printf("Too high! Try again.\n");
    } else if (guess < number) {
      printf("Too low! Try again.\n");
    }

    num_guesses++; //increment number of guesses
  } while (guess != number);

  printf("Congratulations, you guessed the number in %d guesses!\n", num_guesses);

  return 0;
}