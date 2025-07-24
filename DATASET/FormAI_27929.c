//FormAI DATASET v1.0 Category: Checkers Game ; Style: portable
#include <stdio.h>
#define BOARD_SIZE 8 // size of the checkers board

int board[BOARD_SIZE][BOARD_SIZE] = {0}; // Initialize board

void initialize_board(){
  // initialize the checkers board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (i % 2 == 0) {
            if (j % 2 == 0) board[i][j] = 0;
            else board[i][j] = -1; 
        } 
        else {
            if (j % 2 == 1) board[i][j] = 0;
            else board[i][j] = -1;
        }
    }
  }
}

void print_board(){
  // print the checkers board with current pieces
  printf("\n   ");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i);
  }
  printf("\n  ");
  for (int i = 0; i < BOARD_SIZE; i++){
    printf("--");
  }
  printf("\n");
  for (int i = 0; i < BOARD_SIZE; i++){
    printf("%d| ", i);
    for (int j = 0; j < BOARD_SIZE; j++){
      if (board[i][j] == -1) printf("  ");
      else printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

int move_piece(int row, int col, int new_row, int new_col){
  // move the piece to the new location
  if (board[new_row][new_col] != 0) return 0; // can't move to a non-empty space
  if (new_row < 0 || new_row >= BOARD_SIZE || new_col < 0 || new_col >= BOARD_SIZE) return 0; // can't move off the board
  if (board[row][col] == 1) { // if moving a red piece
    if (new_row != row - 1) return 0; // red pieces can only move one row up
    if (new_col != col - 1 && new_col != col + 1) return 0; // red pieces can only move diagonally
    board[new_row][new_col] = board[row][col];
    board[row][col] = 0;
    return 1;
  }
  else if (board[row][col] == 2) { // if moving a black piece
    if (new_row != row + 1) return 0; // black pieces can only move one row down
    if (new_col != col - 1 && new_col != col + 1) return 0; // black pieces can only move diagonally
    board[new_row][new_col] = board[row][col];
    board[row][col] = 0;
    return 1;
  }
  else if (board[row][col] == 3) { // if moving a king(red) piece
    if (new_row != row - 1 && new_row != row + 1) return 0; // king pieces can move one row up or down
    if (new_col != col - 1 && new_col != col + 1) return 0; // king pieces can only move diagonally
    board[new_row][new_col] = board[row][col];
    board[row][col] = 0;
    return 1;
  }
  else if (board[row][col] == 4) { // if moving a king(black) piece
    if (new_row != row - 1 && new_row != row + 1) return 0; // king pieces can move one row up or down
    if (new_col != col - 1 && new_col != col + 1) return 0; // king pieces can only move diagonally
    board[new_row][new_col] = board[row][col];
    board[row][col] = 0;
    return 1;
  }
  return 0;
}

int main(){
  char player1[50], player2[50];
  initialize_board();
  printf("Enter Player1 name: ");
  scanf("%s", player1);
  printf("Enter Player2 name: ");
  scanf("%s", player2);

  int playerTurn = 1; // 1 for player 1 turn, 2 for player 2 turn
  while (1) {
    printf("\n%s's turn:\n", playerTurn == 1 ? player1 : player2 );
    print_board();
    int row, col, new_row, new_col;
    printf("Enter Row: ");
    scanf("%d", &row);
    printf("Enter Column: ");
    scanf("%d", &col);
    printf("Enter New Row: ");
    scanf("%d", &new_row);
    printf("Enter New Column: ");
    scanf("%d", &new_col);
    int moveResult = move_piece(row, col, new_row, new_col);
    if (!moveResult) {
      printf("Invalid move.\n");
      continue;
    }
    if (playerTurn == 1) playerTurn = 2;
    else playerTurn = 1;
  }

  return 0;
}