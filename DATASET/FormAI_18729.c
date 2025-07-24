//FormAI DATASET v1.0 Category: Dice Roller ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int dice_num, roll_num, score, i, j;

  // seed the random number generator with current time in seconds
  srand(time(NULL));

  // get user input for number of dice and rolls
  printf("How many dice would you like to roll? ");
  scanf("%d", &dice_num);

  printf("How many times would you like to roll the dice? ");
  scanf("%d", &roll_num);

  // roll the dice and calculate total score for each roll
  for (i = 0; i < roll_num; i++) {
    score = 0;
    for (j = 0; j < dice_num; j++) {
      score += rand() % 6 + 1; // generate random number between 1-6 (inclusive) for each dice
    }
    printf("Roll %d: %d\n", i+1, score);
  }

  return 0;
}