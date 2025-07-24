//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int input, guess, tries = 0;
  srand(time(0));
  int random_num = rand() % 100 + 1;
  printf("***Welcome to Guessing Game!***\n\n");
  printf("Guess a number between 1 and 100: ");
  do {
    scanf("%d", &input);
    tries++;
    if(input > random_num) {
      printf("Too high, try again: ");
    }
    else if(input < random_num) {
      printf("Too low, try again: ");
    }
    else {
      printf("\nCongratulations! You guessed the right number in %d tries.\n", tries);
      break;
    }
  } while(1);
  return 0;
}