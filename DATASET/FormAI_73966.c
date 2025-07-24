//FormAI DATASET v1.0 Category: Checkers Game ; Style: innovative
#include<stdio.h>
#include<stdlib.h>

#define BOARD_SIZE 8

enum piece {EMPTY = 0, RED_PIECE = 1, BLACK_PIECE = 2};
enum player {RED_PLAYER = 1, BLACK_PLAYER = 2};

int board[BOARD_SIZE][BOARD_SIZE] = {0};
int selected_piece = 0;
int selected_piece_row = -1;
int selected_piece_col = -1;
int current_player = RED_PLAYER;
int gameover = 0;

void draw_board() {
  printf(" | 1 2 3 4 5 6 7 8\n");
  printf("_|_________________\n");
  for(int i=0; i<BOARD_SIZE; i++) {
    printf(" %d|", i+1);
    for(int j=0; j<BOARD_SIZE; j++) {
      switch(board[i][j]) {
        case EMPTY:
          printf(" ");
          break;
        case RED_PIECE:
          printf("R");
          break;
        case BLACK_PIECE:
          printf("B");
          break;
        default:
          break;
      }
      printf(" ");
    }
    printf("\n");
  }
}

void move_piece(int r1, int c1, int r2, int c2) {
  board[r2][c2] = board[r1][c1];
  board[r1][c1] = EMPTY;
}

void capture_piece(int r1, int c1, int r2, int c2) {
  board[r2][c2] = board[r1][c1];
  board[(r1+r2)/2][(c1+c2)/2] = EMPTY;
  board[r1][c1] = EMPTY;
}

void select_piece(int row, int col) {
  selected_piece = board[row][col];
  selected_piece_row = row;
  selected_piece_col = col;
}

void game_over(int winner) {
  printf("Game over! ");
  if(winner == RED_PLAYER) {
    printf("Red player wins!\n");
  } else {
    printf("Black player wins!\n");
  }
  gameover = 1;
}

int valid_move(int r1, int c1, int r2, int c2) {
  if(board[r2][c2] != EMPTY || (r1%2 == c1%2 && r2%2 == c2%2)) {
    return 0;
  }
  switch(board[r1][c1]) {
    case RED_PIECE:
      if(r2>r1) return 0;
      if(abs(r2-r1)==1 && abs(c2-c1)==1) return 1;
    
      if(abs(r2-r1)==2 && abs(c2-c1)==2 && board[(r1+r2)/2][(c1+c2)/2] == BLACK_PIECE) {
        return 1;
      }
      break;
    case BLACK_PIECE:
      if(r2<r1) return 0;
      if(abs(r2-r1)==1 && abs(c2-c1)==1) return 1;
      if(abs(r2-r1)==2 && abs(c2-c1)==2 && board[(r1+r2)/2][(c1+c2)/2] == RED_PIECE) {
        return 1;
      }
      break;
    default:
      return 0;
  }
  return 0;
}

void try_move(int r1, int c1, int r2, int c2) {
  int valid_move_integer = valid_move(r1, c1, r2, c2);
  if(valid_move_integer) {
    if(abs(r2-r1)==2 && abs(c2-c1)==2) {
      capture_piece(r1, c1, r2, c2);
    } else {
      move_piece(r1, c1, r2, c2);
    }
    if(board[r2][c2] == BLACK_PIECE && r2 == BOARD_SIZE - 1) {
      board[r2][c2] = RED_PIECE;
    }
    if(board[r2][c2] == RED_PIECE && r2 == 0) {
      board[r2][c2] = BLACK_PIECE;
    }
    selected_piece = EMPTY;
    selected_piece_row = -1;
    selected_piece_col = -1;
    if(valid_move_integer == 1 && abs(r2-r1)==2) {
      if(current_player == RED_PLAYER) {
        int any_possible_move = 0;
        for(int r=-2; r<=2; r+=4) {
          for(int c=-2; c<=2; c+=4) {
            if(r1+r < 0 || r1+r >= BOARD_SIZE || c1+c < 0 || c1+c >= BOARD_SIZE)
              continue;
            if(board[r1+r][c1+c] == EMPTY) {
              if(board[r1][c1] == RED_PIECE || r1+r == 0) {
                any_possible_move = 1;
              }
            }
          }
        }
        if(!any_possible_move) {
          game_over(BLACK_PLAYER);
        }
      } else {
        int any_possible_move = 0;
        for(int r=-2; r<=2; r+=4) {
          for(int c=-2; c<=2; c+=4) {
            if(r1+r < 0 || r1+r >= BOARD_SIZE || c1+c < 0 || c1+c >= BOARD_SIZE)
              continue;
            if(board[r1+r][c1+c] == EMPTY) {
              if(board[r1][c1] == BLACK_PIECE || r1+r == BOARD_SIZE-1) {
                any_possible_move = 1;
              }
            }
          }
        }
        if(!any_possible_move) {
          game_over(RED_PLAYER);
        }
      }
    }
    current_player = (current_player == RED_PLAYER) ? BLACK_PLAYER : RED_PLAYER;
  }
}

int main() {
  printf("*** Welcome to Checkers ***\n\n");
  
  int turn = 1;
  while(!gameover) {
    printf("Turn %d:\n", turn++);
    draw_board();
    printf("Current player: %s\n", (current_player == RED_PLAYER) ? "Red" : "Black");
    int row1, col1, row2, col2;
    printf("Enter row and column of piece to move: ");
    scanf("%d %d", &row1, &col1);
    row1--;
    col1--;
    select_piece(row1, col1);
    if(selected_piece == EMPTY || (current_player == RED_PLAYER && selected_piece != RED_PIECE) || (current_player == BLACK_PLAYER && selected_piece != BLACK_PIECE)) {
      printf("Invalid selection. Please try again.\n");
      continue;
    }
    printf("Enter row and column where piece should move: ");
    scanf("%d %d", &row2, &col2);
    row2--;
    col2--;
    try_move(row1, col1, row2, col2);
  }

  return 0;
}