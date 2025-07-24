//FormAI DATASET v1.0 Category: Dice Roller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  int numRolls;
  printf("Welcome to the C Dice Roller!\n");
  printf("How many times do you want to roll the dice? ");
  scanf("%d", &numRolls);

  srand(time(0)); //initializing random number generator

  int i;
  for (i = 1; i <= numRolls; i++) {
    int diceRoll = rand() % 6 + 1; //generates random number between 1 and 6
    printf("Roll #%d: %d\n", i, diceRoll);
  }

  printf("Thanks for playing!\n");

  return 0;
}