//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 3
#define NO_PLAYER 0
#define AI_PLAYER 1
#define HUMAN_PLAYER 2

int board[BOARD_SIZE][BOARD_SIZE];
bool is_game_over = false;
int winner = NO_PLAYER;

void print_board() {
  printf("\n");

  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      printf(" %c ", board[row][col] == AI_PLAYER ? 'O' :
                           (board[row][col] == HUMAN_PLAYER ? 'X' : ' '));
      if (col != BOARD_SIZE - 1) {
        printf("|");
      }
    }

    printf("\n");

    if (row != BOARD_SIZE - 1) {
      for (int i = 0; i < BOARD_SIZE * 4 - 1; i++) {
        printf("-");
      }

      printf("\n");
    }
  }
}

bool is_valid_move(int row, int col) {
  return !(row < 0 || row >= BOARD_SIZE || col < 0 ||
           col >= BOARD_SIZE || board[row][col] != NO_PLAYER);
}

bool is_winner(int player) {
  for (int row = 0; row < BOARD_SIZE; row++) {
    if (board[row][0] == player && board[row][1] == player &&
        board[row][2] == player) {
      return true;
    }
  }

  for (int col = 0; col < BOARD_SIZE; col++) {
    if (board[0][col] == player && board[1][col] == player &&
        board[2][col] == player) {
      return true;
    }
  }

  if (board[0][0] == player && board[1][1] == player &&
      board[2][2] == player) {
    return true;
  }

  if (board[0][2] == player && board[1][1] == player &&
      board[2][0] == player) {
    return true;
  }

  return false;
}

bool is_board_full() {
  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      if (board[row][col] == NO_PLAYER) {
        return false;
      }
    }
  }

  return true;
}

void ai_move() {
  int best_score = -1000;
  int move_row = -1;
  int move_col = -1;

  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      if (board[row][col] == NO_PLAYER) {
        board[row][col] = AI_PLAYER;
        int score = -minimax(HUMAN_PLAYER, 0);
        board[row][col] = NO_PLAYER;

        if (score > best_score) {
          best_score = score;
          move_row = row;
          move_col = col;
        }
      }
    }
  }

  board[move_row][move_col] = AI_PLAYER;
}

int minimax(int player, int depth) {
  if (is_winner(HUMAN_PLAYER)) {
    return -10 + depth;
  }

  if (is_winner(AI_PLAYER)) {
    return 10 - depth;
  }

  if (is_board_full()) {
    return 0;
  }

  if (player == AI_PLAYER) {
    int best_score = -1000;

    for (int row = 0; row < BOARD_SIZE; row++) {
      for (int col = 0; col < BOARD_SIZE; col++) {
        if (board[row][col] == NO_PLAYER) {
          board[row][col] = AI_PLAYER;
          int score = minimax(HUMAN_PLAYER, depth + 1);
          board[row][col] = NO_PLAYER;

          if (score > best_score) {
            best_score = score;
          }
        }
      }
    }

    return best_score;
  } else {
    int best_score = 1000;

    for (int row = 0; row < BOARD_SIZE; row++) {
      for (int col = 0; col < BOARD_SIZE; col++) {
        if (board[row][col] == NO_PLAYER) {
          board[row][col] = HUMAN_PLAYER;
          int score = minimax(AI_PLAYER, depth + 1);
          board[row][col] = NO_PLAYER;

          if (score < best_score) {
            best_score = score;
          }
        }
      }
    }

    return best_score;
  }
}

void human_move() {
  int row, col;

  do {
    printf("\nEnter row and column (1-3): ");
    scanf("%d %d", &row, &col);
    row--;
    col--;
  } while (!is_valid_move(row, col));

  board[row][col] = HUMAN_PLAYER;
}

void check_game_over() {
  if (is_winner(AI_PLAYER)) {
    is_game_over = true;
    winner = AI_PLAYER;
  } else if (is_winner(HUMAN_PLAYER)) {
    is_game_over = true;
    winner = HUMAN_PLAYER;
  } else if (is_board_full()) {
    is_game_over = true;
  }
}

int main() {
  printf("Welcome to Tic Tac Toe AI Game\n");
  printf("Human player (X) - you will make the first move\n");
  printf("AI player (O) - computer will make the second move\n");

  while (!is_game_over) {
    print_board();
    human_move();
    check_game_over();

    if (!is_game_over) {
      ai_move();
      check_game_over();
    }
  }

  print_board();

  if (winner == NO_PLAYER) {
    printf("Game over. Tie!\n");
  } else if (winner == AI_PLAYER) {
    printf("Game over. You lost!\n");
  } else {
    printf("Game over. You won!\n");
  }

  return 0;
}