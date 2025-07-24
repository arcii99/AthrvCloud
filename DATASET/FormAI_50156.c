//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];

void init_board() {
  for (int i = 0; i < BOARD_SIZE; ++i) {
    for (int j = 0; j < BOARD_SIZE; ++j) {
      board[i][j] = '-';
    }
  }
}

void print_board() {
  for (int i = 0; i < BOARD_SIZE; ++i) {
    for (int j = 0; j < BOARD_SIZE; ++j) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

int check_winner() {
  for (int i = 0; i < BOARD_SIZE; ++i) {
    /* Check rows */
    if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      if (board[i][0] == 'X') return 1;
      else return 2;
    }
    /* Check columns */
    if (board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
      if (board[0][i] == 'X') return 1;
      else return 2;
    }
  }
  /* Check diagonals */
  if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    if (board[0][0] == 'X') return 1;
    else return 2;
  }
  if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    if (board[0][2] == 'X') return 1;
    else return 2;
  }
  /* Check for tie game */
  for (int i = 0; i < BOARD_SIZE; ++i) {
    for (int j = 0; j < BOARD_SIZE; ++j) {
      if (board[i][j] == '-') return 0;
    }
  }
  return 3;
}

int minimax(int depth, int player) {
  int score;
  int best_score;
  int best_row = -1;
  int best_col = -1;
  int result = check_winner();
  if (result != 0) {
    if (result == 1) return -10 + depth;
    else if (result == 2) return 10 - depth;
    else return 0;
  }
  best_score = player == 1 ? -100 : 100;
  for (int i = 0; i < BOARD_SIZE; ++i) {
    for (int j = 0; j < BOARD_SIZE; ++j) {
      if (board[i][j] == '-') {
        board[i][j] = player == 1 ? 'X' : 'O';
        score = minimax(depth + 1, player == 1 ? 2 : 1);
        board[i][j] = '-';
        if (player == 1 && score > best_score) {
          best_score = score;
          best_row = i;
          best_col = j;
        } else if (player == 2 && score < best_score) {
          best_score = score;
          best_row = i;
          best_col = j;
        }
      }
    }
  }
  if (depth == 0) {
    return best_row * BOARD_SIZE + best_col;
  }
  return best_score;
}

void player_turn() {
  int row, col, index;
  printf("Enter row and column index (0-2): ");
  scanf("%d %d", &row, &col);
  if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != '-') {
    printf("Invalid move. Please try again.\n");
    player_turn();
  } else {
    board[row][col] = 'X';
  }
}

void ai_turn() {
  int index = minimax(0, 2);
  int row = index / BOARD_SIZE;
  int col = index % BOARD_SIZE;
  printf("AI plays at row %d, column %d\n", row, col);
  board[row][col] = 'O';
}

int main() {
  int turn = 1;
  srand(time(NULL));
  init_board();
  printf("Welcome to Tic Tac Toe!\n");
  printf("Player is X, AI is O.\n");
  printf("Player goes first.\n");
  while (check_winner() == 0) {
    printf("=======================\n");
    printf("Turn %d\n", turn);
    printf("=======================\n");
    if (turn % 2 == 1) {
      print_board();
      player_turn();
    } else {
      ai_turn();
    }
    ++turn;
  }
  print_board();
  int winner = check_winner();
  if (winner == 1) printf("Player wins!\n");
  else if (winner == 2) printf("AI wins!\n");
  else printf("Tie game!\n");
  return 0;
}