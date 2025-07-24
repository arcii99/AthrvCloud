//FormAI DATASET v1.0 Category: Table Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed the random number generator
  
  printf("Welcome to the C Table Game!\n");
  printf("You will roll two dice. If the sum is greater than or equal to 7, you win!\n");
  
  char playAgain = 'y';
  int wins = 0;
  int losses = 0;
  
  while (playAgain == 'y') {
    int die1 = rand() % 6 + 1; // roll first die
    int die2 = rand() % 6 + 1; // roll second die
    
    printf("You rolled a %d and a %d.\n", die1, die2);
    
    int sum = die1 + die2;
    
    if (sum >= 7) {
      printf("Congratulations! You win!\n");
      wins++;
    } else {
      printf("Sorry, you lose.\n");
      losses++;
    }
    
    printf("Wins: %d  Losses: %d\n", wins, losses);
    
    printf("Would you like to play again? (y/n)\n");
    scanf(" %c", &playAgain);
  }
  
  printf("Thanks for playing the C Table Game!\n");
  
  return 0;
}