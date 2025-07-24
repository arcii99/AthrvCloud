//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random number between 1 and 100
int generateRandomNumber() {
  srand(time(NULL));  // seed the random number generator
  return rand() % 100 + 1;  // return a random number between 1 and 100
}

int main() {
  int randomNumber = generateRandomNumber();  // generate a random number
  int guess, tries = 0;  // initialize guess and tries
  char decision;  // for user decision
  
  printf("Welcome to the Guessing Game!\n");
  printf("Guess the number between 1 and 100.\n");
  
  do {
    printf("Guess #%d: ", ++tries);  // prompt user for guess
    scanf("%d", &guess);  // read the user's guess
    
    if (guess > randomNumber) {
      printf("Too high!\n");
    } else if (guess < randomNumber) {
      printf("Too low!\n");
    } else {
      printf("Congratulations! You guessed the number in %d tries.\n", tries);
      printf("Do you want to play again? (y/n): ");
      scanf(" %c", &decision);  // read the user's decision
      
      if (decision == 'y' || decision == 'Y') {  // if user wants to play again
        randomNumber = generateRandomNumber();  // generate a new random number
        tries = 0;  // reset the number of tries
        printf("\nAlright! Generating a new number...\n");
      } else {  // if user wants to quit
        printf("\nThanks for playing! Goodbye!\n");
      }
    }
  } while (guess != randomNumber || (decision == 'y' || decision == 'Y'));  // keep guessing until correct answer or user quits
  
  return 0;  // exit the program
}