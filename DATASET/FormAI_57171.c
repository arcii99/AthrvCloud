//FormAI DATASET v1.0 Category: Sudoku solver ; Style: sophisticated
#include <stdio.h>

#define SIZE 9

int puzzle[SIZE][SIZE] = {
  {0, 0, 0, 8, 0, 0, 0, 0, 0},
  {0, 0, 8, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 7, 0, 6, 0, 0},
  {3, 0, 0, 0, 0, 1, 0, 0, 6},
  {6, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 3},
  {0, 9, 0, 0, 0, 7, 0, 0, 0},
  {0, 0, 0, 0, 0, 6, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 4, 0, 0}
};

void print(int arr[SIZE][SIZE]) {
  int i, j;
  
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

int findEmpty(int arr[SIZE][SIZE], int *row, int *col) {
  int i, j;
  
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      if (arr[i][j] == 0) {
        *row = i;
        *col = j;
        return 1;
      }
    }
  }
  
  return 0;
}

int isSafe(int arr[SIZE][SIZE], int row, int col, int num) {
  int i, j;
  
  // check row
  for (i = 0; i < SIZE; i++) {
    if (arr[row][i] == num) {
      return 0;
    }
  }
  
  // check column
  for (i = 0; i < SIZE; i++) {
    if (arr[i][col] == num) {
      return 0;
    }
  }
  
  // check box
  int startRow = row - row % 3;
  int startCol = col - col % 3;
  
  for (i = startRow; i < startRow + 3; i++) {
    for (j = startCol; j < startCol + 3; j++) {
      if (arr[i][j] == num) {
        return 0;
      }
    }
  }
  
  return 1;
}

int solve(int arr[SIZE][SIZE]) {
  int row, col;
  
  if (!findEmpty(arr, &row, &col)) {
    return 1;
  }
  
  int num;
  
  for (num = 1; num <= 9; num++) {
    if (isSafe(arr, row, col, num)) {
      arr[row][col] = num;
      
      if (solve(arr)) {
        return 1;
      }
      
      arr[row][col] = 0;
    }
  }
  
  return 0;
}

int main() {
  printf("Puzzle:\n");
  print(puzzle);
  
  if (solve(puzzle)) {
    printf("Solution:\n");
    print(puzzle);
  } else {
    printf("No solution found\n");
  }
  
  return 0;
}