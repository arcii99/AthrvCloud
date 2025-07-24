//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 8
#define COLUMNS 8

int grid[ROWS][COLUMNS];

bool is_valid(int row, int col) {
  if (row >= 0 && row < ROWS && col >= 0 && col < COLUMNS && grid[row][col] == 0) {
    return true;
  } else {
    return false;
  }
}

bool solve(int row, int col, int moves) {
  if (moves == ROWS * COLUMNS) {
    return true;
  }
  
  int row_moves[] = {2, 2, -2, -2, 1, 1, -1, -1};
  int col_moves[] = {1, -1, 1, -1, 2, -2, 2, -2};
  
  for (int i = 0; i < 8; i++) {
    int new_row = row + row_moves[i];
    int new_col = col + col_moves[i];
    
    if (is_valid(new_row, new_col)) {
      grid[new_row][new_col] = moves + 1;
      
      if (solve(new_row, new_col, moves + 1)) {
        return true;
      } else {
        grid[new_row][new_col] = 0;
      }
    }
  }
  
  return false;
}

int main() {
  int start_row = 0;
  int start_col = 0;
  
  grid[start_row][start_col] = 1;
  
  if (solve(start_row, start_col, 1)) {
    printf("Solution found!\n\n");
    
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLUMNS; j++) {
        printf("%d\t", grid[i][j]);
      }
      printf("\n");
    }
  } else {
    printf("No solution found.\n");
  }
  
  return 0;
}