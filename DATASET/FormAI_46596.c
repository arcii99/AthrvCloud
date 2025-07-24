//FormAI DATASET v1.0 Category: Chess engine ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

// Declarations
void init_board(char board[BOARD_SIZE][BOARD_SIZE]);
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
void move_piece(char board[BOARD_SIZE][BOARD_SIZE], int x1, int y1, int x2, int y2);
int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int x1, int y1, int x2, int y2);
int check_king(char board[BOARD_SIZE][BOARD_SIZE], int king_x, int king_y, int opponent_x, int opponent_y);

// Main function
int main() {
  char board[BOARD_SIZE][BOARD_SIZE];
  init_board(board);
  print_board(board);

  // Example move of pawn from A2 - A4
  move_piece(board, 1, 0, 3, 0);
  print_board(board);

  return 0;
}

// Initialize the chess board
void init_board(char board[BOARD_SIZE][BOARD_SIZE]) {
  // Set up black pieces
  board[0][0] = 'r';
  board[0][1] = 'n';
  board[0][2] = 'b';
  board[0][3] = 'q';
  board[0][4] = 'k';
  board[0][5] = 'b';
  board[0][6] = 'n';
  board[0][7] = 'r';
  for (int i = 0; i < BOARD_SIZE; i++) {
    board[1][i] = 'p';
  }

  // Fill in blank spaces
  for (int i = 2; i < 6; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }

  // Set up white pieces
  for (int i = 0; i < BOARD_SIZE; i++) {
    board[6][i] = 'P';
  }
  board[7][0] = 'R';
  board[7][1] = 'N';
  board[7][2] = 'B';
  board[7][3] = 'Q';
  board[7][4] = 'K';
  board[7][5] = 'B';
  board[7][6] = 'N';
  board[7][7] = 'R';
}

// Print the chess board
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("|");
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf(" %c |", board[i][j]);
    }
    printf("\n");
  }
}

// Move a piece on the board
void move_piece(char board[BOARD_SIZE][BOARD_SIZE], int x1, int y1, int x2, int y2) {
  if (is_valid_move(board, x1, y1, x2, y2)) {
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = ' ';
  }
}

// Check if a move is valid
int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int x1, int y1, int x2, int y2) {
  char piece = board[x1][y1];

  // Check if the move falls within the board
  if ((x1 < 0 || x1 >= BOARD_SIZE) || (x2 < 0 || x2 >= BOARD_SIZE) || (y1 < 0 || y1 >= BOARD_SIZE) || (y2 < 0 || y2 >= BOARD_SIZE)) {
    return 0;
  }

  // Check if the destination space is occupied by a piece of the same color
  if (board[x2][y2] != ' ' && ((isupper(piece) && isupper(board[x2][y2])) || (islower(piece) && islower(board[x2][y2])))) {
    return 0;
  }

  // Check if the move is valid for the selected piece
  switch (tolower(piece)) {
    // Pawns
    case 'p':
      // Check if the pawn is moving forward
      if (x2 > x1) {
        return 0;
      }
      // Check if the pawn is moving forward by more than one
      if ((x1 == 1 && x2 == 3 && y1 == y2) || (x1 == 6 && x2 == 4 && y1 == y2)) {
        // Check if there is a piece in front of the pawn
        if (board[x2 + ((x1 - x2) / 2)][y2] != ' ') {
          return 0;
        }
      } else {
        // Check if the pawn is moving diagonally to capture
        if ((abs(x2 - x1) == 1) && (abs(y2 - y1) == 1) && (board[x2][y2] == ' ')) {
          return 0;
        }
        // Check if the pawn is moving diagonally to attack
        if ((abs(x2 - x1) != 1) || (abs(y2 - y1) != 1) || (board[x2][y2] == ' ')) {
          return 0;
        }
      }
      break;

    // Rooks
    case 'r':
      // Check if there are any pieces blocking the path of the rook
      if (x1 == x2) {
        // Rook is moving horizontally
        for (int i = y1 + ((y2 - y1) / abs(y2 - y1)); i != y2; i += ((y2 - y1) / abs(y2 - y1))) {
          if (board[x1][i] != ' ') {
            return 0;
          }
        }
      } else if (y1 == y2) {
        // Rook is moving vertically
        for (int i = x1 + ((x2 - x1) / abs(x2 - x1)); i != x2; i += ((x2 - x1) / abs(x2 - x1))) {
          if (board[i][y1] != ' ') {
            return 0;
          }
        }
      } else {
        // Rook is trying to move diagonally
        return 0;
      }
      break;

    // Knights
    case 'n':
      // Check if the knight is moving in an L shape
      if (!((abs(x2 - x1) == 2 && abs(y2 - y1) == 1) || (abs(x2 - x1) == 1 && abs(y2 - y1) == 2))) {
        return 0;
      }
      break;

    // Bishops
    case 'b':
      // Check if there are any pieces blocking the path of the bishop
      if (abs(x2 - x1) == abs(y2 - y1)) {
        int x_dir = (x2 - x1) / abs(x2 - x1);
        int y_dir = (y2 - y1) / abs(y2 - y1);
        for (int i = 1; i < abs(x2 - x1); i++) {
          if (board[x1 + (i * x_dir)][y1 + (i * y_dir)] != ' ') {
            return 0;
          }
        }
      } else {
        // Bishop is not moving along diagonal
        return 0;
      }
      break;

    // Queens
    case 'q':
      // Check if the queen is moving along diagonal
      if (abs(x2 - x1) == abs(y2 - y1)) {
        int x_dir = (x2 - x1) / abs(x2 - x1);
        int y_dir = (y2 - y1) / abs(y2 - y1);
        for (int i = 1; i < abs(x2 - x1); i++) {
          if (board[x1 + (i * x_dir)][y1 + (i * y_dir)] != ' ') {
            return 0;
          }
        }
      }
      // Check if the queen is not blocked by any piece
      else if (x1 == x2) {
        for (int i = y1 + ((y2 - y1) / abs(y2 - y1)); i != y2; i += ((y2 - y1) / abs(y2 - y1))) {
          if (board[x1][i] != ' ') {
            return 0;
          }
        }
      } else if (y1 == y2) {
        for (int i = x1 + ((x2 - x1) / abs(x2 - x1)); i != x2; i += ((x2 - x1) / abs(x2 - x1))) {
          if (board[i][y1] != ' ') {
            return 0;
          }
        }
      }
      // Not moving on either diagonals or a straight path
      else {
        return 0;
      }
      break;

    // King
    case 'k':
      // Check if the king is moving only one spot
      if (!((abs(x2 - x1) == 1 && abs(y2 - y1) == 1) || (abs(x2 - x1) == 1 && abs(y2 - y1) == 0) || (abs(x2 - x1) == 0 && abs(y2 - y1) == 1))) {
        return 0;
      }
      break;

    // Empty space
    case ' ':
      return 0;
  }

  // Make move and check if king is in check
  char temp_piece = board[x2][y2];
  board[x2][y2] = board[x1][y1];
  board[x1][y1] = ' ';
  int in_check = check_king(board, x2, y2, x1, y1);
  board[x1][y1] = board[x2][y2];
  board[x2][y2] = temp_piece;

  if (in_check) {
    return 0;
  }

  return 1;
}

// Check if the king is in check after a move
int check_king(char board[BOARD_SIZE][BOARD_SIZE], int king_x, int king_y, int opponent_x, int opponent_y) {
  // Check for check from pawns
  int x_dir = (isupper(board[king_x][king_y])) ? -1 : 1;
  if (king_x + x_dir >= 0 && king_x + x_dir < BOARD_SIZE && king_y - 1 >= 0 && board[king_x + x_dir][king_y - 1] == 'p') {
    return 1;
  }
  if (king_x + x_dir >= 0 && king_x + x_dir < BOARD_SIZE && king_y + 1 < BOARD_SIZE && board[king_x + x_dir][king_y + 1] == 'p') {
    return 1;
  }

  // Check for check from knights
  for (int i = -2; i <= 2; i++) {
    if (i == 0) {
      continue;
    }
    for (int j = -2; j <= 2; j++) {
      if (j == 0 || abs(i) == abs(j)) {
        continue;
      }
      if (king_x + i >= 0 && king_x + i < BOARD_SIZE && king_y + j >= 0 && king_y + j < BOARD_SIZE && board[king_x + i][king_y + j] == 'n') {
        return 1;
      }
    }
  }

  // Check for check from bishops or queen
  for (int i = 1; i < BOARD_SIZE; i++) {
    if (king_x - i >= 0 && king_y - i >= 0 && (board[king_x - i][king_y - i] == 'b' || board[king_x - i][king_y - i] == 'q')) {
      return 1;
    }
    if (king_x - i >= 0 && king_y + i < BOARD_SIZE && (board[king_x - i][king_y + i] == 'b' || board[king_x - i][king_y + i] == 'q')) {
      return 1;
    }
    if (king_x + i < BOARD_SIZE && king_y - i >= 0 && (board[king_x + i][king_y - i] == 'b' || board[king_x + i][king_y - i] == 'q')) {
      return 1;
    }
    if (king_x + i < BOARD_SIZE && king_y + i < BOARD_SIZE && (board[king_x + i][king_y + i] == 'b' || board[king_x + i][king_y + i] == 'q')) {
      return 1;
    }
  }

  // Check for check from rooks or queen
  for (int i = 1; i < BOARD_SIZE; i++) {
    if (king_x - i >= 0 && (board[king_x - i][king_y] == 'r' || board[king_x - i][king_y] == 'q')) {
      return 1;
    }
    if (king_x + i < BOARD_SIZE && (board[king_x + i][king_y] == 'r' || board[king_x + i][king_y] == 'q')) {
      return 1;
    }
    if (king_y - i >= 0 && (board[king_x][king_y - i] == 'r' || board[king_x][king_y - i] == 'q')) {
      return 1;
    }
    if (king_y + i < BOARD_SIZE && (board[king_x][king_y + i] == 'r' || board[king_x][king_y + i] == 'q')) {
      return 1;
    }
  }

  // Check for check from king
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0) {
        continue;
      }
      if (king_x + i >= 0 && king_x + i < BOARD_SIZE && king_y + j >= 0 && king_y + j < BOARD_SIZE && board[king_x + i][king_y + j] == 'k') {
        return 1;
      }
    }
  }

  return 0;
}