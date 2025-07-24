//FormAI DATASET v1.0 Category: Checkers Game ; Style: scientific
#include <stdio.h>
#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE]; // The game board
int player1Pieces = 12, player2Pieces = 12; // Number of remaining pieces for each player
int currentPlayer = 1; // Keeps track of whose turn it is
int pieceSelected = 0; // Keeps track of if a piece has been selected
int xSelected, ySelected; // The coordinates of the currently selected piece

void initBoard() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if ((i + j) % 2 == 0 && i < 3) 
        board[i][j] = '2'; // Player 2 pieces
      else if ((i + j) % 2 == 0 && i > 4)
        board[i][j] = '1'; // Player 1 pieces
      else
        board[i][j] = ' '; // Empty squares
    }
  }
}

void printBoard() {
  printf("\n   0 1 2 3 4 5 6 7\n"); // Print column numbers
  printf("  +---------------+\n"); // Top border
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i); // Row number
    printf("|");
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c|", board[i][j]); // Print each square with borders
    }
    printf("%d ", i); // Row number
    printf("\n");
    printf("  +---------------+\n");
  }
  printf("   0 1 2 3 4 5 6 7\n"); // Print column numbers
}

int movePiece(int x, int y, int newX, int newY) {
  if (newX < 0 || newY < 0 || newX >= BOARD_SIZE || newY >= BOARD_SIZE) {
    // The new position is outside the board
    return 0;
  }
  if (board[newX][newY] != ' ') {
    // The new position is already occupied
    return 0;
  }
  if (board[x][y] == '1' && newX > x) {
    // Player 1 can only move pieces upwards
    return 0;
  }
  if (board[x][y] == '2' && newX < x) {
    // Player 2 can only move pieces downwards
    return 0;
  }
  if (abs(newX - x) == 1 && abs(newY - y) == 1) {
    // Regular move, no capture
    board[newX][newY] = board[x][y];
    board[x][y] = ' ';
    return 1;
  }
  if (abs(newX - x) == 2 && abs(newY - y) == 2) {
    // Capture move
    int capturedX = (newX + x) / 2;
    int capturedY = (newY + y) / 2;
    if ((board[x][y] == '1' && board[capturedX][capturedY] == '2') ||
        (board[x][y] == '2' && board[capturedX][capturedY] == '1')) {
      // The captured piece belongs to the other player
      board[newX][newY] = board[x][y];
      board[x][y] = ' ';
      board[capturedX][capturedY] = ' ';
      if (board[newX][newY] == '1')
        player2Pieces--;
      else
        player1Pieces--;
      return 2;
    }
    else {
      // The captured piece belongs to the same player
      return 0;
    }
  }
  else {
    // Not a valid move
    return 0;
  }
}

int checkWinner() {
  if (player1Pieces == 0)
    return 2; // Player 2 wins
  if (player2Pieces == 0)
    return 1; // Player 1 wins
  return 0; // No winner yet
}

int main() {
  initBoard();
  printBoard();

  while(1) {
    int winner = checkWinner();
    if (winner != 0) {
      printf("Game over! Player %d wins.\n", winner);
      break;
    }

    printf("Player %d's turn. ", currentPlayer);

    if (!pieceSelected) {
      printf("Select a piece: ");
      scanf("%d %d", &xSelected, &ySelected);
      if (board[xSelected][ySelected] == ' ' || 
          (board[xSelected][ySelected] == '1' && currentPlayer == 2) ||
          (board[xSelected][ySelected] == '2' && currentPlayer == 1)) {
        // The selected square doesn't contain a piece belonging to the current player
        printf("Invalid selection.\n");
        continue;
      }
      pieceSelected = 1;
    }
    else {
      printf("Move the piece: ");
      int newX, newY;
      scanf("%d %d", &newX, &newY);
      int moveResult = movePiece(xSelected, ySelected, newX, newY);
      if (moveResult == 0) {
        printf("Invalid move.\n");
        continue;
      }
      else if (moveResult == 1) {
        // Regular move, no capture
        pieceSelected = 0;
        if (currentPlayer == 1)
          currentPlayer = 2;
        else
          currentPlayer = 1;
      }
      else {
        // Capture move
        printf("Piece captured! ");
        if (currentPlayer == 1)
          player2Pieces--;
        else
          player1Pieces--;
      }
      if (currentPlayer == 1)
        currentPlayer = 2;
      else
        currentPlayer = 1;
    }

    printBoard();
  }

  return 0;
}