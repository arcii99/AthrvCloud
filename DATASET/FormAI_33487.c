//FormAI DATASET v1.0 Category: Dice Roller ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rollDice(int faces);

int main() {
  int faces;
  printf("Let's roll some dice!\nHow many faces does the dice have? ");
  scanf("%d", &faces);
  if (faces < 2) {
    printf("Error: You can't have a dice with less than 2 faces.\n");
    return 1;
  }
  printf("How many times would you like to roll the dice? ");
  int rolls;
  scanf("%d", &rolls);
  if (rolls < 1) {
    printf("Error: You must roll the dice at least once.\n");
    return 1;
  }
  printf("Rolling dice with %d faces %d times:\n", faces, rolls);
  srand(time(NULL)); // seed random number generator
  rollDice(faces);
  for (int i = 1; i < rolls; i++) { // roll dice multiple times
    printf("----------------\n");
    rollDice(faces);
  }
  return 0;
}

void rollDice(int faces) {
  int result = rand() % faces + 1;
  if (faces == 2) {
    printf("Coin flip: ");
    if (result == 1) {
      printf("Heads\n");
    } else {
      printf("Tails\n");
    }
  } else {
    printf("Dice roll: %d\n", result);
  }
}