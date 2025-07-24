//FormAI DATASET v1.0 Category: Checkers Game ; Style: surprised
#include <stdio.h>

int main() {
  printf("Surprise! Here's a C Checkers Game\n");

  // Game initialization
  char board[8][8]; // The game board
  int currentPlayer = 1; // Player 1 starts
  int finished = 0; // Game not finished
  
  // Set the pieces on the board
  int i, j;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      if (i % 2 == j % 2) {
        if (i < 3) {
          board[i][j] = 'X'; // Player 1 piece
        } else if (i > 4) {
          board[i][j] = 'O'; // Player 2 piece
        } else {
          board[i][j] = ' '; // Empty square
        }
      } else {
        board[i][j] = ' '; // Empty square
      }
    }
  }

  // Game loop
  while (!finished) {
    // Print the current state of the game board
    printf("  a b c d e f g h\n");
    printf(" +----------------+\n");
    for (i = 0; i < 8; i++) {
      printf("%d|", i + 1);
      for (j = 0; j < 8; j++) {
        printf("%c|", board[i][j]);
      }
      printf("%d\n", i + 1);
    }
    printf(" +----------------+\n");
    
    // Get the player's move
    printf("Player %d, enter your move: ", currentPlayer);
    char input[5];
    scanf("%s", input);

    // Convert the input to board coordinates
    int row = input[1] - '1';
    int col = input[0] - 'a';

    // Check if the move is valid
    if (input[2] == '-') {
      // Normal move
      int dx, dy;
      if (currentPlayer == 1) {
        dx = -1;
      } else {
        dx = 1;
      }
      if (board[row][col] == 'X' || board[row][col] == 'O') {
        printf("Invalid move: square occupied\n");
      } else if (col < 1 || col > 6 || row < 0 || row > 7) {
        printf("Invalid move: out of bounds\n");
      } else if (board[row + dx][col - 1] != ' ' || board[row + dx][col + 1] != ' ') {
        printf("Invalid move: can't jump over pieces\n");
      } else {
        // Valid move, update the board
        board[row][col] = currentPlayer == 1 ? 'X' : 'O';
        currentPlayer = currentPlayer == 1 ? 2 : 1;
      }
    } else if (input[2] == 'x') {
      // Capture move
      int dy = input[3] - col; // horizontal displacement
      int dx = currentPlayer == 1 ? -1 : 1; // vertical displacement
      int sr = row + dx; // start row
      int sc = col + dy; // start column
      int er = row + 2*dx; // end row
      int ec = col + 2*dy; // end column
      if (board[row][col] == 'X' || board[row][col] == 'O') {
        printf("Invalid move: square occupied\n");
      } else if (col < 2 || col > 5 || row < 0 || row > 6) {
        printf("Invalid move: out of bounds\n");
      } else if (board[sr][sc] == ' ' || board[sr][sc] == (currentPlayer == 1 ? 'O' : 'X') || board[er][ec] != ' ') {
        printf("Invalid move: can't capture\n");
      } else {
        // Valid move, update the board
        board[row][col] = currentPlayer == 1 ? 'X' : 'O';
        board[sr][sc] = ' ';
        board[er][ec] = currentPlayer == 1 ? 'X' : 'O';
        currentPlayer = currentPlayer == 1 ? 2 : 1;
      }
    } else {
      // Invalid input
      printf("Invalid move: incorrect format\n");
    }

    // Check if the game is finished
    int xCount = 0, oCount = 0;
    for (i = 0; i < 8; i++) {
      for (j = 0; j < 8; j++) {
        if (board[i][j] == 'X') {
          xCount++;
        } else if (board[i][j] == 'O') {
          oCount++;
        }
      }
    }
    if (xCount == 0 || oCount == 0) {
      // A player has no pieces left, game over
      printf("Game over! Player %d wins.\n", currentPlayer == 1 ? 2 : 1);
      finished = 1;
    }
  }
  
  return 0;
}