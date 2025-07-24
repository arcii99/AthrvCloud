//FormAI DATASET v1.0 Category: Dice Roller ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int diceValue, totalSum = 0, numOfRolls;
  
  // srand seeds the rand() function with the current time
  srand(time(NULL));
  
  printf("Welcome to the Dice Roller program!\n");
  printf("How many times would you like to roll the dice? ");
  scanf("%d", &numOfRolls);
  
  // Loop through the number of rolls specified and roll the dice
  for (int i = 0; i < numOfRolls; i++) {
    diceValue = rand() % 6 + 1; // Generates a random number between 1 and 6
    totalSum += diceValue; // Add the dice value to the total sum
    
    printf("Roll number %d: You rolled a %d\n", i+1, diceValue);
  }
  
  // Print the total sum and the average value rolled
  printf("\nTotal sum of all rolls: %d\n", totalSum);
  printf("Average value rolled: %.2f\n", (float)totalSum/numOfRolls);
  
  return 0;
}