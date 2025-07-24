//FormAI DATASET v1.0 Category: Dice Roller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); // seed the random number generator with the current time

  int roll_again = 1; // variable to control if we should roll again
  while (roll_again) {
    printf("Rolling the dice...\n");
    int roll1 = rand() % 6 + 1; // generate random number between 1 and 6 for first die
    int roll2 = rand() % 6 + 1; // generate random number between 1 and 6 for second die

    printf("You rolled a %d and a %d!\n", roll1, roll2); // print out the results

    printf("Would you like to roll again? (Enter 1 for yes, 0 for no)"); // ask the user if they want to roll again
    scanf("%d", &roll_again); // read in their response
  }

  printf("Thanks for playing!\n");
  return 0;
}