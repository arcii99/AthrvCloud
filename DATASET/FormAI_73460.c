//FormAI DATASET v1.0 Category: Checkers Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Player types
#define EMPTY 0
#define RED 1
#define BLACK 2

// Game status
#define PLAYING 0
#define RED_WON 1
#define BLACK_WON 2

// Initial board configuration (0 for empty cell)
int board[BOARD_SIZE][BOARD_SIZE] = {
    {0, BLACK, 0, BLACK, 0, BLACK, 0, BLACK},
    {BLACK, 0, BLACK, 0, BLACK, 0, BLACK, 0},
    {0, BLACK, 0, BLACK, 0, BLACK, 0, BLACK},
    {EMPTY, 0, EMPTY, 0, EMPTY, 0, EMPTY, 0},
    {0, EMPTY, 0, EMPTY, 0, EMPTY, 0, EMPTY},
    {RED, 0, RED, 0, RED, 0, RED, 0},
    {0, RED, 0, RED, 0, RED, 0, RED},
    {RED, 0, RED, 0, RED, 0, RED, 0}};

// Function to display the board
void display_board() {
  int row, col;

  // Print column numbers
  printf("\n    ");
  for (col = 0; col < BOARD_SIZE; col++) {
    printf(" %d  ", col + 1);
  }
  printf("\n");

  // Print row numbers and board values
  printf("  ");
  for (col = 0; col < BOARD_SIZE * 4; col++) {
    printf("-");
  }
  printf("\n");

  for (row = 0; row < BOARD_SIZE; row++) {
    printf("%d| ", row + 1);
    for (col = 0; col < BOARD_SIZE; col++) {
      switch (board[row][col]) {
        case EMPTY:
          printf("   | ");
          break;
        case RED:
          printf(" R | ");
          break;
        case BLACK:
          printf(" B | ");
          break;
      }
    }
    printf("\n  ");
    for (col = 0; col < BOARD_SIZE * 4; col++) {
      printf("-");
    }
    printf("\n");
  }
}

// Function to check if a move is valid
int is_valid_move(int player, int start_row, int start_col, int end_row, int end_col) {
  if (end_row < 0 || end_row >= BOARD_SIZE ||
      end_col < 0 || end_col >= BOARD_SIZE ||
      board[end_row][end_col] != EMPTY) {
    return 0;
  }

  if (player == RED) {
    if (end_row >= start_row) {
      return 0;
    }

    // Regular move
    if (start_row - end_row == 1 && abs(start_col - end_col) == 1) {
      return 1;
    }

    // Capture move
    if (start_row - end_row == 2 && abs(start_col - end_col) == 2 &&
        board[start_row - 1][(start_col + end_col) / 2] == BLACK) {
      return 2;
    }
  } else if (player == BLACK) {
    if (end_row <= start_row) {
      return 0;
    }

    // Regular move
    if (end_row - start_row == 1 && abs(start_col - end_col) == 1) {
      return 1;
    }

    // Capture move
    if (end_row - start_row == 2 && abs(start_col - end_col) == 2 &&
        board[start_row + 1][(start_col + end_col) / 2] == RED) {
      return 2;
    }
  }

  return 0;
}

// Function to make a move
int make_move(int player, int start_row, int start_col, int end_row, int end_col) {
  int move_type = is_valid_move(player, start_row, start_col, end_row, end_col);

  if (move_type == 0) {
    return 0;
  }

  board[end_row][end_col] = player;
  board[start_row][start_col] = EMPTY;

  if (move_type == 2) {
    // Capture move
    int captured_row = (start_row + end_row) / 2;
    int captured_col = (start_col + end_col) / 2;
    board[captured_row][captured_col] = EMPTY;
  }

  return 1;
}

// Function to check if a player has won the game
int check_win(int player) {
  int row, col;

  for (row = 0; row < BOARD_SIZE; row++) {
    for (col = 0; col < BOARD_SIZE; col++) {
      if (board[row][col] == player) {
        int move_type;

        if (player == RED) {
          // Check regular move
          move_type = is_valid_move(player, row, col, row - 1, col - 1);
          if (move_type != 0) {
            return PLAYING;
          }
          move_type = is_valid_move(player, row, col, row - 1, col + 1);
          if (move_type != 0) {
            return PLAYING;
          }

          // Check capture move
          move_type = is_valid_move(player, row, col, row - 2, col - 2);
          if (move_type != 0 && board[row - 1][col - 1] == BLACK) {
            return PLAYING;
          }
          move_type = is_valid_move(player, row, col, row - 2, col + 2);
          if (move_type != 0 && board[row - 1][col + 1] == BLACK) {
            return PLAYING;
          }
        } else if (player == BLACK) {
          // Check regular move
          move_type = is_valid_move(player, row, col, row + 1, col - 1);
          if (move_type != 0) {
            return PLAYING;
          }
          move_type = is_valid_move(player, row, col, row + 1, col + 1);
          if (move_type != 0) {
            return PLAYING;
          }

          // Check capture move
          move_type = is_valid_move(player, row, col, row + 2, col - 2);
          if (move_type != 0 && board[row + 1][col - 1] == RED) {
            return PLAYING;
          }
          move_type = is_valid_move(player, row, col, row + 2, col + 2);
          if (move_type != 0 && board[row + 1][col + 1] == RED) {
            return PLAYING;
          }
        }
      }
    }
  }

  return player;
}

int main() {
  int game_status = PLAYING;
  int current_player = RED;
  int start_row, start_col, end_row, end_col;

  // Game loop
  while (game_status == PLAYING) {
    display_board();

    // Get move from player
    printf("\nPlayer %d's turn:", current_player);
    printf("\nStart row: ");
    scanf("%d", &start_row);
    printf("Start col: ");
    scanf("%d", &start_col);
    printf("End row: ");
    scanf("%d", &end_row);
    printf("End col: ");
    scanf("%d", &end_col);

    // Make move
    if (!make_move(current_player, start_row - 1, start_col - 1, end_row - 1, end_col - 1)) {
      printf("\nInvalid move. Please try again.\n");
      continue;
    }

    // Check win condition
    game_status = check_win(current_player);
    if (game_status != PLAYING) {
      display_board();

      if (game_status == RED_WON) {
        printf("\nPlayer RED won the game!\n");
      } else if (game_status == BLACK_WON) {
        printf("\nPlayer BLACK won the game!\n");
      }
    } else {
      // Switch to next player
      current_player = (current_player == RED) ? BLACK : RED;
    }
  }

  return 0;
}