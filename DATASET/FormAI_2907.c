//FormAI DATASET v1.0 Category: Dice Roller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i, num, sides, sum = 0;

  printf("Enter the number of dice: ");
  scanf("%d", &num);

  printf("Enter the number of sides per die: ");
  scanf("%d", &sides);

  srand(time(0));

  printf("\nRolling...\n");

  for (i = 0; i < num; i++) {
    int roll = rand() % sides + 1;
    printf("Die %d: %d\n", i+1, roll);
    sum += roll;
  }

  printf("\nTotal: %d\n", sum);

  return 0;
}