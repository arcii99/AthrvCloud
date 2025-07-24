//FormAI DATASET v1.0 Category: Checkers Game ; Style: minimalist
#include <stdio.h>
#define BOARD_SIZE 8

void draw_board(int board[BOARD_SIZE][BOARD_SIZE]) {
  printf("\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("|");
      switch (board[i][j]) {
        case 0:
          printf(" ");
          break;
        case 1:
          printf("O");
          break;
        case 2:
          printf("X");
          break;
        case 3:
          printf("K");
          break;
      }
    }
    printf("|");
    printf("\n");
  }
}

int is_valid(int board[BOARD_SIZE][BOARD_SIZE], int i, int j, int a, int b) {
  if (a < 0 || a >= BOARD_SIZE || b < 0 || b >= BOARD_SIZE) {
    return 0;
  }
  if (board[a][b] != 0) {
    return 0;
  }
  if (board[i][j] == 1 && a > i) {
    return 0;
  }
  if (board[i][j] == 2 && a < i) {
    return 0;
  }
  if (abs(a - i) == 2 && abs(b - j) == 2) {
    if (board[(a + i) / 2][(b + j) / 2] == 0) {
      return 0;
    } else {
      return 1;
    }
  }
  if (abs(a - i) == 1 && abs(b - j) == 1) {
    return 1;
  }
  return 0;
}

int can_capture(int board[BOARD_SIZE][BOARD_SIZE], int i, int j) {
  int val = board[i][j];
  if (val == 0 || val == 3) {
    return 0;
  }
  if (val == 1) {
    if (is_valid(board, i, j, i + 2, j - 2) || is_valid(board, i, j, i + 2, j + 2)) {
      return 1;
    }
  } else {
    if (is_valid(board, i, j, i - 2, j - 2) || is_valid(board, i, j, i - 2, j + 2)) {
      return 1;
    }
  }
  return 0;
}

void make_move(int board[BOARD_SIZE][BOARD_SIZE], int i, int j, int a, int b) {
  int val = board[i][j];
  board[i][j] = 0;
  board[a][b] = val;
  if (abs(a - i) == 2) {
    board[(a + i) / 2][(b + j) / 2] = 0;
  }
  if (a == 0 && val == 1) {
    board[a][b] = 3;
  } else if (a == BOARD_SIZE - 1 && val == 2) {
    board[a][b] = 3;
  }
}

int check_win(int board[BOARD_SIZE][BOARD_SIZE]) {
  int num_1 = 0;
  int num_2 = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == 1 || board[i][j] == 3) {
        num_1++;
      } else if (board[i][j] == 2 || board[i][j] == 3) {
        num_2++;
      }
    }
  }
  if (num_1 == 0) {
    return 2;
  } else if (num_2 == 0) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  int board[BOARD_SIZE][BOARD_SIZE] = {
      {0, 2, 0, 2, 0, 2, 0, 2},
      {2, 0, 2, 0, 2, 0, 2, 0},
      {0, 2, 0, 2, 0, 2, 0, 2},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {1, 0, 1, 0, 1, 0, 1, 0},
      {0, 1, 0, 1, 0, 1, 0, 1},
      {1, 0, 1, 0, 1, 0, 1, 0},
  };

  int turn = 1;
  int gameover = 0;
  int winner = 0;
  int oi, oj, ni, nj;

  while (!gameover) {
    draw_board(board);
    printf("Player %d's turn:\n", turn);
    printf("Enter the coordinates of the piece you want to move (x,y):\n");
    scanf("%d,%d", &oi, &oj);
    printf("Enter the coordinates of where you want to move the piece (x,y):\n");
    scanf("%d,%d", &ni, &nj);
    if (is_valid(board, oi, oj, ni, nj)) {
      make_move(board, oi, oj, ni, nj);
      if (!can_capture(board, ni, nj)) {
        turn = (turn == 1) ? 2 : 1;
      }
      winner = check_win(board);
      if (winner != 0) {
        gameover = 1;
      }
    } else {
      printf("Invalid move!\n");
    }
  }
  draw_board(board);
  printf("Player %d wins!\n", winner);

  return 0;
}