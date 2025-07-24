//FormAI DATASET v1.0 Category: Random ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  int diceRoll1, diceRoll2;
  srand(time(NULL)); // Seed the random number generator with the current time

  printf("Let's roll some dice!\n");

  // Roll the first dice
  printf("Rolling the first dice...\n");
  diceRoll1 = rand() % 6 + 1; // Generate a random number between 1 and 6
  printf("The first dice roll result is: %d\n", diceRoll1);

  // Roll the second dice
  printf("Rolling the second dice...\n");
  diceRoll2 = rand() % 6 + 1; // Generate a random number between 1 and 6
  printf("The second dice roll result is: %d\n", diceRoll2);

  // Calculate the total
  int total = diceRoll1 + diceRoll2;
  printf("The total is: %d\n", total);

  // Check for a winning combination
  if (total == 7 || total == 11) {
    printf("Congratulations! You won!\n");
  } else if (total == 2 || total == 3 || total == 12) {
    printf("Sorry, you lost!\n");
  } else {
    printf("You didn't win or lose, please roll again!\n");
  }

  return 0;
}