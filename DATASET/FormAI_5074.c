//FormAI DATASET v1.0 Category: Table Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLS 6

void print_board(int board[ROWS][COLS]);
int get_input(int board[ROWS][COLS], int player);
int check_win(int board[ROWS][COLS], int player);

int main() {
  int board[ROWS][COLS] = {0}; // initialize the game board to all 0's
  int player = 1;
  int move_count = 0;
  int winner = 0;

  // Seed the random number generator to add some randomness to the coin toss
  srand(time(NULL));

  // Coin toss to determine who goes first
  if (rand() % 2 == 0) {
    player = 1;
  } else {
    player = 2;
  }

  while (move_count < ROWS * COLS && winner == 0) {
    // Print out the current state of the board
    printf("Player %d's turn\n", player);
    print_board(board);

    // Get input from the player
    int column = get_input(board, player);

    // Place the player's piece on the board
    int row;
    for (int i = 0; i < ROWS; i++) {
      if (board[i][column] == 0) {
        board[i][column] = player;
        row = i;
        break;
      }
    }

    // Check if the player has won
    winner = check_win(board, player);

    // Switch to the other player
    if (player == 1) {
      player = 2;
    } else {
      player = 1;
    }

    move_count++;
  }

  // Print out the final state of the board
  printf("Final board:\n");
  print_board(board);

  // Print out the winner or a tie message
  if (winner > 0) {
    printf("Player %d wins!\n", winner);
  } else {
    printf("Tie game!\n");
  }

  return 0;
}

void print_board(int board[ROWS][COLS]) {
  for (int i = ROWS - 1; i >= 0; i--) {
    for (int j = 0; j < COLS; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
  printf("1 2 3 4 5 6\n\n");
}

int get_input(int board[ROWS][COLS], int player) {
  int column;
  do {
    printf("Enter a column (1-6): ");
    scanf("%d", &column);
    column--; // adjust for 0-based indexing

    // Check if the column is valid and not already full
    if (column < 0 || column >= COLS) {
      printf("Invalid column. Please enter a number between 1 and 6.\n");
    } else if (board[ROWS-1][column] != 0) {
      printf("That column is already full. Please choose another column.\n");
    }
  } while (column < 0 || column >= COLS || board[ROWS-1][column] != 0);

  return column;
}

int check_win(int board[ROWS][COLS], int player) {
  // Check horizontal win
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS - 3; j++) {
      if (board[i][j] == player && board[i][j+1] == player && board[i][j+2] == player && board[i][j+3] == player) {
        return player;
      }
    }
  }

  // Check vertical win
  for (int j = 0; j < COLS; j++) {
    for (int i = 0; i < ROWS - 3; i++) {
      if (board[i][j] == player && board[i+1][j] == player && board[i+2][j] == player && board[i+3][j] == player) {
        return player;
      }
    }
  }

  // Check diagonal win (top-left to bottom-right)
  for (int i = 0; i < ROWS - 3; i++) {
    for (int j = 0; j < COLS - 3; j++) {
      if (board[i][j] == player && board[i+1][j+1] == player && board[i+2][j+2] == player && board[i+3][j+3] == player) {
        return player;
      }
    }
  }

  // Check diagonal win (bottom-left to top-right)
  for (int i = 3; i < ROWS; i++) {
    for (int j = 0; j < COLS - 3; j++) {
      if (board[i][j] == player && board[i-1][j+1] == player && board[i-2][j+2] == player && board[i-3][j+3] == player) {
        return player;
      }
    }
  }

  // No winner yet
  return 0;
}