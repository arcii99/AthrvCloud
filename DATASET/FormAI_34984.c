//FormAI DATASET v1.0 Category: Game of Life ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// size of the game board
#define BOARD_SIZE 20

// function to print the game board
void print_board(int board[][BOARD_SIZE]) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j])
        printf("* ");
      else
        printf(". ");
    }
    printf("\n");
  }
  printf("\n");
}

// function to initialize the game board
void init_board(int board[][BOARD_SIZE]) {
  srand(time(NULL)); // seed the random number generator
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = rand() % 2; // initialize each cell randomly
    }
  }
}

// function to update the game board for one generation
void update_board(int board[][BOARD_SIZE]) {
  int temp[BOARD_SIZE][BOARD_SIZE]; // create a temporary board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      int count = 0; // count the number of live neighbors
      for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
          if (i + x >= 0 && i + x < BOARD_SIZE &&
              j + y >= 0 && j + y < BOARD_SIZE &&
              !(x == 0 && y == 0) &&
              board[i + x][j + y])
            count++;
        }
      }
      // apply the game rules
      if (board[i][j] && count < 2) // underpopulation
        temp[i][j] = 0;
      else if (board[i][j] && (count == 2 || count == 3)) // survival
        temp[i][j] = 1;
      else if (board[i][j] && count > 3) // overpopulation
        temp[i][j] = 0;
      else if (!board[i][j] && count == 3) // reproduction
        temp[i][j] = 1;
      else
        temp[i][j] = board[i][j];
    }
  }
  // copy the temporary board back to the original board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = temp[i][j];
    }
  }
}

int main() {
  int board[BOARD_SIZE][BOARD_SIZE]; // initialize the game board
  init_board(board);
  // main game loop
  while (1) {
    print_board(board);
    update_board(board);
    system("clear"); // clear the terminal window
  }
  return 0;
}