//FormAI DATASET v1.0 Category: Sudoku solver ; Style: irregular
#include <stdio.h>

int board[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                   {6, 0, 0, 1, 9, 5, 0, 0, 0},
                   {0, 9, 8, 0, 0, 0, 0, 6, 0},
                   {8, 0, 0, 0, 6, 0, 0, 0, 3},
                   {4, 0, 0, 8, 0, 3, 0, 0, 1},
                   {7, 0, 0, 0, 2, 0, 0, 0, 6},
                   {0, 6, 0, 0, 0, 0, 2, 8, 0},
                   {0, 0, 0, 4, 1, 9, 0, 0, 5},
                   {0, 0, 0, 0, 8, 0, 0, 7, 9}};

void print_board() {
  int i, j;
  printf("-------------------\n");
  for (i = 0; i < 9; i++) {
    printf("| ");
    for (j = 0; j < 9; j++) {
      printf("%d ", board[i][j]);
      if (j == 2 || j == 5 || j == 8)
        printf("| ");
    }
    printf("\n");
    if (i == 2 || i == 5 || i == 8)
      printf("-------------------\n");
  }
}

int is_valid(int row, int col, int num) {
  int i, j;
  for (i = 0; i < 9; i++) {
    if (board[row][i] == num)
      return 0;
    if (board[i][col] == num)
      return 0;
    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
      return 0;
  }
  return 1;
}

int solve() {
  int row, col, num;

  for (row = 0; row < 9; row++) {
    for (col = 0; col < 9; col++) {
      if (board[row][col] == 0) {
        for (num = 1; num <= 9; num++) {
          if (is_valid(row, col, num)) {
            board[row][col] = num;
            if (solve())
              return 1;
            board[row][col] = 0;
          }
        }
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  printf("Original Sudoku Board\n");
  print_board();
  printf("\nSolved Sudoku Board\n");
  if (solve())
    print_board();
  else
    printf("Invalid Sudoku board\n");

  return 0;
}