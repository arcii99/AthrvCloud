//FormAI DATASET v1.0 Category: Dice Roller ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int dice, sides, i, total;
  srand(time(NULL));

  printf("Enter the number of dice to roll: ");
  scanf("%d", &dice);

  printf("Enter the number of sides on each die: ");
  scanf("%d", &sides);

  total = 0;
  printf("\nRolling %d dice with %d sides each...\n", dice, sides);
  for (i = 0; i < dice; i++) {
    int roll = rand() % sides + 1;
    printf("Die %d: %d\n", i+1, roll);
    total += roll;
  }

  printf("\nTotal: %d\n", total);

  return 0;
}