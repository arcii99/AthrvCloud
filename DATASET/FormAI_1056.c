//FormAI DATASET v1.0 Category: Checkers Game ; Style: detailed
#include <stdio.h>

int main() {
  char board[8][8] = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                      {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                      {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                      {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                      {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                      {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                      {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                      {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};

  // Prints the initial board state
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      printf("%c ", board[row][col]);
    }
    printf("\n");
  }

  // Game loop
  while (1) {
    int from_row, from_col, to_row, to_col;

    // Get user input for move
    printf("Enter move (row, col, new row, new col): ");
    scanf("%d %d %d %d", &from_row, &from_col, &to_row, &to_col);

    // Check if move is valid
    if (board[from_row][from_col] == ' ' ||
        board[from_row][from_col] == '.' ||
        board[to_row][to_col] != ' ') {
      printf("Invalid move\n");
      continue;
    }

    // Check if move is legal
    if (!check_move(board, from_row, from_col, to_row, to_col)) {
      printf("Illegal move\n");
      continue;
    }

    // Execute move
    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = ' ';

    // Prints the board state after move
    for (int row = 0; row < 8; row++) {
      for (int col = 0; col < 8; col++) {
        printf("%c ", board[row][col]);
      }
      printf("\n");
    }
  }

  return 0;
}

int check_move(char board[8][8], int from_row, int from_col, int to_row, int to_col) {
  char piece = board[from_row][from_col];
  int valid_move = 0;

  switch (piece) {
    // Check for valid king moves
    case 'K':
    case 'k':
      if ((to_row == from_row + 1 || to_row == from_row - 1 || to_row == from_row) &&
          (to_col == from_col + 1 || to_col == from_col - 1 || to_col == from_col)) {
        valid_move = 1;
      }
      break;

    // Check for valid queen moves
    case 'Q':
    case 'q':
      if (check_rook_move(board, from_row, from_col, to_row, to_col) ||
          check_bishop_move(board, from_row, from_col, to_row, to_col)) {
        valid_move = 1;
      }
      break;

    // Check for valid bishop moves
    case 'B':
    case 'b':
      if (check_bishop_move(board, from_row, from_col, to_row, to_col)) {
        valid_move = 1;
      }
      break;

    // Check for valid knight moves
    case 'N':
    case 'n':
      if ((to_row == from_row + 2 && (to_col == from_col + 1 || to_col == from_col - 1)) ||
          (to_row == from_row - 2 && (to_col == from_col + 1 || to_col == from_col - 1)) ||
          (to_col == from_col + 2 && (to_row == from_row + 1 || to_row == from_row - 1)) ||
          (to_col == from_col - 2 && (to_row == from_row + 1 || to_row == from_row - 1))) {
        valid_move = 1;
      }
      break;

    // Check for valid rook moves
    case 'R':
    case 'r':
      if (check_rook_move(board, from_row, from_col, to_row, to_col)) {
        valid_move = 1;
      }
      break;

    // Check for valid pawn moves
    case 'P':
      if (to_row == from_row + 1 && to_col == from_col) {
        if (board[to_row][to_col] == ' ') {
          valid_move = 1;
        }
      } else if (to_row == from_row + 1 && (to_col == from_col + 1 || to_col == from_col - 1)) {
        if (board[to_row][to_col] != ' ' && board[to_row][to_col] != '.' && board[to_row][to_col] != 'P') {
          valid_move = 1;
        }
      }
      break;

    case 'p':
      if (to_row == from_row - 1 && to_col == from_col) {
        if (board[to_row][to_col] == ' ') {
          valid_move = 1;
        }
      } else if (to_row == from_row - 1 && (to_col == from_col + 1 || to_col == from_col - 1)) {
        if (board[to_row][to_col] != ' ' && board[to_row][to_col] != '.' && board[to_row][to_col] != 'p') {
          valid_move = 1;
        }
      }
      break;
  }

  return valid_move;
}

int check_bishop_move(char board[8][8], int from_row, int from_col, int to_row, int to_col) {
  int valid_move = 0;

  if (from_row < to_row && from_col < to_col) {
    // Moving down and to the right
    for (int row = from_row + 1, col = from_col + 1; row <= to_row && col <= to_col; row++, col++) {
      if (row == to_row && col == to_col) {
        valid_move = 1;
      } else if (board[row][col] != ' ') {
        break;
      }
    }
  } else if (from_row < to_row && from_col > to_col) {
    // Moving down and to the left
    for (int row = from_row + 1, col = from_col - 1; row <= to_row && col >= to_col; row++, col--) {
      if (row == to_row && col == to_col) {
        valid_move = 1;
      } else if (board[row][col] != ' ') {
        break;
      }
    }
  } else if (from_row > to_row && from_col < to_col) {
    // Moving up and to the right
    for (int row = from_row - 1, col = from_col + 1; row >= to_row && col <= to_col; row--, col++) {
      if (row == to_row && col == to_col) {
        valid_move = 1;
      } else if (board[row][col] != ' ') {
        break;
      }
    }
  } else if (from_row > to_row && from_col > to_col) {
    // Moving up and to the left
    for (int row = from_row - 1, col = from_col - 1; row >= to_row && col >= to_col; row--, col--) {
      if (row == to_row && col == to_col) {
        valid_move = 1;
      } else if (board[row][col] != ' ') {
        break;
      }
    }
  }

  return valid_move;
}

int check_rook_move(char board[8][8], int from_row, int from_col, int to_row, int to_col) {
  int valid_move = 0;

  if (from_row < to_row && from_col == to_col) {
    // Moving down
    for (int row = from_row + 1; row <= to_row; row++) {
      if (row == to_row) {
        valid_move = 1;
      } else if (board[row][from_col] != ' ') {
        break;
      }
    }
  } else if (from_row > to_row && from_col == to_col) {
    // Moving up
    for (int row = from_row - 1; row >= to_row; row--) {
      if (row == to_row) {
        valid_move = 1;
      } else if (board[row][from_col] != ' ') {
        break;
      }
    }
  } else if (from_col < to_col && from_row == to_row) {
    // Moving right
    for (int col = from_col + 1; col <= to_col; col++) {
      if (col == to_col) {
        valid_move = 1;
      } else if (board[from_row][col] != ' ') {
        break;
      }
    }
  } else if (from_col > to_col && from_row == to_row) {
    // Moving left
    for (int col = from_col - 1; col >= to_col; col--) {
      if (col == to_col) {
        valid_move = 1;
      } else if (board[from_row][col] != ' ') {
        break;
      }
    }
  }

  return valid_move;
}