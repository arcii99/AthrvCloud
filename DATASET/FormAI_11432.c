//FormAI DATASET v1.0 Category: Table Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10

void display_board(int board[BOARD_SIZE][BOARD_SIZE]) {
  int i, j;
  printf("\n");
  printf("    ");
  for (i = 0; i < BOARD_SIZE; i++) {
    printf("%d  ", i);
  }
  printf("\n");
  for (i = 0; i < BOARD_SIZE; i++) {
    printf("%d | ", i);
    for (j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == -1) {
        printf("  | ");
      } else if (board[i][j] == 0) {
        printf(". | ");
      } else {
        printf("%d | ", board[i][j]);
      }
    }
    printf("\n");
  }
  printf("\n");
}

int get_random_number(int n) {
  srand(time(NULL));
  return rand() % n;
}

int get_next_move(int player, int board[BOARD_SIZE][BOARD_SIZE]) {
  int row, col;
  printf("Player %d, enter row number: ", player);
  scanf("%d", &row);
  printf("Player %d, enter column number: ", player);
  scanf("%d", &col);
  if (row < 0 || col < 0 || row >= BOARD_SIZE || col >= BOARD_SIZE) {
    printf("Invalid move! Try again.\n");
    return get_next_move(player, board);
  }
  if (board[row][col] != 0) {
    printf("Position already taken! Try again.\n");
    return get_next_move(player, board);
  }
  return row * BOARD_SIZE + col;
}

int check_winner(int board[BOARD_SIZE][BOARD_SIZE], int last_move) {
  int i, j, row, col, player;

  row = last_move / BOARD_SIZE;
  col = last_move % BOARD_SIZE;
  player = board[row][col];

  // Check row for winner
  for (i = 0; i < BOARD_SIZE; i++) {
    if (board[row][i] != player) {
      break;
    }
    if (i == BOARD_SIZE - 1) {
      return player;
    }
  }

  // Check column for winner
  for (i = 0; i < BOARD_SIZE; i++) {
    if (board[i][col] != player) {
      break;
    }
    if (i == BOARD_SIZE - 1) {
      return player;
    }
  }

  // Check diagonal for winner
  if (row == col) {
    for (i = 0; i < BOARD_SIZE; i++) {
      if (board[i][i] != player) {
        break;
      }
      if (i == BOARD_SIZE - 1) {
        return player;
      }
    }
  }

  // Check anti-diagonal for winner
  if (row + col == BOARD_SIZE - 1) {
    for (i = 0; i < BOARD_SIZE; i++) {
      if (board[i][(BOARD_SIZE - 1) - i] != player) {
        break;
      }
      if (i == BOARD_SIZE - 1) {
        return player;
      }
    }
  }

  // Check if board is full
  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == 0) {
        return 0;
      }
    }
  }

  // Game is a draw
  return -1;
}

int main() {
  int board[BOARD_SIZE][BOARD_SIZE], i, j, move, player = 1, winner = 0;

  // Initialize board with default values
  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = 0;
    }
  }

  display_board(board);

  // Game loop
  while (winner == 0) {
    move = get_next_move(player, board);
    board[move / BOARD_SIZE][move % BOARD_SIZE] = player;
    display_board(board);
    winner = check_winner(board, move);
    if (winner == 0) {
      player = (player == 1) ? 2 : 1;
    }
  }

  if (winner == -1) {
    printf("Game ended in a draw!\n");
  } else {
    printf("Player %d is the winner!\n", winner);
  }

  return 0;
}