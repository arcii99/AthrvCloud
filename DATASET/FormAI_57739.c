//FormAI DATASET v1.0 Category: Sudoku solver ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

void print_board(int board[][9]) {
  printf(" -----------------------\n");
  for (int i = 0; i < 9; i++) {
    printf("| ");
    for (int j = 0; j < 9; j++) {
      printf("%d ", board[i][j]);
      if ((j + 1) % 3 == 0) printf("| ");
    }
    printf("\n");
    if ((i + 1) % 3 == 0) printf(" -----------------------\n");
  }
}

int is_valid(int board[][9], int row, int col, int num) {
  for (int i = 0; i < 9; i++) {
    if (board[row][i] == num) return 0;
  }

  for (int j = 0; j < 9; j++) {
    if (board[j][col] == num) return 0;
  }

  int box_row = row - row % 3;
  int box_col = col - col % 3;

  for (int i = box_row; i < box_row + 3; i++) {
    for (int j = box_col; j < box_col + 3; j++) {
      if (board[i][j] == num) return 0;
    }
  }

  return 1;
}

int solve_board(int board[][9]) {
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      if (board[row][col] == 0) {
        for (int num = 1; num <= 9; num++) {
          if (is_valid(board, row, col, num)) {
            board[row][col] = num;
            if (solve_board(board)) {
              return 1;
            } else {
              board[row][col] = 0;
            }
          }
        }
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  int board[9][9] = {
      {0, 0, 0, 0, 0, 0, 0, 8, 0},
      {7, 0, 0, 2, 0, 0, 0, 0, 0},
      {0, 1, 0, 0, 0, 0, 0, 0, 2},
      {0, 0, 9, 0, 0, 0, 0, 0, 0},
      {0, 7, 0, 0, 0, 0, 8, 0, 0},
      {0, 0, 0, 6, 0, 3, 0, 0, 0},
      {0, 0, 0, 0, 1, 0, 0, 0, 0},
      {8, 0, 0, 0, 0, 0, 5, 0, 0},
      {0, 5, 0, 7, 0, 0, 0, 0, 0},
  };

  printf("Original board:\n");
  print_board(board);

  if (solve_board(board)) {
    printf("\nSolved board:\n");
    print_board(board);
  } else {
    printf("No solution\n");
  }

  return 0;
}