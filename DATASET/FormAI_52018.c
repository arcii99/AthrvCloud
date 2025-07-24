//FormAI DATASET v1.0 Category: Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int playerScore = 0;
  int computerScore = 0;
  
  // Set up random number generator
  srand(time(NULL));
  
  printf("Welcome to the Dice Game!\n");
  
  // Keep playing until either player reaches a score of 10
  while (playerScore < 10 && computerScore < 10) {
    // Player's turn
    char choice;
    printf("Your turn. Roll the dice? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y') {
      int roll = rand() % 6 + 1;
      printf("You rolled a %d!\n", roll);
      playerScore += roll;
    }
    printf("Your current score is %d.\n", playerScore);
    
    // Computer's turn
    int computerRoll = rand() % 6 + 1;
    printf("Computer rolled a %d!\n", computerRoll);
    computerScore += computerRoll;
    printf("Computer's current score is %d.\n", computerScore);
    
    printf("----------------------------\n");
  }
  
  // Determine winner
  if (playerScore >= 10 && computerScore >= 10) {
    printf("It's a tie!\n");
  } else if (playerScore >= 10) {
    printf("Congratulations! You win!\n");
  } else {
    printf("Sorry, the computer wins.\n");
  }
  
  return 0;
}