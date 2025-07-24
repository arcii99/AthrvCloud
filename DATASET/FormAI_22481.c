//FormAI DATASET v1.0 Category: Checkers Game ; Style: cheerful
#include <stdio.h>

#define BOARD_DIM 8

char board[BOARD_DIM][BOARD_DIM];
int player_turn = 1;

void initialize_board() {
  for(int i = 0; i < BOARD_DIM; i++) {
    for(int j = 0; j < BOARD_DIM; j++) {
      if(i < 3 && (i + j) % 2 == 0) {
        board[i][j] = 'B'; // Player 2's piece
      } else if(i > 4 && (i + j) % 2 == 0) {
        board[i][j] = 'R'; // Player 1's piece
      } else {
        board[i][j] = ' ';
      }
    }
  }
}

void draw_board() {
  printf("   0 1 2 3 4 5 6 7\n");
  printf("  -----------------\n");
  for(int i = 0; i < BOARD_DIM; i++) {
    printf("%d |", i);
    for(int j = 0; j < BOARD_DIM; j++) {
      printf("%c|", board[i][j]);
    }
    printf(" %d\n", i);
  }
  printf("  -----------------\n");
  printf("   0 1 2 3 4 5 6 7\n");
}

int make_move(int start_row, int start_col, int end_row, int end_col) {
  // Check if move is valid
  if((start_row + start_col) % 2 != 0 || 
     (end_row + end_col) % 2 == 0 ||
     board[start_row][start_col] == ' ' ||
     board[end_row][end_col] != ' ') {
    return 0; // Invalid move
  }

  // Check if move is a capture
  int dx = end_col - start_col;
  int dy = end_row - start_row;
  if(board[start_row][start_col] == 'R' && dy < 0 ||
     board[start_row][start_col] == 'B' && dy > 0 ||
     abs(dx) != abs(dy) ||
     abs(dx) != 2 ||
     board[start_row + dy/2][start_col + dx/2] == ' ' ||
     board[start_row + dy/2][start_col + dx/2] == board[start_row][start_col]) {
     return 0; // Invalid move
   }

   // Make the move
   board[end_row][end_col] = board[start_row][start_col];
   board[start_row][start_col] = ' ';
   if(abs(dy) == 2){
     board[start_row + dy/2][start_col + dx/2] = ' ';
   }
   return 1;
}

void switch_turn() {
  player_turn = (player_turn == 1) ? 2 : 1;
}

int check_game_over() {
  int red_pieces = 0, black_pieces = 0;
  for(int i = 0; i < BOARD_DIM; i++) {
    for(int j = 0; j < BOARD_DIM; j++) {
      if(board[i][j] == 'R') red_pieces++;
      if(board[i][j] == 'B') black_pieces++;
    }
  }
  if(red_pieces == 0) {
    return 2; // Black wins!
  } else if(black_pieces == 0) {
    return 1; // Red wins!
  } else {
    return 0; // Game continues
  }
}

int main() {
  printf("Welcome to the Checkers game!\n");
  initialize_board();
  draw_board();
  int game_over = 0;
  while(!game_over) {
    printf("It is Player %d's turn.\n", player_turn);
    int start_row, start_col, end_row, end_col;
    printf("Enter start row and column: ");
    scanf("%d %d", &start_row, &start_col);
    printf("Enter end row and column: ");
    scanf("%d %d", &end_row, &end_col);
    if(make_move(start_row, start_col, end_row, end_col)) {
      draw_board();
      switch_turn();
    } else {
      printf("Invalid move. Please try again.\n");
    }
    game_over = check_game_over();
  }
  printf("Congratulations Player %d! You win!\n", game_over);
  return 0;
}