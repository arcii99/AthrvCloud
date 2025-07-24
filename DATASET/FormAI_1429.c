//FormAI DATASET v1.0 Category: Checkers Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define EMPTY 0
#define BLACK_PIECE 1
#define BLACK_KING 2
#define WHITE_PIECE -1
#define WHITE_KING -2

int board[BOARD_SIZE][BOARD_SIZE];

// Helper function to print the board
void print_board() {
  printf("\n");
  printf("  0 1 2 3 4 5 6 7\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i);
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == EMPTY) {
        printf("_ ");
      } else if (board[i][j] == BLACK_PIECE) {
        printf("b ");
      } else if (board[i][j] == BLACK_KING) {
        printf("B ");
      } else if (board[i][j] == WHITE_PIECE) {
        printf("w ");
      } else if (board[i][j] == WHITE_KING) {
        printf("W ");
      }
    }
    printf("%d\n", i);
  }
  printf("  0 1 2 3 4 5 6 7\n");
}

// Helper function to check if the given row and col are valid indices for the board
int is_valid(int row, int col) {
  return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE;
}

// Helper function to initialize the board
void initialize_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if ((i + j) % 2 == 0) {
        if (i < 3) {
          board[i][j] = WHITE_PIECE;
        } else if (i > 4) {
          board[i][j] = BLACK_PIECE;
        } else {
          board[i][j] = EMPTY;
        }
      } else {
        board[i][j] = EMPTY;
      }
    }
  }
}

// Helper function to move a piece from the source cell to the destination cell
void move_piece(int src_row, int src_col, int dest_row, int dest_col) {
  int temp = board[src_row][src_col];
  board[src_row][src_col] = EMPTY;
  board[dest_row][dest_col] = temp;
}

// Helper function to determine if a piece can be moved diagonally to the left
int can_move_left(int row, int col) {
  int player = board[row][col];
  if (player == BLACK_PIECE || player == BLACK_KING) {
    // Check if there is a white piece diagonally to the left
    if (is_valid(row + 1, col - 1) && (board[row + 1][col - 1] == WHITE_PIECE || board[row + 1][col - 1] == WHITE_KING)) {
      // Check if the destination cell is empty
      if (is_valid(row + 2, col - 2) && board[row + 2][col - 2] == EMPTY) {
        return 1;
      }
    }
  } else if (player == WHITE_PIECE || player == WHITE_KING) {
    // Check if there is a black piece diagonally to the left
    if (is_valid(row - 1, col - 1) && (board[row - 1][col - 1] == BLACK_PIECE || board[row - 1][col - 1] == BLACK_KING)) {
      // Check if the destination cell is empty
      if (is_valid(row - 2, col - 2) && board[row - 2][col - 2] == EMPTY) {
        return 1;
      }
    }
  }
  return 0;
}

// Helper function to determine if a piece can be moved diagonally to the right
int can_move_right(int row, int col) {
  int player = board[row][col];
  if (player == BLACK_PIECE || player == BLACK_KING) {
    // Check if there is a white piece diagonally to the right
    if (is_valid(row + 1, col + 1) && (board[row + 1][col + 1] == WHITE_PIECE || board[row + 1][col + 1] == WHITE_KING)) {
      // Check if the destination cell is empty
      if (is_valid(row + 2, col + 2) && board[row + 2][col + 2] == EMPTY) {
        return 1;
      }
    }
  } else if (player == WHITE_PIECE || player == WHITE_KING) {
    // Check if there is a black piece diagonally to the right
    if (is_valid(row - 1, col + 1) && (board[row - 1][col + 1] == BLACK_PIECE || board[row - 1][col + 1] == BLACK_KING)) {
      // Check if the destination cell is empty
      if (is_valid(row - 2, col + 2) && board[row - 2][col + 2] == EMPTY) {
        return 1;
      }
    }
  }
  return 0;
}

// Helper function to determine if a piece can be jumped diagonally to the left
int can_jump_left(int row, int col) {
  int player = board[row][col];
  if (player == BLACK_PIECE || player == BLACK_KING) {
    // Check if there is a white piece diagonally to the left
    if (is_valid(row + 1, col - 1) && (board[row + 1][col - 1] == WHITE_PIECE || board[row + 1][col - 1] == WHITE_KING)) {
      // Check if the destination cell is empty
      if (is_valid(row + 2, col - 2) && board[row + 2][col - 2] == EMPTY) {
        return 1;
      }
    }
  } else if (player == WHITE_PIECE || player == WHITE_KING) {
    // Check if there is a black piece diagonally to the left
    if (is_valid(row - 1, col - 1) && (board[row - 1][col - 1] == BLACK_PIECE || board[row - 1][col - 1] == BLACK_KING)) {
      // Check if the destination cell is empty
      if (is_valid(row - 2, col - 2) && board[row - 2][col - 2] == EMPTY) {
        return 1;
      }
    }
  }
  return 0;
}

// Helper function to determine if a piece can be jumped diagonally to the right
int can_jump_right(int row, int col) {
  int player = board[row][col];
  if (player == BLACK_PIECE || player == BLACK_KING) {
    // Check if there is a white piece diagonally to the right
    if (is_valid(row + 1, col + 1) && (board[row + 1][col + 1] == WHITE_PIECE || board[row + 1][col + 1] == WHITE_KING)) {
      // Check if the destination cell is empty
      if (is_valid(row + 2, col + 2) && board[row + 2][col + 2] == EMPTY) {
        return 1;
      }
    }
  } else if (player == WHITE_PIECE || player == WHITE_KING) {
    // Check if there is a black piece diagonally to the right
    if (is_valid(row - 1, col + 1) && (board[row - 1][col + 1] == BLACK_PIECE || board[row - 1][col + 1] == BLACK_KING)) {
      // Check if the destination cell is empty
      if (is_valid(row - 2, col + 2) && board[row - 2][col + 2] == EMPTY) {
        return 1;
      }
    }
  }
  return 0;
}

// Helper function to determine if a given piece has any possible moves or jumps
int has_moves(int row, int col) {
  if (can_move_left(row, col) || can_move_right(row, col) || can_jump_left(row, col) || can_jump_right(row, col)) {
    return 1;
  }
  return 0;
}

// Helper function to update the piece to a king if it reaches the other side of the board
void update_king(int row, int col) {
  int player = board[row][col];
  if (player == BLACK_PIECE && row == BOARD_SIZE - 1) {
    board[row][col] = BLACK_KING;
  } else if (player == WHITE_PIECE && row == 0) {
    board[row][col] = WHITE_KING;
  }
}

// Helper function to move a piece or make a jump
void make_move(int src_row, int src_col, int dest_row, int dest_col) {
  int player = board[src_row][src_col];
  if (abs(dest_col - src_col) > 1) {
    // Jump
    int jumped_row = (dest_row + src_row) / 2;
    int jumped_col = (dest_col + src_col) / 2;
    move_piece(src_row, src_col, dest_row, dest_col);
    board[jumped_row][jumped_col] = EMPTY;
  } else {
    // Move
    move_piece(src_row, src_col, dest_row, dest_col);
  }
  update_king(dest_row, dest_col);
}

// Helper function to determine if the given player has any pieces left
int has_pieces_left(int player) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == player || board[i][j] == player * 2) {
        if (has_moves(i, j)) {
          return 1;
        }
      }
    }
  }
  return 0;
}

int main() {
  initialize_board();
  print_board();

  int turn = BLACK_PIECE;
  while (1) {
    int src_row, src_col, dest_row, dest_col;

    // Get source cell
    printf("\n");
    printf("%s's turn\n", turn == BLACK_PIECE ? "Black" : "White");
    printf("Enter source row and column:\n");
    if (scanf("%d %d", &src_row, &src_col) != 2 || !is_valid(src_row, src_col) || board[src_row][src_col] != turn && board[src_row][src_col] != turn * 2) {
      printf("Invalid input\n");
      fflush(stdin); //flushing buffer
      continue;
    }

    // Get destination cell
    printf("Enter destination row and column:\n");
    if (scanf("%d %d", &dest_row, &dest_col) != 2 || !is_valid(dest_row, dest_col) || board[dest_row][dest_col] != EMPTY) {
      printf("Invalid input\n");
      fflush(stdin);//flushing buffer
      continue;
    }

    // Check if the move is valid
    if (abs(dest_col - src_col) > 2) {
      printf("Invalid move\n");
      fflush(stdin);//flushing buffer
      continue;
    } else if (abs(dest_col - src_col) == 2) {
      // Jump
      int jumped_row = (dest_row + src_row) / 2;
      int jumped_col = (dest_col + src_col) / 2;
      if (board[jumped_row][jumped_col] != -turn && board[jumped_row][jumped_col] != -turn * 2) {
        printf("Invalid move\n");
        fflush(stdin);//flushing buffer
        continue;
      }
    } else if (board[src_row][src_col] == BLACK_PIECE && dest_row <= src_row || board[src_row][src_col] == WHITE_PIECE && dest_row >= src_row) {
      printf("Invalid move\n");
      fflush(stdin);//flushing buffer
      continue;
    }

    // Make the move
    make_move(src_row, src_col, dest_row, dest_col);
    print_board();

    // Check if the game has ended
    if (!has_pieces_left(BLACK_PIECE)) {
      printf("White wins\n");
      break;
    } else if (!has_pieces_left(WHITE_PIECE)) {
      printf("Black wins\n");
      break;
    }

    // Switch turn
    turn = -turn;
  }
  return 0;
}