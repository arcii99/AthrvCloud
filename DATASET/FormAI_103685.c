//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int answer, guess, num_guesses = 0;
  char choice;
  
  printf("Welcome to the Number Guessing Game!\n\n");
  printf("I'm thinking of a number between 1 and 100. Can you guess it?\n\n");
  srand(time(0));
  answer = rand() % 100 + 1;
  
  do {
    printf("Make your guess: ");
    scanf("%d", &guess);
    
    if (guess < 1 || guess > 100) {
      printf("Invalid guess, please enter a number between 1 and 100.\n");
    } else if (guess < answer) {
      printf("Too low, try again!\n");
      num_guesses++;
    } else if (guess > answer) {
      printf("Too high, try again!\n");
      num_guesses++;
    } else {
      num_guesses++;
      printf("Congratulations! You guessed the number in %d guesses!\n", num_guesses);
      printf("Would you like to play again? (y/n): ");
      scanf(" %c", &choice);
      if (choice == 'y') {
        printf("\n\n\n");
        num_guesses = 0;
        answer = rand() % 100 + 1;
      }
    }
  } while (choice == 'y');
  
  printf("\nThanks for playing!\n");
  return 0;
}