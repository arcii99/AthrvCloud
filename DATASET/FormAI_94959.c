//FormAI DATASET v1.0 Category: Sudoku solver ; Style: sophisticated
#include <stdio.h>

// The board size nd the empty cell key
#define BOARD_SIZE 9
#define EMPTY_CELL 0

// Print board
void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
  for(int i = 0; i < BOARD_SIZE; i++) {
    for(int j = 0; j < BOARD_SIZE; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

// Determine if specified value can be placed at position
int can_place(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int candidate) {
  // Check row
  for(int i = 0; i < BOARD_SIZE; i++) {
    if(board[row][i] == candidate) return 0;
  }

  // Check column
  for(int i = 0; i < BOARD_SIZE; i++) {
    if(board[i][col] == candidate) return 0;
  }

  // Check grid
  int start_row = row - row % 3, start_col = col - col % 3;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(board[start_row + i][start_col + j] == candidate) return 0;
    }
  }

  // Valid placement
  return 1;
}

// Find next empty cell, returning 0 if none found
int find_empty(int board[BOARD_SIZE][BOARD_SIZE], int* row, int* col) {
  for(*row = 0; *row < BOARD_SIZE; (*row)++) {
    for(*col = 0; *col < BOARD_SIZE; (*col)++) {
      if(board[*row][*col] == EMPTY_CELL) return 1;
    }
  }
  return 0;
}

// Solve board recursively
int solve_board(int board[BOARD_SIZE][BOARD_SIZE]) {
  int row, col;

  // Find unassigned cell
  if(!find_empty(board, &row, &col)) return 1;

  // Iterate through possible candidates
  for(int candidate = 1; candidate <= BOARD_SIZE; candidate++) {
    // Check if candidate is a valid placement at position
    if(can_place(board, row, col, candidate)) {
      // Place candidate and recursively try to solve board
      board[row][col] = candidate;
      if(solve_board(board)) return 1;
      // Reset cell if recursive solve fails backtracking
      board[row][col] = EMPTY_CELL;
    }
  }
  // No solution found with current configuration
  return 0;
}

int main() {
  int board[BOARD_SIZE][BOARD_SIZE] = {
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

  printf("Solving Sudoku board:\n");
  print_board(board);

  if(solve_board(board)) {
    printf("\nSolution:\n");
    print_board(board);
  } else {
    printf("\nNo solution exists for the given board.\n");
  }

  return 0;
}