//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 5  // maximum number of tries for the player
#define MAX_NUMBER 100  // maximum number to guess
#define MIN_NUMBER 1  // minimum number to guess

int main() {
  // seed random number generator
  srand(time(NULL));

  // generate a random number for the player to guess
  int number_to_guess = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;

  // initialize the number of tries and the player's guess
  int tries = 0;
  int guess = 0;

  // welcome the player
  printf("Welcome to the Guessing Game!\n");
  printf("I am thinking of a number between %d and %d, can you guess it?\n", MIN_NUMBER, MAX_NUMBER);

  // loop until the player guesses the correct number or uses up all their tries
  while (tries < MAX_TRIES && guess != number_to_guess) {
    printf("Guess #%d: ", tries+1);
    scanf("%d", &guess);

    // check if the player's guess is too high or too low
    if (guess < number_to_guess) {
      printf("Too low!\n");
    } else if (guess > number_to_guess) {
      printf("Too high!\n");
    } else {  // the player guessed correctly
      printf("Congratulations, you guessed the number in %d tries!\n", tries+1);
    }

    tries++;
  }

  // the player used up all their tries without guessing the correct number
  if (tries == MAX_TRIES && guess != number_to_guess) {
    printf("Sorry, you used up all your tries. The number was %d.\n", number_to_guess);
  }

  return 0;
}