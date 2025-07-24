//FormAI DATASET v1.0 Category: Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int guess;
  int number;
  int tries = 0;
  
  srand(time(0)); //seed random number generator
  number = rand() % 100 + 1; //random number between 1 and 100
  
  printf("Welcome to the Number Guessing Game!\n");
  printf("I am thinking of a number between 1 and 100...\n");
  
  do {
    printf("Enter your guess (1-100): ");
    scanf("%d", &guess);
    tries++;
    
    if (guess > number) {
      printf("Too high! Try again.\n");
    } else if (guess < number) {
      printf("Too low! Try again.\n");
    } else {
      printf("Congratulations! You guessed the number in %d tries.\n", tries);
    }
  } while (guess != number);
  
  return 0;
}