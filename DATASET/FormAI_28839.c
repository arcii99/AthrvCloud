//FormAI DATASET v1.0 Category: Dice Roller ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(int num_dice, int sides) {
  int total = 0;
  for (int i = 0; i < num_dice; i++) {
    total += rand() % sides + 1;
  }
  return total;
}

int main() {
  srand(time(NULL));
  int num_dice, sides;
  printf("Enter the number of dice: ");
  scanf("%d", &num_dice);
  printf("Enter the number of sides per die: ");
  scanf("%d", &sides);
  printf("\nRolling %d %d-sided dice...\n\n", num_dice, sides);
  printf("Result: %d\n", roll_dice(num_dice, sides));
  return 0;
}