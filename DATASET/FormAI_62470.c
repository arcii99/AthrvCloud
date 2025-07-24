//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 3
#define COLS 3

char board[ROWS][COLS];

// printing the board
void print_board() {
  for (int row = 0; row < ROWS; row++) {

    for (int col = 0; col < COLS; col++) {
      printf("| %c ", board[row][col]);
    }
    printf("|\n");
  }
}

// checking whether there is a tie or not
bool check_tie() {
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      if (board[row][col] == ' ') {
        return false;
      }
    }
  }
  return true;
}

// checking if someone won
bool check_win(char symbol) {
  bool row_win, col_win, diagonal_win1, diagonal_win2;
  for (int row = 0; row < ROWS; row++) {
    row_win = true;
    col_win = true;
    for (int col = 0; col < COLS; col++) {
      if (board[row][col] != symbol) {
        row_win = false;
      }
      if (board[col][row] != symbol) {
        col_win = false;
      }
    }
    if (row_win || col_win) {
      return true;
    }
  }
  diagonal_win1 = true;
  diagonal_win2 = true;
  for (int index = 0; index < ROWS; index++) {
    if (board[index][index] != symbol) {
      diagonal_win1 = false;
    }
    if (board[index][ROWS - 1 - index] != symbol) {
      diagonal_win2 = false;
    }
  }
  if (diagonal_win1 || diagonal_win2) {
      return true;
  }
  return false;
}

// getting the input from player
void player_turn(char symbol) {
  int row, col;
  printf("Enter row number: ");
  scanf("%d", &row);
  printf("Enter col number: ");
  scanf("%d", &col);
  if (board[row][col] == ' ') {
    board[row][col] = symbol;
  } else {
      printf("Place is already taken! Try again.\n");
      player_turn(symbol);
  }
}

// minimax algorithm
int minimax(bool maximizing, int depth) {
  if (check_win('O')) {
    return depth - 10; 
  } else if (check_win('X')) {
    return 10 - depth; 
  } else if (check_tie()) {
    return 0; 
  }
  int score;
  if (maximizing) {
    int best_score = -100;
    for (int row = 0; row < ROWS; row++) {
      for (int col = 0; col < COLS; col++) {
        if (board[row][col] == ' ') {
          board[row][col] = 'X';
          score = minimax(false, depth + 1);
          board[row][col] = ' ';
          if (score > best_score) {
            best_score = score;
          }
        }
      }
    }
    return best_score;
  } else {
    int worst_score = 100;
    for (int row = 0; row < ROWS; row++) {
      for (int col = 0; col < COLS; col++) {
        if (board[row][col] == ' ') {
          board[row][col] = 'O';
          score = minimax(true, depth + 1);
          board[row][col] = ' ';
          if (score < worst_score) {
            worst_score = score;
          }
        }
      }
    }
    return worst_score;
  }
}

// getting input from AI
void ai_turn() {
  int row, col;
  int best_score = -100;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (board[i][j] == ' ') {
        board[i][j] = 'X';
        int score = minimax(false, 0);
        board[i][j] = ' ';
        if (score > best_score) {
          best_score = score;
          row = i;
          col = j;
        }
      }
    }
  }
  board[row][col] = 'X';
}

// main game loop
int main() {
  // initializing the board with spaces
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      board[row][col] = ' ';
    }
  }

  // setting random seed for AI to make different moves each time
  srand(time(NULL));

  // gameloop
  while (true) {
    // player turn
    print_board();
    player_turn('O');
    if (check_win('O')) {
      printf("You Won!\n");
      return 0;
    }
    if (check_tie()) {
      printf("It's a tie!\n");
      return 0;
    }

    // ai turn
    ai_turn();
    if (check_win('X')) {
      print_board();
      printf("You Lose!\n");
      return 0;
    }
    if (check_tie()) {
      printf("It's a tie!\n");
      return 0;
    }
  }
}