//FormAI DATASET v1.0 Category: Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  
  // Print the title of the game
  printf("=== WELCOME TO THE NUMBER GUESSING GAME! ===\n\n");
  
  // Generate a random number between 1 and 100
  srand(time(NULL));
  int numberToGuess = rand()%100 + 1;
  
  // Initialize player's guess and number of tries
  int playerGuess = 0;
  int numTries = 0;
  
  // Loop until the player guesses the right number
  while (playerGuess != numberToGuess){
    
    // Ask the player to guess a number
    printf("Guess a number between 1 and 100: ");
    scanf("%d", &playerGuess);
    
    // Increase the number of tries
    numTries++;
    
    // Check if the guess is too high or too low
    if (playerGuess > numberToGuess){
      printf("Too high. Guess again!\n");
    } else if (playerGuess < numberToGuess){
      printf("Too low. Guess again!\n");
    }
  }
  
  // Congratulate the player and display the number of tries
  printf("Congratulations! You guessed the number in %d tries.\n", numTries);
  
  return 0;
}