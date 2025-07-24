//FormAI DATASET v1.0 Category: Dice Roller ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
  int dice1, dice2;
  int sum = 0;

  srand(time(0)); // Initialize random seed

  printf("Welcome to the Dice Roller Game!\n\n");

  printf("Press enter to start rolling the dice...");
  getchar(); // Wait for user to press enter

  dice1 = (rand() % 6) + 1; // Generate random number from 1 to 6 for dice 1
  dice2 = (rand() % 6) + 1; // Generate random number from 1 to 6 for dice 2
  sum = dice1 + dice2; // Calculate sum of rolls

  printf("You rolled a %d and a %d!\n", dice1, dice2);

  if(sum == 7 || sum == 11) {
    printf("You WIN with a total of %d!\n", sum);
  }
  else if(sum == 2 || sum == 3 || sum == 12) {
    printf("You LOST with a total of %d!\n", sum);
  }
  else {
    printf("You need to roll again to get a total of %d!\n", sum);
    getchar(); // Wait for user to press enter
    dice1 = (rand() % 6) + 1; // Generate random number from 1 to 6 for dice 1
    dice2 = (rand() % 6) + 1; // Generate random number from 1 to 6 for dice 2
    int newSum = dice1 + dice2; // Calculate sum of rolls
    printf("You rolled a %d and a %d!\n", dice1, dice2);
    if(newSum == sum) {
      printf("You WIN with a total of %d!\n", newSum);
    }
    else {
      printf("You LOST with a total of %d!\n", newSum);
    }
  }

  printf("\nThanks for playing the Dice Roller Game!\n");

  return 0;
}