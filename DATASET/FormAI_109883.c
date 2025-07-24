//FormAI DATASET v1.0 Category: Chess AI ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 8
#define COLS 8

char board[ROWS][COLS];

int get_random_number(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

void print_board() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

void init_board() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      board[i][j] = '-';
    }
  }
  
  board[0][0] = 'r';
  board[0][1] = 'n';
  board[0][2] = 'b';
  board[0][3] = 'q';
  board[0][4] = 'k';
  board[0][5] = 'b';
  board[0][6] = 'n';
  board[0][7] = 'r';
  
  for (int i = 0; i < COLS; i++) {
    board[1][i] = 'p';
  }
  
  board[7][0] = 'R';
  board[7][1] = 'N';
  board[7][2] = 'B';
  board[7][3] = 'Q';
  board[7][4] = 'K';
  board[7][5] = 'B';
  board[7][6] = 'N';
  board[7][7] = 'R';
  
  for (int i = 0; i < COLS; i++) {
    board[6][i] = 'P';
  }
}

bool is_move_valid(int start_row, int start_col, int end_row, int end_col) {
  if (board[start_row][start_col] == '-') {
    return false;
  }
  
  if (start_row == end_row && start_col == end_col) {
    return false;
  }
  
  if (board[start_row][start_col] == 'p') {
    if (start_col == end_col) {
      if (end_row == start_row + 1) {
        if (board[end_row][end_col] == '-') {
          return true;
        }
      }
    } else {
      if (end_row == start_row + 1 && abs(end_col - start_col) == 1) {
        if (board[end_row][end_col] != '-') {
          return true;
        }
      }
    }
    return false;
  }
  
  // more codes here for other pieces
  
  return true;
}

void make_move(int start_row, int start_col, int end_row, int end_col) {
  if (is_move_valid(start_row, start_col, end_row, end_col)) {
    board[end_row][end_col] = board[start_row][start_col];
    board[start_row][start_col] = '-';
  }
}

int main() {
  init_board();
  print_board();
  
  while (true) {
    int start_row = get_random_number(0, 7);
    int start_col = get_random_number(0, 7);
    int end_row = get_random_number(0, 7);
    int end_col = get_random_number(0, 7);
    
    make_move(start_row, start_col, end_row, end_col);
    
    printf("\n");
    print_board();
  }
  
  return 0;
}