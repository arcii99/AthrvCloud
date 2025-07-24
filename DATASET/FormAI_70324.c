//FormAI DATASET v1.0 Category: Checkers Game ; Style: automated
#include <stdio.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE] = {
  { 0, -1,  0, -1,  0, -1,  0, -1},
  {-1,  0, -1,  0, -1,  0, -1,  0},
  { 0, -1,  0, -1,  0, -1,  0, -1},
  { 0,  0,  0,  0,  0,  0,  0,  0},
  { 0,  0,  0,  0,  0,  0,  0,  0},
  { 1,  0,  1,  0,  1,  0,  1,  0},
  { 0,  1,  0,  1,  0,  1,  0,  1},
  { 1,  0,  1,  0,  1,  0,  1,  0}
};

void print_board() {
  printf("  0 1 2 3 4 5 6 7\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i);
    for (int j = 0; j < BOARD_SIZE; j++) {
      switch(board[i][j]) {
        case -1:
          printf("X ");
          break;
        case 1:
          printf("O ");
          break;
        case 2:
          printf("K ");
          break;
        case -2:
          printf("K ");
          break;
        default:
          printf(". ");
          break;
      }
    }
    printf("\n");
  }
}

int is_move_valid(int x0, int y0, int x1, int y1, int player) {
  if (x1 < 0 || x1 >= BOARD_SIZE || y1 < 0 || y1 >= BOARD_SIZE)
    return 0; // out of bounds
  if (board[x1][y1] != 0)
    return 0; // destination is not empty
  if (player == 1 && x0 > x1)
    return 0; // white can only move down
  if (player == -1 && x0 < x1)
    return 0; // black can only move up
  if (board[x0][y0] == 1 && x1 - x0 != 1)
    return 0; // white can only move diagonal by 1
  if (board[x0][y0] == -1 && x0 - x1 != 1)
    return 0; // black can only move diagonal by 1

  // check for capture moves
  int dx = x1 - x0;
  int dy = y1 - y0;
  if (dx == 2) {
    if (dy == -2 && board[x0+1][y0-1] == -player)
      return 1; // black piece captured
    if (dy == 2 && board[x0+1][y0+1] == -player)
      return 1; // black piece captured
  } else if (dx == -2) {
    if (dy == -2 && board[x0-1][y0-1] == -player)
      return 1; // white piece captured
    if (dy == 2 && board[x0-1][y0+1] == -player)
      return 1; // white piece captured
  }

  return 1;
}

void apply_move(int x0, int y0, int x1, int y1, int player) {
  board[x1][y1] = board[x0][y0];
  board[x0][y0] = 0;

  if (player == 1 && x1 == 0)
    board[x1][y1] = 2; // white piece promoted to king
  else if (player == -1 && x1 == BOARD_SIZE-1)
    board[x1][y1] = -2; // black piece promoted to king

  // check for capture moves
  int dx = x1 - x0;
  int dy = y1 - y0;;
  if (dx == 2) {
    if (dy == -2) {
      board[x0+1][y0-1] = 0; // captured black piece
    }
    if (dy == 2) {
      board[x0+1][y0+1] = 0; // captured black piece
    }
  } else if (dx == -2) {
    if (dy == -2) {
      board[x0-1][y0-1] = 0; // captured white piece
    }
    if (dy == 2) {
      board[x0-1][y0+1] = 0; // captured white piece
    }
  }
}

void make_move(int x0, int y0, int x1, int y1, int player) {
  if (is_move_valid(x0, y0, x1, y1, player)) {
    apply_move(x0, y0, x1, y1, player);
  } else {
    printf("Invalid move!\n");
  }
}

int main() {
  int turn = 1; // 1=white, -1=black
  char buffer[256];

  while(1) {
    printf("\n\nTurn: %s\n", turn == 1 ? "WHITE" : "BLACK");
    print_board();

    printf("Enter move (e.g. 3,4->2,5): ");
    fgets(buffer, 256, stdin);

    int x0, y0, x1, y1;
    if (sscanf(buffer, "%d,%d->%d,%d", &x0, &y0, &x1, &y1) != 4) {
      printf("Invalid input format.\n");
      continue;
    }

    make_move(x0, y0, x1, y1, turn);

    // check for win
    int white_count = 0, black_count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
      for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[i][j] == 1 || board[i][j] == 2)
          white_count++;

        if (board[i][j] == -1 || board[i][j] == -2)
          black_count++;
      }
    }

    if (black_count == 0) {
      printf("WHITE WINS!\n");
      break;
    }

    if (white_count == 0) {
      printf("BLACK WINS!\n");
      break;
    }

    turn = -turn; // switch turns
  }

  return 0;
}