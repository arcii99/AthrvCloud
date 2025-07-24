//FormAI DATASET v1.0 Category: Educational ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num, guess, tries = 0;
  
  srand(time(NULL)); // seed the random number generator
  num = rand() % 100 + 1; // pick a random number between 1 and 100
  
  printf("\nWelcome to the Guessing Game!\n");
  
  do {
    printf("\nEnter your guess (between 1 and 100): ");
    scanf("%d", &guess);
    
    tries++; // increment the number of tries
    
    if (guess > num) {
      printf("Too high! Try again.\n");
    } else if (guess < num) {
      printf("Too low! Try again.\n");
    }
  } while (guess != num);
  
  printf("\nCongratulations, you guessed it!\n");
  printf("Number of tries: %d\n", tries);
  
  return 0;
}