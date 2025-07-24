//FormAI DATASET v1.0 Category: Sudoku solver ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define N 9

int puzzle[N][N] = {
   {5, 3, 0, 0, 7, 0, 0, 0, 0},
   {6, 0, 0, 1, 9, 5, 0, 0, 0},
   {0, 9, 8, 0, 0, 0, 0, 6, 0},
   {8, 0, 0, 0, 6, 0, 0, 0, 3},
   {4, 0, 0, 8, 0, 3, 0, 0, 1},
   {7, 0, 0, 0, 2, 0, 0, 0, 6},
   {0, 6, 0, 0, 0, 0, 2, 8, 0},
   {0, 0, 0, 4, 1, 9, 0, 0, 5},
   {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

int solve(int, int);
void print();

int main() {
  int x = solve(0, 0);
  printf("Sudoku solved successfully! Check the answer below:\n");
  print();
  return 0;
}

int solve(int row, int col) {
  // base case condition
  if (row == N) return 1;

  // check if current cell is empty
  if (puzzle[row][col] != 0) {
    if (col == N-1) return solve(row+1, 0);
    else return solve(row, col+1);
  }

  int i, val;
  for (i = 1; i <= N; i++) {
    val = i;
    int r, c, flag = 1;

    for (r = 0; r < N; r++) {
      if (puzzle[r][col] == val) {
        flag = 0;
        break;
      }
    }

    if (!flag) continue;

    for (c = 0; c < N; c++) {
      if (puzzle[row][c] == val) {
        flag = 0;
        break;
      }
    }

    if (!flag) continue;

    int row_start = (row/3) * 3;
    int col_start = (col/3) * 3;
    int j;

    for (r = row_start; r < row_start+3; r++) {
      for (c = col_start; c < col_start+3; c++) {
        if (puzzle[r][c] == val) {
          flag = 0;
          break;
        }
      }
      if (!flag) break;
    }

    if (!flag) continue;

    puzzle[row][col] = val;
    if (col == N-1) {
      if (solve(row+1, 0)) return 1;
    } else {
      if (solve(row, col+1)) return 1;
    }
    puzzle[row][col] = 0;
  }
  return 0;
}

void print() {
  int i, j;

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("%d ", puzzle[i][j]);
    }
    printf("\n");
  }
}