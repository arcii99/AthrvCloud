//FormAI DATASET v1.0 Category: Scientific ; Style: creative
#include <stdio.h>

int main(void) {
  printf("Welcome to the magical number guessing game!\n");
  printf("I am thinking of a number between 1 and 100. Can you guess it?\n");

  int answer = 42; //the magical number
  int guess;

  //initialize variables for game statistics
  int num_guesses = 0;
  int num_higher = 0;
  int num_lower = 0;

  //begin game loop
  while(1) {
    printf("\nEnter your guess: ");
    scanf("%d", &guess);
    num_guesses++;

    if(guess == answer) {
      printf("You guessed it! The answer was %d! Congratulations!\n", answer);
      printf("It took you %d guesses. You guessed higher %d times and lower %d times.\n", num_guesses, num_higher, num_lower);
      break;
    }
    else if(guess > answer) {
      printf("Sorry! Your guess is too high. Try again!\n");
      num_higher++;
    }
    else {
      printf("Sorry! Your guess is too low. Try again!\n");
      num_lower++;
    }
  }

  return 0;
}