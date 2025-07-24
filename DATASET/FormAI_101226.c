//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int max_number, guess, user_input, attempt = 1;
  
  printf("Welcome to the guessing game!\n");
  printf("Enter the maximum value for the secret number: ");
  scanf("%d", &max_number);

  // Generate a random number
  srand(time(NULL));
  guess = rand() % max_number + 1;

  do {
    printf("Attempt %d: Enter your guess: ", attempt);
    scanf("%d", &user_input);
    
    if (user_input < guess) {
      printf("Too low! Try again.\n");
    } else if (user_input > guess) {
      printf("Too high! Try again.\n");
    } else {
      printf("Congratulations! You guessed the secret number %d in %d attempts!\n", guess, attempt);
      break;
    }
    
    attempt++;
  } while (user_input != guess);

  return 0;
}