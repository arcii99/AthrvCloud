//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void print_board(int bingo_board[][COLS]) {
  int i, j;
  printf("\n");
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      printf("%d\t", bingo_board[i][j]);
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL)); // Seed the random number generator
  int bingo_board[ROWS][COLS] = {0}; // Initialize the bingo board

  // Fill up the board with random numbers from 1 to 75
  int i, j, k;
  for (k = 1; k <= 75; k++) {
    i = rand() % ROWS;
    j = rand() % COLS;
    if (bingo_board[i][j] == 0) {
      bingo_board[i][j] = k;
    } else {
      k--;
    }
  }

  // Print the initial bingo board
  printf("Initial Bingo Board:\n");
  print_board(bingo_board);

  // Game loop
  int num;
  int num_calls = 0;
  while (1) {
    // Get a random number from 1 to 75
    num = rand() % 75 + 1;
    printf("\nNumber called: %d\n", num);
    num_calls++;

    // Check if the number called is on the board
    for (i = 0; i < ROWS; i++) {
      for (j = 0; j < COLS; j++) {
        if (bingo_board[i][j] == num) {
          bingo_board[i][j] = 0; // Mark the number as called
        }
      }
    }

    // Print the updated bingo board
    printf("Updated Bingo Board:\n");
    print_board(bingo_board);

    // Check for BINGO
    int bingo_count = 0;
    for (i = 0; i < ROWS; i++) {
      int row_sum = 0;
      int col_sum = 0;
      for (j = 0; j < COLS; j++) {
        row_sum += bingo_board[i][j];
        col_sum += bingo_board[j][i];
      }
      if (row_sum == 0) {
        printf("\nBINGO! Row %d\n", i+1);
        bingo_count++;
      }
      if (col_sum == 0) {
        printf("\nBINGO! Col %d\n", i+1);
        bingo_count++;
      }
    }
    int diag_sum1 = 0; // for diagonal from top-left to bottom right
    int diag_sum2 = 0; // for diagonal from bottom-left to top-right
    for (i = 0; i < ROWS; i++) {
      diag_sum1 += bingo_board[i][i];
      diag_sum2 += bingo_board[i][ROWS-i-1];
    }
    if (diag_sum1 == 0) {
      printf("\nBINGO! Diagonal from top-left to bottom-right\n");
      bingo_count++;
    }
    if (diag_sum2 == 0) {
      printf("\nBINGO! Diagonal from bottom-left to top-right\n");
      bingo_count++;
    }

    // Check if all BINGO's have been achieved
    if (bingo_count == 5) {
      printf("\nCongratulations! You have achieved all 5 BINGOs in %d calls!\n", num_calls);
      break;
    }
  }

  return 0;
}