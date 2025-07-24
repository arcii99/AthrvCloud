//FormAI DATASET v1.0 Category: Sudoku solver ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 9
#define UNASSIGNED 0

int grid[N][N];

bool findUnassignedLocation(int* row, int* col) {
  for (*row = 0; *row < N; (*row)++) {
    for (*col = 0; *col < N; (*col)++) {
      if (grid[*row][*col] == UNASSIGNED) {
        return true;
      }
    }
  }
  return false;
}

bool usedInRow(int row, int num) {
  for (int col = 0; col < N; col++) {
    if (grid[row][col] == num) {
      return true;
    }
  }
  return false;
}

bool usedInCol(int col, int num) {
  for (int row = 0; row < N; row++) {
    if (grid[row][col] == num) {
      return true;
    }
  }
  return false;
}

bool usedInBox(int boxStartRow, int boxStartCol, int num) {
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      if (grid[row+boxStartRow][col+boxStartCol] == num) {
        return true;
      }
    }
  }
  return false;
}

bool isSafe(int row, int col, int num) {
  return !usedInRow(row, num) &&
         !usedInCol(col, num) &&
         !usedInBox(row - row%3 , col - col%3, num);
}

bool solve() {
  int row, col;
  if (!findUnassignedLocation(&row, &col)) {
    return true;
  }
  for (int num = 1; num <= 9; num++) {
    if (isSafe(row, col, num)) {
      grid[row][col] = num;
      if (solve()) {
        return true;
      }
      grid[row][col] = UNASSIGNED;
    }
  }
  return false;
}

void printGrid() {
  for (int row = 0; row < N; row++) {
    for (int col = 0; col < N; col++) {
      printf("%2d", grid[row][col]);
    }
    printf("\n");
  }
}

int main() {
  printf("Please give nine rows of nine numbers separated by space representing the Sudoku grid:\n");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &grid[i][j]);
    }
  }
  if (solve()) {
    printf("\nSudoku grid successfully solved:\n");
    printGrid();
  } else {
    printf("\nIt is impossible to solve the given Sudoku grid.\n");
  }
  return 0;
}