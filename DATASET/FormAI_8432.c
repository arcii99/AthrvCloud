//FormAI DATASET v1.0 Category: Checkers Game ; Style: complete
#include <stdio.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
  int i, j;

  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      if (i < 3 && (i + j) % 2 == 0) {
        board[i][j] = 'R';
      } else if (i > 4 && (i + j) % 2 == 0) {
        board[i][j] = 'B';
      } else {
        board[i][j] = ' ';
      }
    }
  }
}

void print_board() {
  int i, j;

  printf("  A B C D E F G H\n");
  printf("  ---------------\n");

  for (i = 0; i < BOARD_SIZE; i++) {
    printf("%d|", i + 1);

    for (j = 0; j < BOARD_SIZE; j++) {
      printf("%c|", board[i][j]);
    }

    printf("%d\n", i + 1);
  }

  printf("  ---------------\n");
  printf("  A B C D E F G H\n");
}

int is_valid_move(int row, int col, int new_row, int new_col, char player) {
  int row_diff = new_row - row;
  int col_diff = new_col - col;

  if (board[new_row][new_col] != ' ') {
    return 0;
  }

  if (player == 'R' && row_diff < 0) {
    return 0;
  } else if (player == 'B' && row_diff > 0) {
    return 0;
  }

  if (row_diff == 1 && col_diff == 1) {
    return 1;
  } else if (row_diff == 2 && col_diff == 2) {
    int middle_row = (new_row + row) / 2;
    int middle_col = (new_col + col) / 2;

    if (board[middle_row][middle_col] != player &&
        board[middle_row][middle_col] != ' ') {
      return 1;
    }
  }

  return 0;
}

void make_move(int row, int col, int new_row, int new_col, char player) {
  int row_diff = new_row - row;
  int col_diff = new_col - col;

  board[new_row][new_col] = player;
  board[row][col] = ' ';

  if (row_diff == 2 && col_diff == 2) {
    int middle_row = (new_row + row) / 2;
    int middle_col = (new_col + col) / 2;

    board[middle_row][middle_col] = ' ';
  }
}

int is_game_over() {
  int i, j;
  int red_count = 0, black_count = 0;

  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == 'R' || board[i][j] == 'K') {
        red_count++;
      } else if (board[i][j] == 'B' || board[i][j] == 'Q') {
        black_count++;
      }
    }
  }

  return red_count == 0 || black_count == 0;
}

int main() {
  char player = 'R';
  int game_over = 0;
  char move[5];

  initialize_board();

  while (!game_over) {
    print_board();

    printf("\n%c's turn. Enter move (e.g. 'A1 B2'): ", player);
    scanf("%s", move);

    int col1 = move[0] - 'A';
    int row1 = move[1] - '1';
    int col2 = move[3] - 'A';
    int row2 = move[4] - '1';

    if (is_valid_move(row1, col1, row2, col2, player)) {
      make_move(row1, col1, row2, col2, player);

      if (player == 'R' && row2 == BOARD_SIZE - 1) {
        board[row2][col2] = 'K';
      } else if (player == 'B' && row2 == 0) {
        board[row2][col2] = 'Q';
      }

      if (player == 'R') {
        player = 'B';
      } else if (player == 'B') {
        player = 'R';
      }

      game_over = is_game_over();
    } else {
      printf("Invalid move. Please try again.\n");
    }
  }

  print_board();

  if (player == 'R') {
    printf("Game over. Winner: Black\n");
  } else {
    printf("Game over. Winner: Red\n");
  }

  return 0;
}