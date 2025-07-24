//FormAI DATASET v1.0 Category: Checkers Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define BOARD_SIZE 8

// Model
char board[BOARD_SIZE][BOARD_SIZE] = {
  {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
  {'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '},
  {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
  {'w', ' ', 'w', ' ', 'w', ' ', 'w', ' '},
  {' ', 'w', ' ', 'w', ' ', 'w', ' ', 'w'},
  {'w', ' ', 'w', ' ', 'w', ' ', 'w', ' '}
};

// View
void print_board() {
  printf("  a b c d e f g h\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i+1);
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("%d", i+1);
    printf("\n");
  }
  printf("  a b c d e f g h\n");
}

// Controller
int get_row(char row) {
  return toupper(row) - 'A';
}

int get_column(int column) {
  return column - 1;
}

bool is_valid_move(int current_row, int current_column, int new_row, int new_column) {
  // Ensure the new cell is within the bounds of the board
  if (new_row < 0 || new_column < 0 || new_row >= BOARD_SIZE || new_column >= BOARD_SIZE) {
    return false;
  }

  // Ensure the new cell is diagonal to the current cell
  int row_offset = new_row - current_row;
  int column_offset = new_column - current_column;
  if (abs(row_offset) != abs(column_offset)) {
    return false;
  }

  // Ensure the new cell is not occupied
  if (board[new_row][new_column] != ' ') {
    return false;
  }

  // Ensure the current cell is occupied
  if (board[current_row][current_column] == ' ') {
    return false;
  }

  // Ensure a regular checker is only moving diagonally forward
  if (board[current_row][current_column] == 'w' && row_offset > 0) {
    return false;
  }
  if (board[current_row][current_column] == 'b' && row_offset < 0) {
    return false;
  }

  // Ensure that a piece is making a capture move if there is an opposing piece diagonally adjacent
  int row_direction = (row_offset > 0) ? 1 : -1;
  int column_direction = (column_offset > 0) ? 1 : -1;
  if (abs(row_offset) == 2) {
    int middle_row = current_row + row_direction;
    int middle_column = current_column + column_direction;
    if (board[middle_row][middle_column] == ' ') {
      return false;
    }
    if (board[middle_row][middle_column] == board[current_row][current_column]) {
      return false;
    }
  }

  return true;
}

void move_piece(int current_row, int current_column, int new_row, int new_column) {
  board[new_row][new_column] = board[current_row][current_column];
  board[current_row][current_column] = ' ';

  // Check for capture
  int row_offset = new_row - current_row;
  int column_offset = new_column - current_column;
  if (abs(row_offset) == 2) {
    int captured_row = current_row + row_offset / 2;
    int captured_column = current_column + column_offset / 2;
    board[captured_row][captured_column] = ' ';
  }
}

int main() {
  printf("Welcome to Post-Apocalyptic Checkers!\n");
  printf("--------------------------------------\n");
  printf("The world is in ruins, but people still find entertainment playing checkers.\n");
  printf("Each player gets 12 regular checkers, which can only move diagonally forward,\n");
  printf("and must capture an opposing checker if possible. When a regular checker\n");
  printf("reaches the opponent's back row, it is promoted to a king, which can move\n");
  printf("diagonally in any direction and perform multiple jumps in a single turn.\n");
  printf("Good luck, and may the odds be ever in your favor!\n");

  while (true) {
    print_board();

    printf("Player 1, please enter the location of the checker you want to move (e.g. a1): ");
    char current_row_input;
    int current_column_input;
    scanf(" %c%d", &current_row_input, &current_column_input);

    int current_row = get_row(current_row_input);
    int current_column = get_column(current_column_input);

    printf("Player 1, please enter the location where you want to move your checker (e.g. b2): ");
    char new_row_input;
    int new_column_input;
    scanf(" %c%d", &new_row_input, &new_column_input);

    int new_row = get_row(new_row_input);
    int new_column = get_column(new_column_input);

    if (!is_valid_move(current_row, current_column, new_row, new_column)) {
      printf("Invalid move! Please try again.\n");
      continue;
    }

    move_piece(current_row, current_column, new_row, new_column);

    printf("Player 2, it's your turn.\n");

    print_board();

    printf("Player 2, please enter the location of the checker you want to move (e.g. a1): ");
    scanf(" %c%d", &current_row_input, &current_column_input);

    current_row = get_row(current_row_input);
    current_column = get_column(current_column_input);

    printf("Player 2, please enter the location where you want to move your checker (e.g. b2): ");
    scanf(" %c%d", &new_row_input, &new_column_input);

    new_row = get_row(new_row_input);
    new_column = get_column(new_column_input);

    if (!is_valid_move(current_row, current_column, new_row, new_column)) {
      printf("Invalid move! Please try again.\n");
      continue;
    }

    move_piece(current_row, current_column, new_row, new_column);
  }

  return 0;
}