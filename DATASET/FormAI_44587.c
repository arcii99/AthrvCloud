//FormAI DATASET v1.0 Category: Dice Roller ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rollDice(int*);

int main() {
  srand(time(NULL));  // Initialize random number generator

  int dice[2];
  printf("Enter 'r' to roll the dice, or 'q' to quit.\n");

  while (1) {  // Loop endlessly
    char choice;
    scanf("%c", &choice);

    if (choice == 'r') {
      rollDice(dice);
      printf("You rolled %d and %d!\n", dice[0], dice[1]);
    }
    else if (choice == 'q') {
      printf("Goodbye!\n");
      break;  // Exit loop
    }
    else {
      printf("Invalid choice. Enter 'r' to roll or 'q' to quit.\n");
    }
    getchar();  // Clear input buffer
  }

  return 0;  // Exit program
}

void rollDice(int *arr) {
  arr[0] = rand() % 6 + 1;  // Generate random number between 1 and 6
  arr[1] = rand() % 6 + 1;
}