//FormAI DATASET v1.0 Category: Table Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define ROWS 6
#define COLS 7
#define PLAYER1 'O'
#define PLAYER2 'X'



char board[ROWS][COLS];
int moveCount = 0;

void initializeBoard(){
  for (int i = 0; i < ROWS; i++){
    for (int j = 0; j < COLS; j++){
      board[i][j] = '_';
    }
  }
}

void displayBoard(){
  for (int i = 0; i < ROWS; i++){
    printf("|");
    for (int j = 0; j < COLS; j++){
      printf("%c|", board[i][j]);
    }
    printf("\n");
  }
  printf("---------------\n");
  printf(" 1 2 3 4 5 6 7\n");
}

void makeMove(char player, int col){
  int row = ROWS - 1;
  while (board[row][col] != '_' && row >= 0){
    row--;
  }
  if (row < 0){
    printf("Column is already full, please choose another.\n");
  }
  else{
    board[row][col] = player;
    moveCount++;
  }
}

int checkWinningMove(int row, int col, char player){
  int moveCount = 0;
  for (int i = 0; i < ROWS; i++){
    if (board[i][col] == player){
      moveCount++;
      if (moveCount == 4){
        return 1;
      }
    }
    else{
      moveCount = 0;
    }
  }

  moveCount = 0;
  for (int j = 0; j < COLS; j++){
    if (board[row][j] == player){
      moveCount++;
      if (moveCount == 4){
        return 1;
      }
    }
    else{
      moveCount = 0;
    }
  }

  moveCount = 0;
  int i = row;
  int j = col;
  while (i < ROWS && j < COLS && board[i][j] == player){
    moveCount++;
    if (moveCount == 4){
      return 1;
    }
    i++;
    j++;
  }
  i = row - 1;
  j = col - 1;
  while (i >= 0 && j >= 0 && board[i][j] == player){
    moveCount++;
    if (moveCount == 4){
      return 1;
    }
    i--;
    j--;
  }

  moveCount = 0;
  i = row;
  j = col;
  while (i < ROWS && j >= 0 && board[i][j] == player){
    moveCount++;
    if (moveCount == 4){
      return 1;
    }
    i++;
    j--;
  }
  i = row - 1;
  j = col + 1;
  while (i >= 0 && j < COLS && board[i][j] == player){
    moveCount++;
    if (moveCount == 4){
      return 1;
    }
    i--;
    j++;
  }

  return 0;
}

char checkWinner(){
  for (int i = 0; i < ROWS; i++){
    for (int j = 0; j < COLS; j++){
      if (board[i][j] != '_'){
        if (checkWinningMove(i, j, board[i][j])) {
          return board[i][j];
        }
      }
    }
  }
  return '_';
}

int main () {
  char player = PLAYER1;
  int column;
  char winner;
  initializeBoard();
  printf("Welcome to the Connect Four Game!\n");
  printf("Player 1: 'O'\nPlayer 2: 'X'\n");
  while (moveCount < ROWS * COLS){
    displayBoard();
    printf("It is Player %c's turn. Enter column (1-7): ", player);
    scanf("%d", &column);
    column--;
    makeMove(player, column);
    winner = checkWinner();
    if (winner != '_'){
      printf("Player %c wins the game!\n", winner);
      displayBoard();
      return 0;
    }
    if (player == PLAYER1){
      player = PLAYER2;
    }
    else  {
      player = PLAYER1;
    }
  }
  printf("The game is a draw!\n");
  displayBoard();
  return 0;
}