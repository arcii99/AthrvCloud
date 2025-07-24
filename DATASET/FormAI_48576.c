//FormAI DATASET v1.0 Category: Dice Roller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL)); // Seed for generating random numbers

  int numSides, numDice, numRolls;
  printf("Welcome to the Dice Roller Program!\n\n");

  // Get user input for number of sides on the dice
  printf("How many sides are on the dice? ");
  scanf("%d", &numSides);

  // Get user input for number of dice to roll
  printf("How many dice would you like to roll? ");
  scanf("%d", &numDice);

  // Get user input for number of times to roll the dice
  printf("How many times would you like to roll the dice? ");
  scanf("%d", &numRolls);

  int totalRolls = numDice * numRolls; // Total number of rolls needed
  int rolls[totalRolls]; // Array to store all the rolls
  int index = 0; // Counter variable for array index

  // Loop through each roll needed and generate a random number for each dice
  for (int i = 0; i < numRolls; i++) {
    printf("\nRoll %d:\n", i+1);
    for (int j = 0; j < numDice; j++) {
      int roll = rand() % numSides + 1; // Generate random number between 1 and numSides
      printf("Dice %d: %d\n", j+1, roll);
      rolls[index] = roll; // Store the roll in the array
      index++;
    }
  }

  // Calculate and print the total sum of all the rolls
  int sum = 0;
  for (int i = 0; i < totalRolls; i++) {
    sum += rolls[i];
  }
  printf("\nTotal sum of all rolls: %d\n", sum);

  return 0;
}