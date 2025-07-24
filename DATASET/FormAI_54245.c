//FormAI DATASET v1.0 Category: Dice Roller ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i, diceRoll;
  char ans;
  
  do {
    srand(time(NULL)); // seed for random number generation
    
    printf("Rolling the dice...\n");
    diceRoll = rand() % 6 + 1; // generates a random number between 1 and 6
    
    printf("\nYou rolled a %d!\n", diceRoll);
    
    printf("\nWould you like to roll again? (y/n): ");
    scanf(" %c", &ans); // allows user to continue or quit
  } while(ans == 'y' || ans == 'Y');
  
  printf("\nThanks for playing!\n");
  return 0;
}