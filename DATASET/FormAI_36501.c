//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Initialize the card, with all values initialized to zero
  int card[5][5] = {0};

  // Generate random values for each column
  for (int i = 0; i < 5; i++) {
    // At least one non-zero number per column
    card[rand() % 5][i] = rand() % 15 + 1;

    // Fill the remaining numbers in the column
    for (int j = 0; j < 4; j++) {
      int num;
      do {
        // Generate a random number between 1 and 15
        num = rand() % 15 + 1;
      } while (cardContains(card, num));
      card[j][i] = num;
    }
  }

  // Print the card
  printf("B  I  N  G  O\n");
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%2d ", card[i][j]);
    }
    printf("\n");
  }

  // Generate and print random numbers
  printf("\n\n");
  int nums[75];
  for (int i = 0; i < 75; i++) {
    int num;
    do {
      // Generate a random number between 1 and 75
      num = rand() % 75 + 1;
    } while (contains(nums, i, num));
    nums[i] = num;
    printf("Number: %2d\n", num);

    // Check if number is in the card
    if (cardContains(card, num)) {
      printf("BINGO!\n");
    }
  }

  return 0;
}

int cardContains(int card[][5], int num) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (card[i][j] == num) {
        // Mark number as found by setting it to -1
        card[i][j] = -1;
        return 1;
      }
    }
  }
  return 0;
}

int contains(int nums[], int size, int num) {
  for (int i = 0; i < size; i++) {
    if (nums[i] == num) {
      return 1;
    }
  }
  return 0;
}