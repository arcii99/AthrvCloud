//FormAI DATASET v1.0 Category: Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define MAX_BOMBS 20

// Game board cell
typedef struct {
  bool visible;
  bool bomb;
  int adjacent_bombs;
} Cell;

// Game board
Cell game_board[ROWS][COLS];

// This function initializes the game board
void init_game_board() {
  int i, j;
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      game_board[i][j].visible = false;
      game_board[i][j].bomb = false;
      game_board[i][j].adjacent_bombs = 0;
    }
  }
}

// This function randomly places bombs on the game board
void place_bombs() {
  int i, row, col;
  for (i = 0; i < MAX_BOMBS; i++) {
    row = rand() % ROWS;
    col = rand() % COLS;
    if (!game_board[row][col].bomb) {
      game_board[row][col].bomb = true;
      update_adjacent_bombs(row, col);
    } else {
      i--;
    }
  }
}

// This function updates the number of adjacent bombs for a given cell
void update_adjacent_bombs(int row, int col) {
  int i, j, r, c;
  for (i = -1; i <= 1; i++) {
    for (j = -1; j <= 1; j++) {
      r = row + i;
      c = col + j;
      if (r >= 0 && r < ROWS && c >= 0 && c < COLS) {
        if (game_board[r][c].bomb) {
          game_board[row][col].adjacent_bombs++;
        }
      }
    }
  }
}

// This function prints the game board
void print_game_board() {
  int i, j;
  printf("\n");
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      if (game_board[i][j].visible) {
        if (game_board[i][j].bomb) {
          printf("* ");
        } else {
          printf("%d ", game_board[i][j].adjacent_bombs);
        }
      } else {
        printf(". ");
      }
    }
    printf("\n");
  }
}

// This function reveals the adjacent cells to a given cell
void reveal_cells(int row, int col) {
  game_board[row][col].visible = true;
  if (game_board[row][col].adjacent_bombs == 0) {
    int i, j, r, c;
    for (i = -1; i <= 1; i++) {
      for (j = -1; j <= 1; j++) {
        r = row + i;
        c = col + j;
        if (r >= 0 && r < ROWS && c >= 0 && c < COLS) {
          if (!game_board[r][c].visible) {
            reveal_cells(r, c);
          }
        }
      }
    }
  }
}

int main() {
  int row, col;
  bool game_over = false;
  srand(time(NULL));
  init_game_board();
  place_bombs();
  printf("Welcome to Minesweeper!\n\n");
  while (!game_over) {
    print_game_board();
    printf("\nEnter row and column (separated by a space) or -1 to exit: ");
    scanf("%d", &row);
    if (row == -1) {
      break;
    }
    scanf("%d", &col);
    if (game_board[row][col].bomb) {
      game_over = true;
      printf("\nGame Over!\n\n");
      print_game_board();
    } else {
      reveal_cells(row, col);
      bool win = true;
      int i, j;
      for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
          if (!game_board[i][j].visible && !game_board[i][j].bomb) {
            win = false;
          }
        }
      }
      if (win) {
        game_over = true;
        printf("\nYou Win!\n\n");
        print_game_board();
      }
    }
  }
  return 0;
}