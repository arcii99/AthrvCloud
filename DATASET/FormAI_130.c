//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Ada Lovelace
#include <stdio.h>

#define N 9
#define UNASSIGNED 0

int rowValidator(int puzzle[N][N], int row, int num) {
  for (int col = 0; col < N; col++) {
    if (puzzle[row][col] == num) {
      return 0;
    }
  }
  return 1;
}

int colValidator(int puzzle[N][N], int col, int num) {
  for (int row = 0; row < N; row++) {
    if (puzzle[row][col] == num) {
      return 0;
    }
  }
  return 1;
}

int subgridValidator(int puzzle[N][N], int subgridStartRow, int subgridStartCol, int num) {
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      if (puzzle[row + subgridStartRow][col + subgridStartCol] == num) {
        return 0;
      }
    }
  }
  return 1;
}

int isSafe(int puzzle[N][N], int row, int col, int num) {
  return rowValidator(puzzle, row, num) &&
         colValidator(puzzle, col, num) &&
         subgridValidator(puzzle, row - row % 3, col - col % 3, num);
}

void printPuzzle(int puzzle[N][N]) {
  for (int row = 0; row < N; row++) {
    for (int col = 0; col < N; col++) {
      printf("%d ", puzzle[row][col]);
    }
    printf("\n");
  }
}

int findUnassignedLocation(int puzzle[N][N], int* row, int* col) {
  for (*row = 0; *row < N; (*row)++) {
    for (*col = 0; *col < N; (*col)++) {
      if (puzzle[*row][*col] == UNASSIGNED) {
        return 1;
      }
    }
  }
  return 0;
}

int solvePuzzle(int puzzle[N][N]) {
  int row, col;

  if (!findUnassignedLocation(puzzle, &row, &col)) {
    return 1;
  }

  for (int num = 1; num <= 9; num++) {
    if (isSafe(puzzle, row, col, num)) {
      puzzle[row][col] = num;

      if (solvePuzzle(puzzle)) {
        return 1;
      }

      puzzle[row][col] = UNASSIGNED;
    }
  }

  return 0;
}

int main() {
  int puzzle[N][N] = { {7, 8, 0, 4, 0, 0, 1, 2, 0},
                       {6, 0, 0, 0, 7, 5, 0, 0, 9},
                       {0, 0, 0, 6, 0, 1, 0, 7, 8},
                       {0, 0, 7, 0, 4, 0, 2, 6, 0},
                       {0, 0, 1, 0, 5, 0, 9, 3, 0},
                       {9, 0, 4, 0, 6, 0, 0, 0, 5},
                       {0, 7, 0, 3, 0, 0, 0, 1, 2},
                       {1, 2, 0, 0, 0, 7, 4, 0, 0},
                       {0, 4, 9, 2, 0, 6, 0, 0, 7} };

  if (solvePuzzle(puzzle)) {
    printPuzzle(puzzle);
  }
  else {
    printf("No solution found");
  }

  return 0;
}