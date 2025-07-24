//FormAI DATASET v1.0 Category: Error handling ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int random_num = rand() % 10 + 1;
  int guess;
  printf("Welcome to the Guessing Game!\n");
  printf("I am thinking of a number between 1 and 10.\n");
  printf("Can you guess what it is?\n");
  
  while(1) {
    printf("\nEnter your guess: ");
    if(scanf("%d", &guess) != 1) {
      printf("\nError: You didn't enter a number! Try again.\n");
      fflush(stdin);
      continue;
    }
    if(guess == random_num) {
      printf("Congratulations! You guessed my number!\n");
      break;
    }
    else if(guess < 1 || guess > 10) {
      printf("\nError: Your guess is out of range! Please enter a number between 1 and 10.\n");
      continue;
    }
    else {
      printf("\nSorry, that's not my number... Try again!\n");
      continue;
    }
  }
  return 0;
}