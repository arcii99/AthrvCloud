//FormAI DATASET v1.0 Category: Chess AI ; Style: genious
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define SIZE 8

// global variables
int board[SIZE][SIZE];
bool whites_turn;

void initialize_board() {
  // initialize board with starting positions
  board[0][0] = board[0][7] = 2;
  board[7][0] = board[7][7] = -2;
  board[0][1] = board[0][6] = 1;
  board[7][1] = board[7][6] = -1;
  board[0][2] = board[0][5] = 3;
  board[7][2] = board[7][5] = -3;
  board[0][3] = 4;
  board[7][3] = -4;
  board[0][4] = 5;
  board[7][4] = -5;
  
  // initialize rest of board to empty spaces
  for (int i = 2; i < 6; i++) {
    for (int j = 0; j < SIZE; j++) {
      board[i][j] = 0;
    }
  }
  
  // set white to move first
  whites_turn = true;
}

void print_board() {
  printf("\n   A B C D E F G H\n\n");
  for (int i = 0; i < SIZE; i++) {
    printf("%d  ", (SIZE - i));
    for (int j = 0; j < SIZE; j++) {
      switch(board[i][j]) {
        case 0: // empty space
          printf(". ");
          break;
        case 1: // white pawn
          printf("P ");
          break;
        case 2: // white knight
          printf("N ");
          break;
        case 3: // white bishop
          printf("B ");
          break;
        case 4: // white rook
          printf("R ");
          break;
        case 5: // white queen
          printf("Q ");
          break;
        case 6: // white king
          printf("K ");
          break;
        case -1: // black pawn
          printf("p ");
          break;
        case -2: // black knight
          printf("n ");
          break;
        case -3: // black bishop
          printf("b ");
          break;
        case -4: // black rook
          printf("r ");
          break;
        case -5: // black queen
          printf("q ");
          break;
        case -6: // black king
          printf("k ");
          break;
      }
    }
    printf(" %d\n", (SIZE - i));
  }
  printf("\n   A B C D E F G H\n\n");
}

bool is_valid_move(int i1, int j1, int i2, int j2) {
  // check if piece is moving out of bounds
  if (i2 < 0 || i2 >= SIZE || j2 < 0 || j2 >= SIZE) {
    return false;
  }
  
  // check if piece is moving to same position
  if (i1 == i2 && j1 == j2) {
    return false;
  }
  
  // check if piece being moved is owned by player
  if (board[i1][j1] > 0 && !whites_turn) {
    return false;
  } else if (board[i1][j1] < 0 && whites_turn) {
    return false;
  }
  
  // check if destination is empty or owned by opposing player
  if (board[i2][j2] > 0 && whites_turn) {
    return false;
  } else if (board[i2][j2] < 0 && !whites_turn) {
    return false;
  }
  
  // check validity of specific move
  // TODO: implement move checking
  
  return true;
}

bool make_move(int i1, int j1, int i2, int j2) {
  if (is_valid_move(i1, j1, i2, j2)) {
    // move piece
    board[i2][j2] = board[i1][j1];
    board[i1][j1] = 0;
    
    // switch players turn
    whites_turn = !whites_turn;
    
    return true;
  }
  
  return false;
}

int main() {
  initialize_board();
  
  print_board();
  
  return 0;
}