//FormAI DATASET v1.0 Category: Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_game() {
  int num, guess, num_guesses = 0;
  srand(time(0));
  num = rand() % 100 + 1;
  printf("Guess the number between 1 and 100\n");
  do {
    num_guesses++;
    printf("Enter your guess: ");
    scanf("%d", &guess);
    if (guess > num) {
      printf("Too high!\n");
    } else if (guess < num) {
      printf("Too low!\n");
    } else {
      printf("Congratulations, you guessed the number in %d guesses!\n", num_guesses);
      return;
    }
  } while (1);
}

int main() {
  printf("Welcome to the futuristic number guessing game!\n");
  char play_again;
  do {
    play_game();
    printf("Do you want to play again? (y/n) ");
    scanf(" %c", &play_again);
  } while (play_again == 'y' || play_again == 'Y');
  printf("Thanks for playing!\n");
  return 0;
}