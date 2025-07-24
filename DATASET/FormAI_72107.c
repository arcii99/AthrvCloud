//FormAI DATASET v1.0 Category: Table Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int mystery_number = rand() % 101; // generates a random number between 0 and 100
  int guesses_left = 10; // each player gets 10 guesses
  int player_number; // the player's guess

  printf("Welcome to the Mystery Number game!\n");
  printf("You have to guess the secret number between 0 and 100.\n");
  printf("You have 10 guesses.\n");

  while (guesses_left > 0) {
    printf("Enter your guess: ");
    scanf("%d", &player_number);

    if (player_number == mystery_number) {
      printf("Congratulations, you solved the mystery!\n");
      return 0;
    } else if (player_number < mystery_number) {
      printf("That's too low, try again.\n");
    } else {
      printf("That's too high, try again.\n");
    }
    guesses_left--;
  }

  printf("Sorry, you have no more guesses left :(\n");
  printf("The mystery number was %d.\n", mystery_number);
  return 0;
}