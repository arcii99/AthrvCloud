//FormAI DATASET v1.0 Category: Sudoku solver ; Style: beginner-friendly
#include <stdio.h>
#define N 9

void print_board(int board[N][N]) {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

int is_valid(int board[N][N], int row, int col, int num) {
  
  // Check the row for conflicts
  for(int i = 0; i < N; i++) {
    if(board[row][i] == num) {
      return 0;
    }
  }
  
  // Check the column for conflicts
  for(int i = 0; i < N; i++) {
    if(board[i][col] == num) {
      return 0;
    }
  }
  
  // Check the square for conflicts
  int start_row = row - row % 3;
  int start_col = col - col % 3;
  
  for(int i = start_row; i < start_row + 3; i++) {
    for(int j = start_col; j < start_col + 3; j++) {
      if(board[i][j] == num) {
        return 0;
      }
    }
  }
  
  return 1;
}

int solve_board(int board[N][N], int row, int col) {
  
  // Check if we have reached the end of the board
  if(row == N) {
    return 1;
  }
  
  // Check if we have reached the end of the row
  if(col == N) {
    return solve_board(board, row+1, 0);
  }
  
  // Skip cells that already have a number
  if(board[row][col] != 0) {
    return solve_board(board, row, col+1);
  }
  
  // Try all possible numbers for this cell
  for(int num = 1; num <= N; num++) {
    if(is_valid(board, row, col, num)) {
      board[row][col] = num;
      
      if(solve_board(board, row, col+1)) {
        return 1;
      }
      
      board[row][col] = 0;
    }
  }
  
  return 0;
}

int main() {
  
  // Sample board to solve
  int board[N][N] = {
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
  
  if(solve_board(board, 0, 0)) {
    print_board(board);
  } else {
    printf("No solution found.\n");
  }
  
  return 0;
}