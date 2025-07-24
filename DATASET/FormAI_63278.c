//FormAI DATASET v1.0 Category: Dice Roller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  int numSides, numDice, i, rollTotal = 0;
  char keepRolling = 'y';

  srand(time(0)); // Seed the random number generator with the current time

  printf("Welcome to the Dice Roller!\n\n");
  
  while (keepRolling == 'y') {

    printf("How many sides do your dice have? (2-20): ");
    scanf("%d", &numSides);
  
    printf("How many dice do you want to roll? (1-10): ");
    scanf("%d", &numDice);
  
    printf("\nRolling %d %d-sided dice...\n\n", numDice, numSides);
  
    for (i = 1; i <= numDice; i++) {
      int roll = rand() % numSides + 1;
      printf("Die %d: %d\n", i, roll);
      rollTotal += roll;
    }

    printf("Total roll: %d\n\n", rollTotal);
  
    rollTotal = 0; // Reset rollTotal for next roll

    printf("Roll again? (y/n): ");
    scanf(" %c", &keepRolling);
    printf("\n");

  }

  return 0;

}