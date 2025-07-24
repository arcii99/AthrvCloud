//FormAI DATASET v1.0 Category: Random ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 100
int getRandomNumber() {
  srand(time(0)); // Setting the seed using the current time
  return rand() % 100 + 1; // Returning a random number between 1 and 100
}

int main() {
  int num = getRandomNumber(); // Generating a random number
  int guess; // Variable to store user's guess
  int tries = 0; // Variable to count the number of tries

  printf("Welcome to the guessing game!\n\n");

  while (guess != num) {
    printf("Guess the number (between 1 and 100): ");
    scanf("%d", &guess); // Taking user's guess as input
    tries++; // Increasing the try count

    if (guess < num) {
      printf("Too low! Try again.\n");
    } else if (guess > num) {
      printf("Too high! Try again.\n");
    } else {
      printf("\n\nCongrats! You guessed the number in %d tries!\n", tries);
    }
  }

  return 0;
}