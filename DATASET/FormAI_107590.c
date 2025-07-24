//FormAI DATASET v1.0 Category: Game ; Style: introspective
// This is an introspective C program that generates a game of "Guess the Number"
// The program randomly generates a number between 1 and 100, inclusive, and prompts the user to guess it
// The user has a maximum of 10 tries to guess the number correctly
// After each guess, the program tells the user whether the guess is too high, too low, or correct
// Once the user has guessed the number correctly, the program displays the number of tries it took the user to guess the number

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int num_to_guess, guess, num_guesses_left = 10;
  srand(time(0)); // Seed the random number generator
  num_to_guess = rand() % 100 + 1; // Generate a number between 1 and 100 inclusive
  printf("*************************************\n");
  printf("** Welcome to the Guess the Number **\n");
  printf("*************************************\n\n");
  printf("I'm thinking of a number between 1 and 100 inclusive. You have 10 tries to guess it.\n\n");

  while (num_guesses_left > 0) {
    printf("You have %d guesses left.\n", num_guesses_left);
    printf("Enter your guess: ");
    scanf("%d", &guess);
    if (guess == num_to_guess) {
      printf("Congratulations! You guessed the number in %d tries!\n", (10 - num_guesses_left) + 1); // Add 1 to account for the correct guess
      return 0;
    } else if (guess < num_to_guess) {
      printf("Your guess is too low.\n");
      num_guesses_left--;
    } else {
      printf("Your guess is too high.\n");
      num_guesses_left--;
    }
  }

  printf("Sorry, you ran out of guesses. The number I was thinking of was %d.\n", num_to_guess);
  return 0;
}