//FormAI DATASET v1.0 Category: Dice Roller ; Style: excited
/*
Get ready to roll some dice! This exciting program allows you to roll dice just like a real game! 
You can set the number of dice, number of sides per dice and have your results displayed in a flash! 

So, let's get started!! 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int numDice, numSides, sum = 0;

  printf("Welcome to the Dice Roller program! Let's start rolling!\n");

  // Get the number of dice
  printf("\nHow many dice do you want to roll?: ");
  scanf("%d", &numDice);

  // Get the number of sides per dice
  printf("\nHow many sides does each die have?: ");
  scanf("%d", &numSides);

  // Generate a random number between 1 and the number of sides for each die
  printf("\nRolling %d dice with %d sides each....\n\n", numDice, numSides);
  srand(time(NULL)); // seed the random number generator
  for (int i = 0; i < numDice; i++) {
    int roll = rand() % numSides + 1;
    printf("Die #%d roll: %d\n", i+1, roll);
    sum += roll; // keep track of the total sum of all the rolls
  }

  // Display the total sum of all the rolls
  printf("\nTotal sum of all %d rolls: %d\n", numDice, sum);

  printf("\nThanks for rolling with me! Have a great day!");

  return 0;
}