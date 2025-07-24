//FormAI DATASET v1.0 Category: Dice Roller ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(); // function prototype

int main() {
  srand(time(NULL)); // initialize random seed
  int rolls[6] = {0}; // array to keep track of number of times each number was rolled
  
  printf("How many times would you like to roll the dice? ");
  int numRolls;
  scanf("%d", &numRolls);
  
  for (int i = 0; i < numRolls; i++) {
    int roll = rollDice();
    printf("Roll %d: %d\n", i+1, roll);
    rolls[roll-1]++;
  }
  
  printf("\nDice Roll Summary:\n");
  for (int i = 0; i < 6; i++) {
    printf("Number %d was rolled %d times.\n", i+1, rolls[i]);
  }
  
  return 0;
}

int rollDice() {
  return (rand() % 6) + 1; // random integer between 1-6
}