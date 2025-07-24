//FormAI DATASET v1.0 Category: Chess engine ; Style: beginner-friendly
#include<stdio.h>

int board[8][8] = {{-1,-1,-1,-1,-1,-1,-1,-1},
                   {-1,-1,-1,-1,-1,-1,-1,-1},
                   {-1,-1,-1,-1,-1,-1,-1,-1},
                   {-1,-1,-1, 0, 1,-1,-1,-1},
                   {-1,-1,-1, 1, 0,-1,-1,-1},
                   {-1,-1,-1,-1,-1,-1,-1,-1},
                   {-1,-1,-1,-1,-1,-1,-1,-1},
                   {-1,-1,-1,-1,-1,-1,-1,-1}};

int kingPos[2][2];

void movePiece(int fromX, int fromY, int toX, int toY) {
  if (board[toX][toY] != -1) {
    printf("Illegal Move\n");
    return;
  }

  board[toX][toY] = board[fromX][fromY];
  board[fromX][fromY] = -1;

  if (board[toX][toY] == 1) {
    kingPos[0][0] = toX;
    kingPos[0][1] = toY;
  } else if (board[toX][toY] == 2) {
    kingPos[1][0] = toX;
    kingPos[1][1] = toY;
  }
}

int checkWin() {
  int king1X = kingPos[0][0];
  int king1Y = kingPos[0][1];
  int king2X = kingPos[1][0];
  int king2Y = kingPos[1][1];

  // if white king is dead
  if (board[king1X][king1Y] == -1) {
    printf("Black wins!\n");
    return 1;
  }

  // if black king is dead
  if (board[king2X][king2Y] == -1) {
    printf("White wins!\n");
    return 1;
  }

  return 0;
}

void printBoard() {
  printf("\n");
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board[i][j] == -1) {
        printf("  ");
      } else if (board[i][j] == 0) {
        printf("o ");
      } else if (board[i][j] == 1) {
        printf("w ");
      } else if (board[i][j] == 2) {
        printf("b ");
      }
    }
    printf("\n");
  }
  printf("\n");
}

int main(){

  kingPos[0][0] = 3;
  kingPos[0][1] = 3;
  kingPos[1][0] = 3;
  kingPos[1][1] = 4;
  
  printBoard();

  movePiece(3, 3, 2, 3);
  printBoard();
  
  movePiece(3, 4, 4, 4);
  printBoard();
  
  movePiece(2, 3, 1, 4);
  printBoard();
  
  movePiece(4, 4, 7, 4);
  printBoard();
  
  movePiece(1, 4, 2, 4);
  printBoard();

  if(checkWin()) {
    return 0;
  }

  return 0;
}