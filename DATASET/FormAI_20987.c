//FormAI DATASET v1.0 Category: Sudoku solver ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

typedef struct {
  int row, col;
} Position;

Position findEmptyCell(int puzzle[SIZE][SIZE]) {
  for (int row = 0; row < SIZE; row++) {
    for (int col = 0; col < SIZE; col++) {
      if (puzzle[row][col] == 0) {
        Position pos = { row, col };
        return pos;
      }
    }
  }
  Position pos = { -1, -1 };
  return pos;
}

int isValid(int puzzle[SIZE][SIZE], Position pos, int num) {
  for (int i = 0; i < SIZE; i++) {
    if (puzzle[pos.row][i] == num || puzzle[i][pos.col] == num) {
      return 0;
    }
  }

  int rowStart = (pos.row / 3) * 3;
  int colStart = (pos.col / 3) * 3;

  for (int row = rowStart; row < rowStart + 3; row++) {
    for (int col = colStart; col < colStart + 3; col++) {
      if (puzzle[row][col] == num) {
        return 0;
      }
    }
  }

  return 1;
}

int solveSudoku(int puzzle[SIZE][SIZE]) {
  Position pos = findEmptyCell(puzzle);
  
  if (pos.row == -1) {
    return 1;
  }

  for (int num = 1; num <= SIZE; num++) {
    if (isValid(puzzle, pos, num)) {
      puzzle[pos.row][pos.col] = num;

      if (solveSudoku(puzzle)) {
        return 1;
      }

      puzzle[pos.row][pos.col] = 0;
    }
  }

  return 0;
}

void printPuzzle(int puzzle[SIZE][SIZE]) {
  printf("---------------------\n");
  for (int row = 0; row < SIZE; row++) {
    printf("|");
    for (int col = 0; col < SIZE; col++) {
      printf(" %d", puzzle[row][col]);
      if ((col + 1) % 3 == 0) {
        printf(" |");
      }
    }
    printf("\n");
    if ((row + 1) % 3 == 0) {
      printf("---------------------\n");
    }
  }
}

int main() {
  int puzzle[SIZE][SIZE] = {
    { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
    { 6, 0, 0, 1, 9, 5, 0, 0, 0 },
    { 0, 9, 8, 0, 0, 0, 0, 6, 0 },
    { 8, 0, 0, 0, 6, 0, 0, 0, 3 },
    { 4, 0, 0, 8, 0, 3, 0, 0, 1 },
    { 7, 0, 0, 0, 2, 0, 0, 0, 6 },
    { 0, 6, 0, 0, 0, 0, 2, 8, 0 },
    { 0, 0, 0, 4, 1, 9, 0, 0, 5 },
    { 0, 0, 0, 0, 8, 0, 0, 7, 9 }
  };

  printf("Unsolved Puzzle:\n");
  printPuzzle(puzzle);

  if (solveSudoku(puzzle)) {
    printf("Solved Puzzle:\n");
    printPuzzle(puzzle);
  } else {
    printf("No solution exists.\n");
  }

  return 0;
}