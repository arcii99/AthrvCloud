//FormAI DATASET v1.0 Category: Checkers Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ROW 8
#define MAX_COL 8

// Board array to record the position of the checkers.
int board[MAX_ROW][MAX_COL];

// Player's turn.
int player_turn = 1;

// Function prototypes.
void create_board();
void print_board();
bool is_valid_move(int row, int col, int dest_row, int dest_col);
bool check_capture(int row, int col, int dest_row, int dest_col);
bool is_king(int row, int col);
void move_piece(int row, int col, int dest_row, int dest_col);
bool is_game_over();

void create_board() {
  // Initialize the board array to have all 0's as starting positions.
  for (int i = 0; i < MAX_ROW; i++) {
    for (int j = 0; j < MAX_COL; j++) {
      board[i][j] = 0;
    }
  }

  // Set the player one's pieces positions.
  for (int i = 0; i < 3; i++) {
    if (i % 2 == 0) {
      for (int j = 1; j < MAX_COL; j += 2) {
        board[i][j] = 1;
      }
    } else {
      for (int j = 0; j < MAX_COL; j += 2) {
        board[i][j] = 1;
      }
    }
  }

  // Set the player two's pieces positions.
  for (int i = 5; i < MAX_ROW; i++) {
    if (i % 2 == 0) {
      for (int j = 1; j < MAX_COL; j += 2) {
        board[i][j] = 2;
      }
    } else {
      for (int j = 0; j < MAX_COL; j += 2) {
        board[i][j] = 2;
      }
    }
  }
}

void print_board() {
  // Display the current board state.
  printf("\n   \t1\t2\t3\t4\t5\t6\t7\t8\n");
  for (int i = 0; i < MAX_ROW; i++) {
    printf("\n%d\t", i + 1);
    for (int j = 0; j < MAX_COL; j++) {
      printf("%d\t", board[i][j]);
    }
  }
  printf("\n");
}

bool is_valid_move(int row, int col, int dest_row, int dest_col) {
  // Check if the destination position is out of bound.
  if (dest_row < 0 || dest_col < 0 || dest_row >= MAX_ROW || dest_col >= MAX_COL) {
    return false;
  }

  // Check if the player is moving to their own piece.
  if (board[dest_row][dest_col] == player_turn) {
    return false;
  }

  // Check if the player is making a diagonal move.
  if (abs(dest_row - row) != abs(dest_col - col)) {
    return false;
  }

  // Check if the player is moving more than one position diagonally.
  if (abs(dest_row - row) > 2) {
    return false;
  }

  // Check if the player is moving in the correct direction (top for player one, bottom for player two).
  if (player_turn == 1 && dest_row <= row) {
    return false;
  }
  if (player_turn == 2 && dest_row >= row) {
    return false;
  }

  // Check if the player is moving one position diagonally.
  if (abs(dest_row - row) == 1) {
    // Check if the destination position is empty.
    if (board[dest_row][dest_col] == 0) {
      return true;
    } else {
      return false;
    }
  }

  // Check if the player is capturing an opponent's piece.
  if (abs(dest_row - row) == 2) {
    return check_capture(row, col, dest_row, dest_col);
  }

  return true;
}

bool check_capture(int row, int col, int dest_row, int dest_col) {
  // Calculate the position of the captured piece.
  int captured_row = (dest_row + row) / 2;
  int captured_col = (dest_col + col) / 2;

  // Check if the captured piece belongs to the opponent and if the destination position is empty.
  if (board[dest_row][dest_col] == 0 && board[captured_row][captured_col] == (player_turn == 1 ? 2 : 1)) {
    return true;
  } else {
    return false;
  }
}

bool is_king(int row, int col) {
  // Check if the current piece is a king.
  if (player_turn == 1 && row == MAX_ROW - 1) {
    return true;
  }
  if (player_turn == 2 && row == 0) {
    return true;
  }

  return false;
}

void move_piece(int row, int col, int dest_row, int dest_col) {
  // Update the board array with the new positions.
  board[dest_row][dest_col] = board[row][col];
  board[row][col] = 0;

  // Check if the moved piece is a king.
  if (is_king(dest_row, dest_col)) {
    board[dest_row][dest_col] = player_turn + 2;
  }
}

bool is_game_over() {
  // Check if there are no more pieces left for a player.
  bool player_one_lost = true;
  bool player_two_lost = true;
  for (int i = 0; i < MAX_ROW; i++) {
    for (int j = 0; j < MAX_COL; j++) {
      if (board[i][j] == 1 || board[i][j] == 3) {
        player_one_lost = false;
      }
      if (board[i][j] == 2 || board[i][j] == 4) {
        player_two_lost = false;
      }
    }
  }

  if (player_one_lost || player_two_lost) {
    return true;
  } else {
    return false;
  }
}

int main() {
  // Initialize the board.
  create_board();

  // Game loop.
  while (!is_game_over()) {
    // Print the current board state.
    print_board();

    // Get the move inputs from the player.
    int row = 0, col = 0, dest_row = 0, dest_col = 0;
    printf("\nPlayer %d, enter the coordinates of the piece you want to move and the destination coordinates (row_col row_col): ", player_turn);
    if (scanf("%d_%d %d_%d", &row, &col, &dest_row, &dest_col) != 4) {
      printf("Invalid input, please try again.\n");
      continue;
    }

    // Check if the move is valid.
    if (!is_valid_move(row-1, col-1, dest_row-1, dest_col-1)) {
      printf("Invalid move, please try again.\n");
      continue;
    }

    // Move the piece and capture the opponent's piece if applicable.
    move_piece(row-1, col-1, dest_row-1, dest_col-1);
    if (abs(dest_row - row) == 2) {
      int captured_row = (dest_row + row) / 2;
      int captured_col = (dest_col + col) / 2;
      board[captured_row][captured_col] = 0;
    }

    // Switch to the next player's turn.
    player_turn = (player_turn == 1 ? 2 : 1);
  }

  // Print the final board state and announce the winner.
  print_board();
  printf("\nPlayer %d wins!\n", (player_turn == 1 ? 2 : 1));

  return 0;
}