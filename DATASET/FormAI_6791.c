//FormAI DATASET v1.0 Category: Checkers Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define BLACK 'B'
#define WHITE 'W'
#define EMPTY ' '

#define SIZE 8

char board[SIZE][SIZE];
char current_player;

int get_piece_value(int row, int col){
  if(board[row][col] == EMPTY){
    return 0;
  } else if(board[row][col] == current_player){
    return 1;
  } else {
    return -1;
  }
}

bool is_valid_move(int start_row, int start_col, int end_row, int end_col){
  if(board[end_row][end_col] != EMPTY){
    return false;
  }

  int delta_row = end_row - start_row;
  int delta_col = end_col - start_col;

  if(current_player == BLACK){
    if(delta_row > 0){
      return false;
    } else if(delta_row == -1 && abs(delta_col) == 1){
      return true;
    } else if(delta_row == -2 && delta_col == 2 && board[start_row-1][start_col+1] == WHITE){
      return true;
    } else if(delta_row == -2 && delta_col == -2 && board[start_row-1][start_col-1] == WHITE){
      return true;
    } else {
      return false;
    }
  } else if(current_player == WHITE){
    if(delta_row < 0){
      return false;
    } else if(delta_row == 1 && abs(delta_col) == 1){
      return true;
    } else if(delta_row == 2 && delta_col == 2 && board[start_row+1][start_col+1] == BLACK){
      return true;
    } else if(delta_row == 2 && delta_col == -2 && board[start_row+1][start_col-1] == BLACK){
      return true;
    } else {
      return false;
    }
  }
}

void make_move(int start_row, int start_col, int end_row, int end_col){
  board[start_row][start_col] = EMPTY;
  board[end_row][end_col] = current_player;

  int captured_row = (start_row + end_row) / 2;
  int captured_col = (start_col + end_col) / 2;

  if(captured_row != start_row && captured_col != start_col){
    board[captured_row][captured_col] = EMPTY;
  }
}

bool has_valid_moves(){
  for(int row = 0; row < SIZE; row++){
    for(int col = 0; col < SIZE; col++){
      if(board[row][col] != current_player){
        continue;
      }

      if(current_player == BLACK){
        if(row > 0){
          if(col > 0 && board[row-1][col-1] == EMPTY){
            return true;
          }

          if(col < SIZE-1 && board[row-1][col+1] == EMPTY){
            return true;
          }
        }

        if(row > 1 && col > 1 && board[row-1][col-1] == WHITE && board[row-2][col-2] == EMPTY){
          return true;
        }

        if(row > 1 && col < SIZE-2 && board[row-1][col+1] == WHITE && board[row-2][col+2] == EMPTY){
          return true;
        }
      } else if(current_player == WHITE){
        if(row < SIZE-1){
          if(col > 0 && board[row+1][col-1] == EMPTY){
            return true;
          }

          if(col < SIZE-1 && board[row+1][col+1] == EMPTY){
            return true;
          }
        }

        if(row < SIZE-2 && col > 1 && board[row+1][col-1] == BLACK && board[row+2][col-2] == EMPTY){
          return true;
        }

        if(row < SIZE-2 && col < SIZE-2 && board[row+1][col+1] == BLACK && board[row+2][col+2] == EMPTY){
          return true;
        }
      }
    }
  }
  return false;
}

bool is_game_over(){
  return !has_valid_moves();
}

void switch_player(){
  if(current_player == BLACK){
    current_player = WHITE;
  } else {
    current_player = BLACK;
  }
}

void print_board(){
  for(int row = 0; row < SIZE; row++){
    for(int col = 0; col < SIZE; col++){
      printf("| %c ", board[row][col]);
    }
    printf("|\n");
  }
  printf("\n\n");
}

void play_game(){
  current_player = BLACK;
  print_board();

  while(!is_game_over()){
    if(!has_valid_moves()){
      switch_player();
    }

    int start_row, start_col, end_row, end_col;

    do {
      printf("%c's turn. Enter move (row,col to row,col): ", current_player);
      scanf("%d,%d to %d,%d", &start_row, &start_col, &end_row, &end_col);
    } while(!is_valid_move(start_row, start_col, end_row, end_col));

    make_move(start_row, start_col, end_row, end_col);
    switch_player();
    print_board();
  }

  printf("Game over!\n");
}

int main(){
  for(int row = 0; row < SIZE; row++){
    for(int col = 0; col < SIZE; col++){
      if(row < 3 && (row+col)%2 == 0){
        board[row][col] = WHITE;
      } else if(row > 4 && (row+col)%2 == 0){
        board[row][col] = BLACK;
      } else {
        board[row][col] = EMPTY;
      }
    }
  }

  play_game();

  return 0;
}