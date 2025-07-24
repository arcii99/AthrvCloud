//FormAI DATASET v1.0 Category: Checkers Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#define BOARD_SIZE 8

// Define player colors
enum Player {
  BLACK, // Player 1
  WHITE // Player 2
};

// Define Piece types
enum Piece {
  NONE,
  BLACK_PIECE,
  BLACK_KING,
  WHITE_PIECE,
  WHITE_KING
};

// Define Board structure
struct Board {
  enum Piece pieces[BOARD_SIZE][BOARD_SIZE];
};

// Initialize the board
void initializeBoard(struct Board* board) {
  // Place black pieces
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      if ((row + col) % 2 == 0) {
        board->pieces[row][col] = BLACK_PIECE;
      }
    }
  }

  // Place white pieces
  for (int row = 5; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      if ((row + col) % 2 == 0) {
        board->pieces[row][col] = WHITE_PIECE;
      }
    }
  }
}

// Print the board
void printBoard(struct Board* board) {
  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      switch(board->pieces[row][col]) {
        case NONE:
          printf("+ ");
          break;
        case BLACK_PIECE:
          printf("b ");
          break;
        case BLACK_KING:
          printf("B ");
          break;
        case WHITE_PIECE:
          printf("w ");
          break;
        case WHITE_KING:
          printf("W ");
          break;
      }
    }
    printf("\n");
  }
}

// Get opposite player
enum Player oppositePlayer(enum Player player) {
  if (player == BLACK) {
    return WHITE;
  } else {
    return BLACK;
  }
}

// Move a piece if it's a valid move
int movePiece(struct Board* board, int fromRow, int fromCol, int toRow, int toCol, enum Player player) {
  // Check if there's a piece at the 'from' location
  if (board->pieces[fromRow][fromCol] == NONE) {
    return 0;
  }

  // Check if the piece is the player's piece
  enum Piece piece = board->pieces[fromRow][fromCol];
  if ((player == BLACK && (piece == WHITE_PIECE || piece == WHITE_KING)) ||
      (player == WHITE && (piece == BLACK_PIECE || piece == BLACK_KING))) {
    return 0;
  }

  // Check if the target location is valid
  int rowDiff = toRow - fromRow;
  int colDiff = toCol - fromCol;
  if (abs(rowDiff) != abs(colDiff)) {
    return 0;
  }

  // Check if the move is a jump
  if (abs(rowDiff) == 2 && abs(colDiff) == 2) {
    int jumpRow = (fromRow + toRow) / 2;
    int jumpCol = (fromCol + toCol) / 2;
    enum Piece jumpedPiece = board->pieces[jumpRow][jumpCol];
    if (jumpedPiece == NONE || 
        (player == BLACK && (jumpedPiece == BLACK_PIECE || jumpedPiece == BLACK_KING)) ||
        (player == WHITE && (jumpedPiece == WHITE_PIECE || jumpedPiece == WHITE_KING))) {
      return 0;
    } else {
      // Jump the piece
      board->pieces[fromRow][fromCol] = NONE;
      if (player == BLACK) {
        board->pieces[toRow][toCol] = BLACK_PIECE;
      } else {
        board->pieces[toRow][toCol] = WHITE_PIECE;
      }
      board->pieces[jumpRow][jumpCol] = NONE;
      return 1;
    }
  }

  // Check if the move is a regular move
  if (abs(rowDiff) == 1 && abs(colDiff) == 1) {
    if (board->pieces[toRow][toCol] != NONE) {
      return 0;
    } else {
      // Move the piece
      board->pieces[fromRow][fromCol] = NONE;
      if (player == BLACK && toRow == BOARD_SIZE-1) {
        board->pieces[toRow][toCol] = BLACK_KING;
      } else if (player == WHITE && toRow == 0) {
        board->pieces[toRow][toCol] = WHITE_KING;
      } else {
        board->pieces[toRow][toCol] = piece;
      }
      return 1;
    }
  }

  return 0;
}

// Check if a player has any valid moves left
int hasValidMoves(struct Board* board, enum Player player) {
  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      if (board->pieces[row][col] != NONE &&
          ((player == BLACK && (board->pieces[row][col] == BLACK_PIECE || board->pieces[row][col] == BLACK_KING)) ||
           (player == WHITE && (board->pieces[row][col] == WHITE_PIECE || board->pieces[row][col] == WHITE_KING)))) {
        // Check regular moves
        int dirs[2];
        if (board->pieces[row][col] == BLACK_PIECE || board->pieces[row][col] == WHITE_PIECE) {
          if (player == BLACK) {
            dirs[0] = 1;
            dirs[1] = -1;
          } else {
            dirs[0] = -1;
            dirs[1] = 1;
          }
        } else {
          dirs[0] = 1;
          dirs[1] = -1;
        }
        for (int i = 0; i < 2; i++) {
          int tRow = row + dirs[i];
          int lCol = col - 1;
          int rCol = col + 1;
          if (tRow >= 0 && tRow < BOARD_SIZE && lCol >= 0 && board->pieces[tRow][lCol] == NONE) {
            return 1;
          }
          if (tRow >= 0 && tRow < BOARD_SIZE && rCol < BOARD_SIZE && board->pieces[tRow][rCol] == NONE) {
            return 1;
          }
        }

        // Check jump moves
        int dirs2[4];
        if (board->pieces[row][col] == BLACK_PIECE || board->pieces[row][col] == WHITE_PIECE) {
          if (player == BLACK) {
            dirs2[0] = 1;
            dirs2[1] = -1;
          } else {
            dirs2[0] = -1;
            dirs2[1] = 1;
          }
        } else {
          dirs2[0] = 1;
          dirs2[1] = -1;
          dirs2[2] = -1;
          dirs2[3] = 1;
        }
        for (int i = 0; i < 4; i++) {
          int tRow = row + 2*dirs2[i];
          int tCol = col + 2*dirs2[(i+1)%4];
          int jRow = row + dirs2[i];
          int jCol = col + dirs2[(i+1)%4];
          if (tRow >= 0 && tRow < BOARD_SIZE && tCol >= 0 && tCol < BOARD_SIZE &&
              board->pieces[tRow][tCol] == NONE &&
              ((player == BLACK && (board->pieces[jRow][jCol] == WHITE_PIECE || board->pieces[jRow][jCol] == WHITE_KING)) ||
               (player == WHITE && (board->pieces[jRow][jCol] == BLACK_PIECE || board->pieces[jRow][jCol] == BLACK_KING)))) {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

// Play the game
void playGame(struct Board* board) {
  enum Player currentPlayer = BLACK;

  while (1) {
    // Print the board
    printBoard(board);

    // Check if the current player has any valid moves
    if (!hasValidMoves(board, currentPlayer)) {
      printf("Player %d has no valid moves left. Game over!\n", currentPlayer);
      break;
    }

    // Get the move from the current player
    int fromRow, fromCol, toRow, toCol;
    printf("Player %d's turn. Enter the from and to locations (row, column): ", currentPlayer);
    scanf("%d %d %d %d", &fromRow, &fromCol, &toRow, &toCol);

    // Move the piece if it's a valid move
    if (!movePiece(board, fromRow, fromCol, toRow, toCol, currentPlayer)) {
      printf("Invalid move. Try again.\n");
      continue;
    }

    // Check if the current player has won
    int hasWon = 1;
    for (int row = 0; row < BOARD_SIZE; row++) {
      for (int col = 0; col < BOARD_SIZE; col++) {
        if (board->pieces[row][col] != NONE &&
            ((currentPlayer == BLACK && (board->pieces[row][col] == WHITE_PIECE || board->pieces[row][col] == WHITE_KING)) ||
             (currentPlayer == WHITE && (board->pieces[row][col] == BLACK_PIECE || board->pieces[row][col] == BLACK_KING)))) {
          hasWon = 0;
          break;
        }
      }
    }
    if (hasWon) {
      printf("Player %d has won the game!\n", currentPlayer);
      break;
    }

    // Switch to the other player
    currentPlayer = oppositePlayer(currentPlayer);
  }
}

// Main function
int main() {
  struct Board board;
  initializeBoard(&board);
  playGame(&board);
  return 0;
}