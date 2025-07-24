//FormAI DATASET v1.0 Category: Dice Roller ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int numDice, numSides, roll, sum = 0;
  printf("Enter the number of dice to roll: ");
  scanf("%d", &numDice);
  printf("Enter the number of sides on each die: ");
  scanf("%d", &numSides);
  srand(time(NULL));

  for(int i = 0; i < numDice; i++) {
    roll = rand() % numSides + 1;
    printf("Roll %d: %d\n", i+1, roll);
    sum += roll;
  }

  printf("Total: %d\n", sum);
  return 0;
}