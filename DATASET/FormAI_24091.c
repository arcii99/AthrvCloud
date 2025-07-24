//FormAI DATASET v1.0 Category: Dice Roller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int rolls, sides;
  printf("Enter number of rolls: ");
  scanf("%d", &rolls);
  printf("Enter number of sides: ");
  scanf("%d", &sides);
  srand(time(NULL));
  printf("Rolling %d %d-sided dice...\n", rolls, sides);
  for (int i = 1; i <= rolls; i++) {
    int result = (rand() % sides) + 1;
    printf("Roll %d: %d\n", i, result);
  }
  return 0;
}