//FormAI DATASET v1.0 Category: Game of Life ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_board(int board[][20]) {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      if (board[i][j] == 1) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int count_neighbors(int board[][20], int x, int y) {
  int count = 0;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      int neighbor_x = x + i;
      int neighbor_y = y + j;
      if (neighbor_x >= 0 && neighbor_x < 20 && neighbor_y >= 0 && neighbor_y < 20) {
        count += board[neighbor_x][neighbor_y];
      }
    }
  }
  count -= board[x][y];
  return count;
}

void update_board(int board[][20]) {
  int newboard[20][20];
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      int neighbors = count_neighbors(board, i, j);
      if (board[i][j]) { // cell is alive
        if (neighbors == 2 || neighbors == 3) {
          newboard[i][j] = 1;
        } else {
          newboard[i][j] = 0;
        }
      } else { // cell is dead
        if (neighbors == 3) {
          newboard[i][j] = 1;
        } else {
          newboard[i][j] = 0;
        }
      }
    }
  }
  // copy new board over old board
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      board[i][j] = newboard[i][j];
    }
  }
}

int main() {
  // initialize random seed
  srand(time(NULL));
  // initialize board
  int board[20][20];
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      board[i][j] = rand() % 2;
    }
  }
  // run game of life
  for (int i = 0; i < 100; i++) {
    system("clear"); // clear screen
    print_board(board);
    update_board(board);
    usleep(100000); // wait for 0.1 seconds
  }
  return 0;
}