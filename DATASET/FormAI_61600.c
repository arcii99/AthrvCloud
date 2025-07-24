//FormAI DATASET v1.0 Category: Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int answer, guess;
  int attempts = 0;

  srand(time(NULL));
  answer = rand() % 100 + 1; // Generate a random number between 1 and 100

  printf("Welcome to the guessing game!\n");
  printf("I'm thinking of a number between 1 and 100.\n");
  printf("Can you guess what it is?\n");

  do {
    printf("Enter a guess: ");
    scanf("%d", &guess);
    
    attempts++;

    if (guess < answer) {
      printf("Too low! Guess again.\n");
    } else if (guess > answer) {
      printf("Too high! Guess again.\n");
    }
  } while (guess != answer); // Keep asking for guesses until the user gets it right

  printf("\nCongratulations! You guessed the number in %d attempts.\n", attempts);

  return 0;
}