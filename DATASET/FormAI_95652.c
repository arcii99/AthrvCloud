//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 20
#define DOT 1
#define PACMAN 2
#define GHOST 3

int board[BOARD_SIZE][BOARD_SIZE] = {0};
int pacManRow = 0, pacManCol = 0;
int ghostRow = BOARD_SIZE/2, ghostCol = BOARD_SIZE/2;

void drawBoard() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == DOT) {
        printf(".");
      } else if (board[i][j] == PACMAN) {
        printf("C");
      } else if (board[i][j] == GHOST) {
        printf("G");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

void spawnDots() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] != PACMAN && board[i][j] != GHOST) {
        board[i][j] = DOT;
      }
    }
  }
}

void movePacMan(int direction) {
  board[pacManRow][pacManCol] = 0;
  switch(direction) {
    case 1:
      if (pacManRow > 0) {
        pacManRow--;
      }
      break;
    case 2:
      if (pacManCol < BOARD_SIZE - 1) {
        pacManCol++;
      }
      break;
    case 3:
      if (pacManRow < BOARD_SIZE - 1) {
        pacManRow++;
      }
      break;
    case 4:
      if (pacManCol > 0) {
        pacManCol--;
      }
      break;
    default:
      break;
  }
  if (board[pacManRow][pacManCol] == DOT) {
    board[pacManRow][pacManCol] = PACMAN;
  }
}

int moveGhost() {
  int direction = rand() % 4 + 1;
  board[ghostRow][ghostCol] = 0;
  switch(direction) {
    case 1:
      if (ghostRow > 0) {
        ghostRow--;
      }
      break;
    case 2:
      if (ghostCol < BOARD_SIZE - 1) {
        ghostCol++;
      }
      break;
    case 3:
      if (ghostRow < BOARD_SIZE - 1) {
        ghostRow++;
      }
      break;
    case 4:
      if (ghostCol > 0) {
        ghostCol--;
      }
      break;
    default:
      break;
  }
  board[ghostRow][ghostCol] = GHOST;
  if (ghostRow == pacManRow && ghostCol == pacManCol) {
    return 1;
  }
  return 0;
}

int main() {
  srand(time(NULL));
  spawnDots();
  board[0][0] = PACMAN;
  board[BOARD_SIZE/2][BOARD_SIZE/2] = GHOST;
  drawBoard();
  while(1) {
    int direction;
    printf("Enter direction (1 = up, 2 = right, 3 = down, 4 = left): ");
    scanf("%d", &direction);
    movePacMan(direction);
    if (moveGhost()) {
      printf("Game over! Ghost caught Pac-Man!\n");
      break;
    }
    drawBoard();
  }
  return 0;
}