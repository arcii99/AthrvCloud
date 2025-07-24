//FormAI DATASET v1.0 Category: Educational ; Style: innovative
#include <stdio.h>

int main() {
  printf("Welcome to the Guessing Game! Please enter a number between 1 and 50:\n");
  int num;
  scanf("%d", &num); // User enters a number

  int guess = 1; // Initialize guess counter to 1
  int min = 1; // Initialize minimum possible number to 1
  int max = 50; // Initialize maximum possible number to 50

  while (guess <= 5 && num != (min+max)/2) { // User has 5 guesses and hasn't found the number
    printf("Is it %d? If so, enter 0. If it's higher, enter 1. If it's lower, enter -1.\n", (min+max)/2); // Guess a number
    int response;
    scanf("%d", &response); // User responds with 0, 1, or -1

    if (response == 0) { // User found the number
      printf("Congratulations! You found the number in %d guesses.\n", guess);
      break;
    }
    else if (response == 1) { // Guess was too low
      min = (min+max)/2 + 1; // Adjust minimum possible number
      guess++; // Increment guess counter
    }
    else if (response == -1) { // Guess was too high
      max = (min+max)/2 - 1; // Adjust maximum possible number
      guess++; // Increment guess counter
    }
    else { // Invalid input
      printf("Invalid input. Please enter 0, 1, or -1.\n");
    }
  }

  if (guess == 6) { // User used up all 5 guesses
    printf("Sorry, you used up all your guesses. The number was %d.\n", num);
  }

  return 0;
}