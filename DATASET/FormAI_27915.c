//FormAI DATASET v1.0 Category: Dice Roller ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 6
int rollDice() {
  return rand() % 6 + 1;
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  int numDice, total = 0;

  // Get the number of dice to roll from the user
  printf("How many dice would you like to roll? ");
  scanf("%d", &numDice);

  // Roll the dice and display the results
  printf("Rolling %d dice...\n", numDice);
  for(int i = 0; i < numDice; i++) {
    int roll = rollDice();
    printf("Dice %d: %d\n", i+1, roll);
    total += roll;
  }

  // Display the total of all the dice rolled
  printf("Total: %d\n", total);

  return 0;
}