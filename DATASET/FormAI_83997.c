//FormAI DATASET v1.0 Category: Checkers Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8 //8x8 board
#define RED 'R'
#define BLACK 'B'
#define KING 'K'
#define EMPTY '-'

typedef struct _checkers_board {
  char board[SIZE][SIZE];
  int turn; //0 for red, 1 for black
} CheckersBoard;

void initialize_board(CheckersBoard* cboard) {
  int i, j;
  cboard->turn = 0;
  for(i=0;i<SIZE;i++) {
    for(j=0;j<SIZE;j++) {
      if((i+j)%2 == 0) {
        if(i < 3) cboard->board[i][j] = BLACK;
        else if(i > 4) cboard->board[i][j] = RED;
        else cboard->board[i][j] = EMPTY;   
      }
      else cboard->board[i][j] = EMPTY;
    }
  }
}

void display_board(CheckersBoard* cboard) {
  printf("\n-------CHECKERS GAME-------\n");
  printf("       BLACK (B)           \n"); 
  printf(" -------------------------\n");
  for(int i=0;i<SIZE;i++) {
    printf("%d |", SIZE-i);
    for(int j=0;j<SIZE;j++) {
      printf(" %c |", cboard->board[i][j]);
    }
    printf("\n -------------------------\n");
  }
  printf("  | A | B | C | D | E | F | G | H |\n");
  printf("       RED (R)             \n\n");
}

int in_range(int i, int j) {
  return (i >= 0 && i < SIZE && j >= 0 && j < SIZE);
}

int can_jump(CheckersBoard* cboard, int i, int j) {
  char player = cboard->turn ? BLACK : RED;
  char opponent = cboard->turn ? RED : BLACK;
  //check if the player's piece can jump
  if(cboard->board[i][j] == player || cboard->board[i][j] == player+KING) {
    int row_step = cboard->turn ? -1 : 1; //direction of movement
    //check if it can jump in all four directions
    if(in_range(i+2*row_step, j-2) && cboard->board[i+row_step][j-1] == opponent && cboard->board[i+2*row_step][j-2] == EMPTY) return 1; //left jump
    if(in_range(i+2*row_step, j+2) && cboard->board[i+row_step][j+1] == opponent && cboard->board[i+2*row_step][j+2] == EMPTY) return 1; //right jump
    if(cboard->board[i][j] == player+KING) { //can jump backwards as well
      if(in_range(i-2*row_step, j-2) && cboard->board[i-row_step][j-1] == opponent && cboard->board[i-2*row_step][j-2] == EMPTY) return 1; //left jump
      if(in_range(i-2*row_step, j+2) && cboard->board[i-row_step][j+1] == opponent && cboard->board[i-2*row_step][j+2] == EMPTY) return 1; //right jump
    }
  }
  return 0;
}

int can_move(CheckersBoard* cboard, int i, int j) {
  char player = cboard->turn ? BLACK : RED;
  char opponent = cboard->turn ? RED : BLACK;
  //check if the player's piece can move
  if(cboard->board[i][j] == player || cboard->board[i][j] == player+KING) {
    int row_step = cboard->turn ? -1 : 1; //direction of movement
    if(in_range(i+row_step, j-1) && cboard->board[i+row_step][j-1] == EMPTY) return 1; //left move
    if(in_range(i+row_step, j+1) && cboard->board[i+row_step][j+1] == EMPTY) return 1; //right move
    if(cboard->board[i][j] == player+KING) { //can move backwards as well
      if(in_range(i-row_step, j-1) && cboard->board[i-row_step][j-1] == EMPTY) return 1; //left move
      if(in_range(i-row_step, j+1) && cboard->board[i-row_step][j+1] == EMPTY) return 1; //right move
    }
  }
  return 0;
}

void make_move(CheckersBoard* cboard, int i, int j, int ni, int nj) {
  char temp = cboard->board[i][j];
  cboard->board[i][j] = EMPTY;
  cboard->board[ni][nj] = temp;
  //check if the piece has become a king
  char player = cboard->turn ? BLACK : RED;
  if(ni == (cboard->turn ? SIZE-1 : 0) && cboard->board[ni][nj] == player) cboard->board[ni][nj] = player+KING;
}

void make_jump(CheckersBoard* cboard, int i, int j, int ni, int nj) {
  char temp = cboard->board[i][j];
  cboard->board[i][j] = EMPTY;
  cboard->board[ni][nj] = temp;
  //check if the piece has become a king
  char player = cboard->turn ? BLACK : RED;
  if(ni == (cboard->turn ? SIZE-1 : 0) && cboard->board[ni][nj] == player) cboard->board[ni][nj] = player+KING;
  //remove the opponent's piece
  int row_step = cboard->turn ? -1 : 1; //direction of movement
  int col_step = nj < j ? -1 : 1; //direction of movement
  cboard->board[i+row_step][j+col_step] = EMPTY;
}

int check_game_over(CheckersBoard* cboard) {
  char player = cboard->turn ? BLACK : RED;
  char opponent = cboard->turn ? RED : BLACK;
  int i, j;
  //check if the player still has any pieces left
  for(i=0;i<SIZE;i++) {
    for(j=0;j<SIZE;j++) {
      if(cboard->board[i][j] == player || cboard->board[i][j] == player+KING) return 0;
    }
  }
  return 1;
}

void play_turn(CheckersBoard* cboard) {
  display_board(cboard);
  char player = cboard->turn ? BLACK : RED;
  char opponent = cboard->turn ? RED : BLACK;
  printf("It is %c's turn.\n", player);
  int i, j, ni, nj, valid_move = 0;
  while(!valid_move) {
    printf("Enter the coordinates of the piece you want to move: ");
    scanf("%d %d", &i, &j);
    if(!in_range(i, j)) {
      printf("That is an invalid position. Please try again.\n");
      continue;
    }
    if(cboard->board[i][j] != player && cboard->board[i][j] != player+KING) {
      printf("That is not your piece. Please try again.\n");
      continue;
    }
    if(can_jump(cboard, i, j)) {
      printf("You must make a jump. Enter the coordinates of the square you want to jump to: ");
      scanf("%d %d", &ni, &nj);
      if(!in_range(ni, nj)) {
        printf("That is an invalid position. Please try again.\n");
        continue;
      }
      if(ni == i || nj == j || (ni-i)*(ni-i) != (nj-j)*(nj-j) || cboard->board[ni][nj] != EMPTY) {
        printf("That is an invalid jump. Please try again.\n");
        continue;
      }
      int row_step = cboard->turn ? -1 : 1; //direction of movement
      int col_step = nj < j ? -1 : 1; //direction of movement
      if(cboard->board[i+row_step][j+col_step] != opponent && cboard->board[i+row_step][j-col_step] != opponent && cboard->board[i-row_step][j+col_step] != opponent && cboard->board[i-row_step][j-col_step] != opponent) {
        printf("You cannot jump over an empty square. Please try again.\n");
        continue;
      }
      make_jump(cboard, i, j, ni, nj);
      if(can_jump(cboard, ni, nj)) {
        printf("You can jump again with the same piece. ");
        i = ni;
        j = nj;
        continue;
      }
      else valid_move = 1;
    }
    else {
      printf("Enter the coordinates of the square you want to move to: ");
      scanf("%d %d", &ni, &nj);
      if(!in_range(ni, nj)) {
        printf("That is an invalid position. Please try again.\n");
        continue;
      }
      if(ni == i || nj == j || (ni-i)*(ni-i) != (nj-j)*(nj-j) || cboard->board[ni][nj] != EMPTY) {
        printf("That is an invalid move. Please try again.\n");
        continue;
      }
      if(!can_move(cboard, i, j)) {
        printf("That piece cannot move. Please try again.\n");
        continue;
      }
      make_move(cboard, i, j, ni, nj);
      valid_move = 1;
    }
  }
  if(check_game_over(cboard)) {
    display_board(cboard);
    printf("Game over. %c wins!\n", player);
    exit(0);
  }
  cboard->turn = !cboard->turn; //switch turns
}

int main() {
  CheckersBoard cboard;
  initialize_board(&cboard);
  while(1) {
    play_turn(&cboard);
  }
  return 0;
}