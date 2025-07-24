//FormAI DATASET v1.0 Category: Random ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  printf("Hi there! Let's play a little game with random numbers!\n\n");

  // Get the current time for generating a different seed every time
  srand(time(NULL));

  int max_number;
  printf("What is the maximum number you want to guess? ");
  scanf("%d", &max_number);

  int random_number = rand() % max_number + 1;
  int guess_number;
  int count_guesses = 1;

  printf("\nOk, I have a random number between 1 and %d. Can you guess it?\n", max_number);

  do {
    printf("\nGuess number %d: ", count_guesses);
    scanf("%d", &guess_number);
    
    if (guess_number > random_number) {
      printf("Too high! Try again.\n");
    } else if (guess_number < random_number) {
      printf("Too low! Try again.\n");
    }
    
    count_guesses++;
  } while (guess_number != random_number);

  printf("\nCongratulations! You found the number %d in %d guesses!\n", random_number, count_guesses-1);

  return 0;
}