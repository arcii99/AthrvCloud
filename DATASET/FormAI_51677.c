//FormAI DATASET v1.0 Category: Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Declare all the variables
  int guess = 0;
  int count = 0;
  int num;

  // Seed the random number generator
  srand(time(NULL));

  // Generate a random number between 1 and 100
  num = rand() % 100 + 1;

  // Print a welcome message
  printf("Welcome to the Happy Number Guessing Game!\n");

  // Loop until the number is guessed
  while (guess != num) {
    // Get the user's guess
    printf("Please enter a guess between 1 and 100: ");
    scanf("%d", &guess);

    // Check if the guess is too low
    if (guess < num) {
      printf("Too low, try again!\n");
    }

    // Check if the guess is too high
    if (guess > num) {
      printf("Too high, try again!\n");
    }

    // Increment the guess count
    count++;
  }

  // Print the congratulations message
  printf("Congratulations, you guessed the number in %d guesses!\n", count);

  return 0;
}