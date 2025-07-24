//FormAI DATASET v1.0 Category: Dice Roller ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num_dice, num_faces;

  // Prompt user for number of dice and number of faces
  printf("How many dice do you want to roll?: ");
  scanf("%d", &num_dice);
  printf("How many faces does each die have?: ");
  scanf("%d", &num_faces);

  // Seed random number generator
  srand(time(0));

  printf("\nRolling %d d%d...\n\n", num_dice, num_faces);

  int total = 0;

  // Roll each dice and print the result
  for(int i = 1; i <= num_dice; i++) {
    int roll = rand() % num_faces + 1;
    printf("Die %d: %d\n", i, roll);
    total += roll;
  }

  printf("\nTotal: %d\n", total);

  return 0;
}