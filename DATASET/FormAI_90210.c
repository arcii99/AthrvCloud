//FormAI DATASET v1.0 Category: Dice Roller ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num_of_dices, dice_sides, sum = 0;
  printf("Enter the number of dices to roll: ");
  scanf("%d", &num_of_dices);
  printf("\nEnter the number of sides for the dice: ");
  scanf("%d", &dice_sides);

  // sets the seed for random number generation
  srand(time(NULL));

  // rolls the dices and calculates the total value
  printf("\nRolling the dices...\n\n");
  for (int i = 1; i <= num_of_dices; i++) {
    int dice_value = rand() % dice_sides + 1;
    printf("Dice[%d] = %d\n", i, dice_value);
    sum += dice_value;
  }

  // prints the total value
  printf("\nTotal value = %d\n", sum);
  return 0;
}