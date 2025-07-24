//FormAI DATASET v1.0 Category: Random ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  // initialize random seed
  srand(time(NULL));

  // generate random number
  int random_number = rand() % 100;

  // print instructions
  printf("Guess the secret number between 0-99!\n");

  // initialize variables
  int user_guess;
  int attempt_count = 0;

  // loop until user guesses the number
  while (1) {

    // prompt user for input
    printf("Enter your guess: ");
    scanf("%d", &user_guess);

    // increment attempt count
    attempt_count++;

    // check if guess is correct
    if (user_guess == random_number) {
      printf("Congratulations! You guessed the secret number in %d attempts.\n", attempt_count);
      break;
    }

    // provide feedback on incorrect guess
    if (user_guess < random_number) {
      printf("Too low, try again.\n");
    } else {
      printf("Too high, try again.\n");
    }

  }

  return 0;
}