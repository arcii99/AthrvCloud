//FormAI DATASET v1.0 Category: Game ; Style: active
// A fun and interactive game of "Guess the Number"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int guess, num, max_range = 100, attempts = 0;
  
  srand(time(0)); // To seed random number generator
  
  num = (rand() % max_range) + 1; // computer selects a random number between 1 and 100
  
  // Welcome and instructions for user
  printf("Welcome to the game of Guess the Number!\n");
  printf("I have chosen a number between 1 and 100. Guess it!\n");
  
  // Loop until correct guess is made 
  do {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    
    // Checking the guess
    if (guess > num) {
      printf("Too high! Guess again.\n");
    }
    else if (guess < num) {
      printf("Too low! Guess again.\n");
    }
    else {
      printf("Congratulations! You guessed the number in %d attempt(s)!\n", attempts+1);
    }
    
    attempts++; // counting the attempts made by the user
    
  } while (guess != num);
  
  // Displaying the number of attempts made by the user
  printf("It took you %d attempt(s) to guess the correct number. Goodbye!", attempts);
  
  return 0; // program ends
}