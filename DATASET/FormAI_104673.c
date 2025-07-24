//FormAI DATASET v1.0 Category: Game of Life ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdbool.h>
#define ROW 10
#define COL 10

void initialize_board(bool board[][COL]);
void print_board(bool board[][COL]);
void update_board(bool board[][COL]);
int count_alive_neighbors(bool board[][COL], int row, int col);

int main() {
  bool board[ROW][COL];
  initialize_board(board);
  print_board(board);

  char input;
  do {
    printf("Press any key to continue or 'q' to quit: ");
    scanf(" %c", &input);
    update_board(board);
    print_board(board);
  } while (input != 'q');

  return 0;
}

void initialize_board(bool board[][COL]) {
  for (int r = 0; r < ROW; r++) {
    for (int c = 0; c < COL; c++) {
      board[r][c] = false;
    }
  }
  board[4][4] = true;
  board[4][5] = true;
  board[4][6] = true;
}

void print_board(bool board[][COL]) {
  printf("\n");
  for (int r = 0; r < ROW; r++) {
    for (int c = 0; c < COL; c++) {
      printf("%c", board[r][c] ? '#' : '-');
    }
    printf("\n");
  }
}

void update_board(bool board[][COL]) {
  bool updated_board[ROW][COL];
  for (int r = 0; r < ROW; r++) {
    for (int c = 0; c < COL; c++) {
      int alive_neighbors = count_alive_neighbors(board, r, c);

      if (board[r][c]) { // cell is alive
        if (alive_neighbors == 2 || alive_neighbors == 3) {
          updated_board[r][c] = true;
        } else {
          updated_board[r][c] = false;
        }
      } else { // cell is dead
        if (alive_neighbors == 3) {
          updated_board[r][c] = true;
        } else {
          updated_board[r][c] = false;
        }
      }
    }
  }
  // copy updated board back to original board
  for (int r = 0; r < ROW; r++) {
    for (int c = 0; c < COL; c++) {
      board[r][c] = updated_board[r][c];
    }
  }
}

int count_alive_neighbors(bool board[][COL], int row, int col) {
  int count = 0;
  int r_min = row == 0 ? 0 : row - 1;
  int r_max = row == ROW - 1 ? ROW - 1 : row + 1;
  int c_min = col == 0 ? 0 : col - 1;
  int c_max = col == COL - 1 ? COL - 1 : col + 1;
  for (int r = r_min; r <= r_max; r++) {
    for (int c = c_min; c <= c_max; c++) {
      if (r == row && c == col) {
        continue; // skip current cell
      }
      if (board[r][c]) {
        count++;
      }
    }
  }
  return count;
}