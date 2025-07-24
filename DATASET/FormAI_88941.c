//FormAI DATASET v1.0 Category: Sudoku solver ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define ROW 9
#define COL 9

void print(int grid[ROW][COL]) {
  printf("-------------------------\n");
  for (int i = 0; i < ROW; i++) {
    printf("| ");
    for (int j = 0; j < COL; j++) {
      printf("%d ", grid[i][j]);
      if ((j + 1) % 3 == 0)
        printf("| ");
    }
    printf("\n");
    if ((i + 1) % 3 == 0)
      printf("-------------------------\n");
  }
}

int isSafe(int grid[ROW][COL], int row, int col, int num) {
  for (int i = 0; i < 9; i++) {
    if (grid[row][i] == num)
      return 0;
    if (grid[i][col] == num)
      return 0;
    if (grid[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
      return 0;
  }
  return 1;
}

int solve(int grid[ROW][COL], int row, int col) {
  if (row == 8 && col == 9) {
    return 1;
  }

  if (col == 9) {
    row++;
    col = 0;
  }

  if (grid[row][col] > 0) {
    return solve(grid, row, col + 1);
  }

  for (int num = 1; num <= 9; num++) {
    if (isSafe(grid, row, col, num)) {
      grid[row][col] = num;
      if (solve(grid, row, col + 1)) {
        return 1;
      }
      grid[row][col] = 0;
    }
  }
  return 0;
}

int main() {
  int grid[ROW][COL] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                        {6, 0, 0, 1, 9, 5, 0, 0, 0},
                        {0, 9, 8, 0, 0, 0, 0, 6, 0},
                        {8, 0, 0, 0, 6, 0, 0, 0, 3},
                        {4, 0, 0, 8, 0, 3, 0, 0, 1},
                        {7, 0, 0, 0, 2, 0, 0, 0, 6},
                        {0, 6, 0, 0, 0, 0, 2, 8, 0},
                        {0, 0, 0, 4, 1, 9, 0, 0, 5},
                        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

  if (solve(grid, 0, 0)) {
    print(grid);
  } else {
    printf("No solution exists!");
  }

  return 0;
}