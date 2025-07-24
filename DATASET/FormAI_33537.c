//FormAI DATASET v1.0 Category: Dice Roller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int numDice, numSides, rollCount, total = 0;
  
  printf("Welcome to the Dice Roller!\n");
  
  // Prompt user for number of dice and sides
  printf("How many dice would you like to roll? ");
  scanf("%d", &numDice);
  printf("How many sides should each die have? ");
  scanf("%d", &numSides);
  
  // Prompt user for number of rolls
  printf("How many times would you like to roll the dice? ");
  scanf("%d", &rollCount);
  
  // Seed random number generator
  srand(time(NULL));
  
  // Roll the dice
  for (int i = 0; i < rollCount; i++) {
    int rollTotal = 0;
    printf("Roll %d: ", i+1);
    for (int j = 0; j < numDice; j++) {
      int roll = (rand() % numSides) + 1;
      printf("%d ", roll);
      rollTotal += roll;
    }
    printf("(Total: %d)\n", rollTotal);
    total += rollTotal;
  }
  
  // Print the total result
  printf("Total result for all rolls: %d\n", total);
  
  return 0;
}