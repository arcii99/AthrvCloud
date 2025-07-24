//FormAI DATASET v1.0 Category: Funny ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));   // initialize random seed

  int guess = rand() % 100;     // generate random number in range 0-99
  int count = 0;
  int input;

  printf("Welcome to the guessing game! I am thinking of a number between 0 and 99. You have 10 tries to guess it.\n");

  do {
    printf("Guess #%d: ", count+1);
    scanf("%d", &input);

    if(input == guess) {
      printf("Congratulations, you guessed it in %d tries!\n", count+1);
      return 0;
    }
    else if(input < guess) {
      printf("Sorry, my number is higher.\n");
    }
    else if(input > guess) {
      printf("Sorry, my number is lower.\n");
    }

    count++;
  } while(count < 10);

  printf("Sorry, you did not guess my number. It was %d.\n", guess);
  return 0;
}