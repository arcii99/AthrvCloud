//FormAI DATASET v1.0 Category: Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num_guesses = 0;
  int max_guesses = 5;
  int number, guess;

  srand(time(0)); // Seed the random number generator
  number = rand() % 100 + 1; // Generate a random number between 1 and 100

  printf("Welcome to the guessing game! I'm thinking of a number between 1 and 100. You have 5 tries to guess it.\n\n");

  while (num_guesses < max_guesses) {
    printf("Guess #%d: ", num_guesses + 1);
    scanf("%d", &guess);

    if (guess == number) {
      printf("Congratulations, you guessed the number in %d tries!\n", num_guesses + 1);
      return 0;
    } else if (guess < number) {
      printf("Too low. ");
    } else {
      printf("Too high. ");
    }

    printf("%d ", max_guesses - num_guesses - 1);
    printf((max_guesses - num_guesses - 1) == 1 ? "guess" : "guesses");
    printf(" left.\n\n");

    num_guesses++;
  }

  printf("Sorry, you ran out of guesses. The number was %d.\n", number);

  return 0;
}