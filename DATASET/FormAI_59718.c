//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int score = 0, guess, num, num_guesses = 0;
  char play_again = 'y';

  printf("\nWelcome to the Mysterious Number Game!\n");
  
  do {
    srand(time(NULL));
    num = rand() % 100 + 1;
    printf("\nI'm thinking of a number from 1 to 100. Can you guess it?\n");

    do {
      printf("Enter your guess: ");
      scanf("%d", &guess);
      num_guesses++;

      if (guess > num) {
        printf("Too high! Guess again.\n");
      } else if (guess < num) {
        printf("Too low! Guess again.\n");
      } else {
        printf("\nCongratulations, you guessed the mysterious number!\n");
        printf("It took you %d guesses to find it.\n", num_guesses);
        score += 100 - num_guesses;
        printf("Your score is now %d.\n", score);
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &play_again);
        num_guesses = 0;
      }
    } while (guess != num);
    
  } while (play_again == 'y');

  printf("\nThanks for playing the Mysterious Number Game! Your final score is %d.\n", score);
  
  return 0;
}