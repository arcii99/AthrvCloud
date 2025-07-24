//FormAI DATASET v1.0 Category: Game of Life ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void init_board(int board[ROWS][COLS]);
void print_board(int board[ROWS][COLS]);
int get_num_neighbors(int board[ROWS][COLS], int row, int col);
void update_board(int board[ROWS][COLS]);

int main() {
  srand(time(NULL));

  int board[ROWS][COLS];
  init_board(board);

  printf("Initial Board:\n");
  print_board(board);

  int i;
  for(i = 0; i < 10; i++) {
    update_board(board);
    printf("After generation %d:\n", i+1);
    print_board(board);
  }

  return 0;
}

// Initializes the board randomly
void init_board(int board[ROWS][COLS]) {
  int i, j;
  for(i = 0; i < ROWS; i++) {
    for(j = 0; j < COLS; j++) {
      int r = rand() % 2;
      board[i][j] = r;
    }
  }
}

// Prints the board to the console
void print_board(int board[ROWS][COLS]) {
  int i, j;
  for(i = 0; i < ROWS; i++) {
    for(j = 0; j < COLS; j++) {
      printf("%c ", board[i][j] ? '#' : '-');
    }
    printf("\n");
  }
  printf("\n");
}

// Gets the number of living neighbors for a cell
int get_num_neighbors(int board[ROWS][COLS], int row, int col) {
  int num_neighbors = 0;

  // Check top-left neighbor
  if(row > 0 && col > 0 && board[row-1][col-1] == 1) {
    num_neighbors++;
  }

  // Check top neighbor
  if(row > 0 && board[row-1][col] == 1) {
    num_neighbors++;
  }

  // Check top-right neighbor
  if(row > 0 && col < COLS-1 && board[row-1][col+1] == 1) {
    num_neighbors++;
  }

  // Check left neighbor
  if(col > 0 && board[row][col-1] == 1) {
    num_neighbors++;
  }

  // Check right neighbor
  if(col < COLS-1 && board[row][col+1] == 1) {
    num_neighbors++;
  }

  // Check bottom-left neighbor
  if(row < ROWS-1 && col > 0 && board[row+1][col-1] == 1) {
    num_neighbors++;
  }

  // Check bottom neighbor
  if(row < ROWS-1 && board[row+1][col] == 1) {
    num_neighbors++;
  }

  // Check bottom-right neighbor
  if(row < ROWS-1 && col < COLS-1 && board[row+1][col+1] == 1) {
    num_neighbors++;
  }

  return num_neighbors;
}

// Updates the board to the next generation
void update_board(int board[ROWS][COLS]) {
  int new_board[ROWS][COLS];
  int i, j;

  for(i = 0; i < ROWS; i++) {
    for(j = 0; j < COLS; j++) {
      int num_neighbors = get_num_neighbors(board, i, j);
      if(board[i][j] == 1) {
        if(num_neighbors < 2 || num_neighbors > 3) {
          new_board[i][j] = 0;
        } else {
          new_board[i][j] = 1;
        }
      } else {
        if(num_neighbors == 3) {
          new_board[i][j] = 1;
        } else {
          new_board[i][j] = 0;
        }
      }
    }
  }

  // Copy new_board to board
  for(i = 0; i < ROWS; i++) {
    for(j = 0; j < COLS; j++) {
      board[i][j] = new_board[i][j];
    }
  }
}