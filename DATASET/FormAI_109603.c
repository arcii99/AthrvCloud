//FormAI DATASET v1.0 Category: Dice Roller ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int dices, sides, sum = 0;
  int *rolls;

  printf("Enter the number of dices: ");
  scanf("%d", &dices);
  printf("Enter the number of sides: ");
  scanf("%d", &sides);

  rolls = malloc(dices * sizeof(int));

  // Set the seed for the random number generator based on time
  srand(time(NULL));

  printf("Rolling %d dices with %d sides:\n", dices, sides);

  for(int i = 0; i < dices; i++) {
    // Generate a random number between 1 and sides
    int roll = rand() % sides + 1;
    
    // Add the roll to the sum and store it in the rolls array
    sum += roll;
    rolls[i] = roll;
  }

  printf("\nResults:");
  for(int i = 0; i < dices; i++) {
    printf("\nDice %d: %d", i+1, rolls[i]);
  }
  printf("\nTotal: %d\n", sum);

  free(rolls);

  return 0;
}