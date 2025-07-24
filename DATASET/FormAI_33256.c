//FormAI DATASET v1.0 Category: Dice Roller ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int numRolls, numSides, i;
  int total = 0;
  
  srand(time(0)); // Seed the random number generator with the current time
  
  printf("How many rolls? ");
  scanf("%d", &numRolls);
  
  printf("How many sides per die? ");
  scanf("%d", &numSides);
  
  printf("\nRolling %d %d-sided dice...\n\n", numRolls, numSides);
  
  for (i = 0; i < numRolls; i++) {
    int roll = rand() % numSides + 1; // Generate a random number between 1 and numSides
    
    total += roll; // Add the current roll to the total
    
    printf("Roll #%d: %d\n", i+1, roll);
  }
  
  printf("\nTotal: %d\n", total);
  
  return 0;
}