//FormAI DATASET v1.0 Category: Game of Life ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

int board[ROWS][COLS];
int next_board[ROWS][COLS];

void initialize_board() {
  // Initialize the board
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      board[i][j] = rand() % 2;
    }
  }
}

void print_board() {
  printf("\n");
  // Print the board
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      printf("%c ", board[i][j] ? '*' : ' ');
    }
    printf("\n");
  }
  printf("\n");
}

int get_neighbours_count(int row, int col) {
  int count = 0;
  int i, j;
  // Check the neighbours of the cell
  for(i = -1; i <= 1; i++) {
    for(j = -1; j <= 1; j++) {
      // Do not count the cell itself
      if(i == 0 && j == 0) {
        continue;
      }
      // Check if the neighbour is within the bounds of the board
      if(row + i >= 0 && row + i < ROWS && col + j >= 0 && col + j < COLS) {
        count += board[row + i][col + j];
      }
    }
  }
  return count;
}

void update_board() {
  // Update the board based on the Game of Life rules
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      int neighbours_count = get_neighbours_count(i, j);
      // If the cell is alive
      if(board[i][j]) {
        // Kill the cell if it has less than 2 or more than 3 neighbours
        if(neighbours_count < 2 || neighbours_count > 3) {
          next_board[i][j] = 0;
        }
        // Keep the cell alive if it has 2 or 3 neighbours
        else {
          next_board[i][j] = 1;
        }
      }
      // If the cell is dead
      else {
        // Bring the cell to life if it has 3 neighbours
        if(neighbours_count == 3) {
          next_board[i][j] = 1;
        }
        else {
          next_board[i][j] = 0;
        }
      }
    }
  }
  // Copy the next board to the current board
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      board[i][j] = next_board[i][j];
    }
  }
}

int main() {
  srand(time(NULL));
  initialize_board();
  int iterations = 0;
  while(iterations < 100) {
    print_board();
    update_board();
    iterations++;
  }
  return 0;
}