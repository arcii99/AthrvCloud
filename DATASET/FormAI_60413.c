//FormAI DATASET v1.0 Category: Random ; Style: lively
// Welcome to this exciting program where we'll be generating random numbers!
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Let's set the seed for our random number generator to the current time
  srand(time(0));

  printf("Generating random numbers:\n");

  for (int i=0; i<10; i++) {
    // We'll generate a random number between 1 and 100 and print it out
    int random_number = rand() % 100 + 1;
    printf("%d\n", random_number);
  }

  printf("\nLet's now simulate a dice roll:\n");

  for (int i=0; i<5; i++) {
    // We'll generate a random number between 1 and 6 and print it out as our dice roll
    int dice_roll = rand() % 6 + 1;
    printf("Dice roll #%d: %d\n", i+1, dice_roll);
  }

  // Do you want to know if it's your lucky day? Let's generate a random number and find out!
  int lucky_number = rand() % 20 + 1; // We'll generate a number between 1 and 20
  if (lucky_number > 10) {
    printf("\nCongratulations, today is your lucky day! Your lucky number is %d\n", lucky_number);
  } else {
    printf("\nSorry, today is not your lucky day. Your lucky number is %d\n", lucky_number);
  }

  return 0;
}