//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define ROWS 5
#define COLS 5
#define MAX_NUM 75

// Function to check if a number is in an array.
int inArray(int num, int *arr, int size) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == num) {
      return 1;
    }
  }
  return 0;
}

int main() {
  // Declare variables
  int nums[ROWS * COLS];
  int called_nums[MAX_NUM] = {0};
  int index = 0;
  int num;

  // Seed random number generator with current time
  srand(time(NULL));

  // Populate nums array with unique random numbers between 1 and 75
  for (int i = 0; i < ROWS * COLS; i++) {
    do {
      num = rand() % MAX_NUM + 1;
    } while (inArray(num, nums, i));
    nums[i] = num;
  }

  // Display the Bingo Card
  printf("  B  I  N  G  O\n");
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      index = i * ROWS + j;
      if (index == 12) {
        printf("    ");
      } else {
        printf(" %2d ", nums[index]);
      }
    }
    printf("\n");
  }

  // Play the game
  printf("\n\nPress any key to begin...");
  getchar();
  system("clear");

  // Call out numbers randomly until someone wins
  printf("  B  I  N  G  O\n");
  while (1) {
    // Generate random number and check if it has already been called
    do {
      num = rand() % MAX_NUM + 1;
    } while (called_nums[num - 1]);
    called_nums[num - 1] = 1;
    printf(" %2d ", num);

    // Check if any rows or columns have all been called
    for (int i = 0; i < ROWS; i++) {
      int row_sum = 0;
      int col_sum = 0;
      for (int j = 0; j < COLS; j++) {
        index = i * ROWS + j;
        if (nums[index] == num) {
          row_sum++;
        }
        if (nums[j * ROWS + i] == num) {
          col_sum++;
        }
      }
      if (row_sum == ROWS || col_sum == COLS) {
        printf("\n\nBINGO! Someone has won!\n");
        return 0;
      }
    }
    getchar();  // wait for user to press key before calling next number
  }

  return 0;
}