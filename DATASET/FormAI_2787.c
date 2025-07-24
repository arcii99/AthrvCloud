//FormAI DATASET v1.0 Category: Dice Roller ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
  int numberOfRolls, diceSides, totalSum = 0;
  int rollCount = 1;
  
  printf("Welcome to the Dice Roller!\n");
  printf("Enter the number of rolls you would like to make: ");
  scanf("%d", &numberOfRolls);
  
  printf("Enter the number of sides on the dice: ");
  scanf("%d", &diceSides);
  
  // Seed the random number generator with the current time 
  srand(time(NULL));
  
  printf("\nRolling the dice...\n\n");
  
  // Roll the dice and generate random numbers
  for(int i = 0; i < numberOfRolls; i++) {
    int rollResult = (rand() % diceSides) + 1;
    printf("Roll %d: %d\n", rollCount, rollResult);
    totalSum += rollResult;
    rollCount++;
  }
  
  // Display the total sum of all rolls
  printf("\nTotal Sum of All Rolls: %d\n", totalSum);
  
  return 0;
}