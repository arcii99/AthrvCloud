//FormAI DATASET v1.0 Category: Dice Roller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A function to roll a dice with n number of sides
int rollDice(int n) {
  return rand() % n + 1; // Generate a random number between 1 and n
}

int main() {
  int numSides, numDice, total = 0;
  
  // Seed the random number generator with the current time
  srand(time(0));
  
  // Ask the user for the number of sides on the dice
  printf("Enter the number of sides on the dice: ");
  scanf("%d", &numSides);
  
  // Ask the user for the number of dice to roll
  printf("Enter the number of dice to roll: ");
  scanf("%d", &numDice);
  
  // Roll the dice and add up the total
  for (int i = 0; i < numDice; i++) {
    int roll = rollDice(numSides);
    printf("Dice %d: %d\n", i + 1, roll);
    total += roll;
  }
  
  // Display the total sum of all rolled dice
  printf("Total: %d\n", total);
  
  return 0;
}