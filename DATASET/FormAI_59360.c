//FormAI DATASET v1.0 Category: Checkers Game ; Style: active
#include <stdio.h>
#include <stdlib.h>

void initialize_board(char board[][8]);
int check_move(char board[][8], int x1, int y1, int x2, int y2, int player);
int is_jump_available(char board[][8], int x, int y, int player);
void make_move(char board[][8], int x1, int y1, int x2, int y2);
int check_winner(char board[][8], int player);

int main()
{
  // Initializing the game board
  char board[8][8];
  initialize_board(board);

  // Setting up player information
  char player1[30], player2[30];
  printf("Please enter the name of player 1: ");
  scanf("%s", player1);
  printf("Please enter the name of player 2: ");
  scanf("%s", player2);
  printf("\n");

  // Printing the empty board
  printf("   0 1 2 3 4 5 6 7\n");
  printf("  -----------------\n");
  for (int i = 0; i < 8; i++) {
    printf("%d |", i);
    for (int j = 0; j < 8; j++) {
      printf(" %c", board[i][j]);
    }
    printf(" |\n");
  }
  printf("  -----------------\n");

  // Game loop
  int winner = 0;
  int player = 1;
  int x1, y1, x2, y2;
  
  while (!winner) {
    // Getting player's move
    printf("%s's turn: ", player == 1 ? player1 : player2);
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    // Checking if the move is valid
    int move_type = check_move(board, x1, y1, x2, y2, player);
    if (move_type == 0) {
      printf("Invalid move.\n");
      continue;
    }

    // Making move
    make_move(board, x1, y1, x2, y2);
    if (move_type == 2) {
      // If the move was a jump, check if more jumps are available
      while (is_jump_available(board, x2, y2, player)) {
        printf("Jump available. ");
        scanf("%d %d", &x1, &y1);
        if (check_move(board, x2, y2, x1, y1, player) == 1) {
          x2 = x1;
          y2 = y1;
          make_move(board, x1, y1, x2, y2);
        } else {
          printf("Invalid jump. Turn over.\n");
          break;
        }
      }
    }

    // Checking for winner
    winner = check_winner(board, player);
    if (winner == 1) {
      printf("%s wins!\n", player1);
    } else if (winner == 2) {
      printf("%s wins!\n", player2);
    }

    // Printing the board
    printf("   0 1 2 3 4 5 6 7\n");
    printf("  -----------------\n");
    for (int i = 0; i < 8; i++) {
      printf("%d |", i);
      for (int j = 0; j < 8; j++) {
        printf(" %c", board[i][j]);
      }
      printf(" |\n");
    }
    printf("  -----------------\n");

    // Switching players
    player = player == 1 ? 2 : 1;
  }

  return 0;
}

// Function to initialize the game board
void initialize_board(char board[][8]) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if ((i + j) % 2 == 0) {
        if (i < 3) {
          board[i][j] = 'B';
        } else if (i > 4) {
          board[i][j] = 'R';
        } else {
          board[i][j] = ' ';
        }
      } else {
        board[i][j] = ' ';
      }
    }
  }
}

// Function to check if a move is valid
int check_move(char board[][8], int x1, int y1, int x2, int y2, int player) {
  if (x1 < 0 || x1 > 7 || x2 < 0 || x2 > 7 || y1 < 0 || y1 > 7 || y2 < 0 || y2 > 7) {
    // If coordinates are out of bounds
    return 0;
  }

  if (board[x2][y2] != ' ') {
    // If target square is not empty
    return 0;
  }

  if (player == 1 && board[x1][y1] != 'R') {
    // If the player is 1 but the piece is not red
    return 0;
  }

  if (player == 2 && board[x1][y1] != 'B') {
    // If the player is 2 but the piece is not black
    return 0;
  }

  if (abs(x2 - x1) != abs(y2 - y1)) {
    // If the move is not diagonal
    return 0;
  }

  if (abs(x2 - x1) == 1) {
    // If the move is not a jump and distance is 1
    return 1;
  }

  // If the move is a jump and distance is 2
  if (board[(x1 + x2) / 2][(y1 + y2) / 2] == ' ') {
    // If the space between the two squares is empty
    return 0;
  }

  if (player == 1 && board[(x1 + x2) / 2][(y1 + y2) / 2] != 'B' && board[(x1 + x2) / 2][(y1 + y2) / 2] != 'b') {
    // If the player is 1 and the jumped piece is not black or black king
    return 0;
  }

  if (player == 2 && board[(x1 + x2) / 2][(y1 + y2) / 2] != 'R' && board[(x1 + x2) / 2][(y1 + y2) / 2] != 'r') {
    // If the player is 2 and the jumped piece is not red or red king
    return 0;
  }

  return 2;
}

// Function to check if more jumps are available for a piece
int is_jump_available(char board[][8], int x, int y, int player) {
  if (player == 1) {
    if (x < 2 || y < 2 || x > 5 || y > 5) {
      // If the piece is at the edge of the board, it cannot jump anymore
      return 0;
    }
    if ((board[x - 1][y - 1] == 'B' || board[x - 1][y - 1] == 'b') && board[x - 2][y - 2] == ' ') {
      // If the diagonal piece is black and the space is empty, a jump is available
      return 1;
    }
    if ((board[x - 1][y + 1] == 'B' || board[x - 1][y + 1] == 'b') && board[x - 2][y + 2] == ' ') {
      return 1;
    }
    if (board[x][y] == 'r') {
      if ((board[x + 1][y - 1] == 'B' || board[x + 1][y - 1] == 'b') && board[x + 2][y - 2] == ' ') {
        return 1;
      }
      if ((board[x + 1][y + 1] == 'B' || board[x + 1][y + 1] == 'b') && board[x + 2][y + 2] == ' ') {
        return 1;
      }
    }
  }

  if (player == 2) {
    if (x < 2 || y < 2 || x > 5 || y > 5) {
      return 0;
    }
    if ((board[x + 1][y - 1] == 'R' || board[x + 1][y - 1] == 'r') && board[x + 2][y - 2] == ' ') {
      return 1;
    }
    if ((board[x + 1][y + 1] == 'R' || board[x + 1][y + 1] == 'r') && board[x + 2][y + 2] == ' ') {
      return 1;
    }
    if (board[x][y] == 'b') {
      if ((board[x - 1][y - 1] == 'R' || board[x - 1][y - 1] == 'r') && board[x - 2][y - 2] == ' ') {
        return 1;
      }
      if ((board[x - 1][y + 1] == 'R' || board[x - 1][y + 1] == 'r') && board[x - 2][y + 2] == ' ') {
        return 1;
      }
    }
  }

  return 0;
}

// Function to perform the move on the board
void make_move(char board[][8], int x1, int y1, int x2, int y2) {
  board[x2][y2] = board[x1][y1];
  board[x1][y1] = ' ';
  if (x2 == 0 && board[x2][y2] == 'R') {
    board[x2][y2] = 'r';
  }
  if (x2 == 7 && board[x2][y2] == 'B') {
    board[x2][y2] = 'b';
  }
  if (abs(x2 - x1) == 2) {
    board[(x1 + x2) / 2][(y1 + y2) / 2] = ' ';
  }
}

// Function to check if a player has won
int check_winner(char board[][8], int player) {
  int red_pieces = 0, black_pieces = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board[i][j] == 'R' || board[i][j] == 'r') {
        red_pieces++;
      }
      if (board[i][j] == 'B' || board[i][j] == 'b') {
        black_pieces++;
      }
    }
  }
  if (red_pieces == 0) {
    return 2;
  }
  if (black_pieces == 0) {
    return 1;
  }
  return 0;
}