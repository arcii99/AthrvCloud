//FormAI DATASET v1.0 Category: Dice Roller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int numRolls = 0;
  int diceSides = 0;
  printf("Welcome to the Dice Roller! Let's roll some dice!\n");
  printf("How many dice rolls would you like to make? ");
  scanf("%d", &numRolls);
  printf("How many sides does the dice have? ");
  scanf("%d", &diceSides);
  printf("\n");

  for(int i = 0; i < numRolls; i++) {
    int roll = rand() % diceSides + 1;
    printf("You rolled a %d!\n", roll);
  }

  printf("\n");
  printf("Thanks for rolling with us! Don't forget to tip your dice dealer!\n");

  return 0;
}