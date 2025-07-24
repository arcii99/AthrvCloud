//FormAI DATASET v1.0 Category: Table Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Welcome message
  printf("Welcome to the C Table Game!\n");

  // Initiate random number generator
  srand(time(NULL));

  // Generate random number between 1 and 100
  int secret_number = rand() % 100 + 1;

  // Initiate counter for number of guesses
  int num_guesses = 0;

  // Loop through guessing process
  while(1) {
    // Prompt user for guess
    printf("Guess the secret number between 1 and 100: ");
    int guess;
    scanf("%d", &guess);

    // Increment number of guesses
    num_guesses++;

    // Check if guess is correct
    if(guess == secret_number) {
      // Congratulate user and tell them how many guesses it took
      printf("Congratulations! You guessed the secret number in %d tries.\n", num_guesses);
      break;
    }
    else {
      // Hint to user if guess is too low or too high
      if(guess < secret_number) {
        printf("Your guess is too low. Try again!\n");
      }
      else {
        printf("Your guess is too high. Try again!\n");
      }
    }
  }

  // End game
  printf("Thanks for playing the C Table Game!");

  return 0;
}