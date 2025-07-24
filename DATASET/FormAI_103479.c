//FormAI DATASET v1.0 Category: Checkers Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE]; // initialize game board

void initialize_board() {
   int row, column;
   for (row = 0; row < BOARD_SIZE; row++) {
      for (column = 0; column < BOARD_SIZE; column++) {
         if ((row + column) % 2 == 0) {
            if (row < 3) {
               board[row][column] = 'B'; // set black pieces
            } else if (row > 4) {
               board[row][column] = 'W'; // set white pieces
            } else {
               board[row][column] = '-'; // empty space
            }
         } else {
            board[row][column] = ' '; // non-playable space
         }
      }
   }
}

void print_board() {
   int row, column;
   for (row = 0; row < BOARD_SIZE; row++) {
      printf("%d ", BOARD_SIZE - row);
      for (column = 0; column < BOARD_SIZE; column++) {
         printf("| %c ", board[row][column]);
      }
      printf("|\n");
   }
   printf("   a   b   c   d   e   f   g   h\n"); // column labels
}

int move_piece(int from_row, int from_column, int to_row, int to_column) {
   char piece = board[from_row][from_column];
   char target = board[to_row][to_column];
   int move_type;
   if (piece == 'W') { // white piece
      if (to_row == from_row - 1 && abs(to_column - from_column) == 1 && target == '-') { // regular move
         move_type = 0;
      } else if (to_row == from_row - 2 && abs(to_column - from_column) == 2 && board[from_row - 1][(from_column + to_column) / 2] == 'B' && target == '-') { // capture move
         board[from_row - 1][(from_column + to_column) / 2] = '-'; // remove captured black piece
         move_type = 1;
      } else {
         return -1; // invalid move
      }
   } else if (piece == 'B') { // black piece
      if (to_row == from_row + 1 && abs(to_column - from_column) == 1 && target == '-') { // regular move
         move_type = 0;
      } else if (to_row == from_row + 2 && abs(to_column - from_column) == 2 && board[from_row + 1][(from_column + to_column) / 2] == 'W' && target == '-') { // capture move
         board[from_row + 1][(from_column + to_column) / 2] = '-'; // remove captured white piece
         move_type = 1;
      } else {
         return -1; // invalid move
      }
   } else {
      return -1; // invalid piece
   }
   board[from_row][from_column] = '-';
   board[to_row][to_column] = piece;
   if (piece == 'W' && to_row == 0) {
      board[to_row][to_column] = 'Q'; // white king
   } else if (piece == 'B' && to_row == 7) {
      board[to_row][to_column] = 'K'; // black king
   }
   return move_type;
}

int is_valid_move(char player, int from_row, int from_column, int to_row, int to_column, int is_capture) {
   char piece = board[from_row][from_column];
   char target = board[to_row][to_column];
   if (target != '-' || (from_row + from_column) % 2 != (to_row + to_column) % 2) { // target space is not empty or is non-playable
      return 0;
   }
   if (piece == 'W' && player == 'B' || piece == 'B' && player == 'W') { // wrong player moving
      return 0;
   }
   if (piece == 'W' || piece == 'Q') { // white pieces
      if (to_row == from_row - 1 && abs(to_column - from_column) == 1 && !is_capture) { // regular move
         return 1;
      } else if (to_row == from_row - 2 && abs(to_column - from_column) == 2 && board[from_row - 1][(from_column + to_column) / 2] == 'B' && is_capture) { // capture move
         return 1; 
      } else if (piece == 'Q' && abs(to_row - from_row) == abs(to_column - from_column)) { // queen move (diagonal)
         int row_dir = (to_row - from_row) / abs(to_row - from_row);
         int col_dir = (to_column - from_column) / abs(to_column - from_column);
         int i;
         for (i = 1; i < abs(to_row - from_row); i++) {
            if (board[from_row + i * row_dir][from_column + i * col_dir] != '-') { // blocked path
               return 0;
            }
         }
         if (is_capture && board[to_row][to_column] != 'B') { // wrong target piece
            return 0;
         }
         return 1;
      } else {
         return 0;
      }
   } else if (piece == 'B' || piece == 'K') { // black pieces
      if (to_row == from_row + 1 && abs(to_column - from_column) == 1 && !is_capture) { // regular move
         return 1;
      } else if (to_row == from_row + 2 && abs(to_column - from_column) == 2 && board[from_row + 1][(from_column + to_column) / 2] == 'W' && is_capture) { // capture move
         return 1;
      } else if (piece == 'K' && abs(to_row - from_row) == abs(to_column - from_column)) { // king move (diagonal)
         int row_dir = (to_row - from_row) / abs(to_row - from_row);
         int col_dir = (to_column - from_column) / abs(to_column - from_column);
         int i;
         for (i = 1; i < abs(to_row - from_row); i++) {
            if (board[from_row + i * row_dir][from_column + i * col_dir] != '-') { // blocked path
               return 0;
            }
         }
         if (is_capture && board[to_row][to_column] != 'W') { // wrong target piece
            return 0;
         }
         return 1;
      } else {
         return 0;
      }
   } else {
      return 0;
   }
}

int is_game_over(char player) {
   int row, column;
   int white_count = 0;
   int black_count = 0;
   for (row = 0; row < BOARD_SIZE; row++) {
      for (column = 0; column < BOARD_SIZE; column++) {
         if (board[row][column] == 'W' || board[row][column] == 'Q') {
            white_count++;
         } else if (board[row][column] == 'B' || board[row][column] == 'K') {
            black_count++;
         }
      }
   }
   if (white_count == 0 || black_count == 0) { // no pieces left for one player
      return 1;
   }
   int can_move = 0;
   for (row = 0; row < BOARD_SIZE; row++) {
      for (column = 0; column < BOARD_SIZE; column++) {
         if ((board[row][column] == 'W' || board[row][column] == 'Q') && is_valid_move(player, row, column, row - 2, column - 2, 1) || is_valid_move(player, row, column, row - 2, column + 2, 1) || is_valid_move(player, row, column, row - 1, column - 1, 0) || is_valid_move(player, row, column, row - 1, column + 1, 0)) { // white piece moves
            can_move = 1;
            break;
         } else if ((board[row][column] == 'B' || board[row][column] == 'K') && is_valid_move(player, row, column, row + 2, column - 2, 1) || is_valid_move(player, row, column, row + 2, column + 2, 1) || is_valid_move(player, row, column, row + 1, column - 1, 0) || is_valid_move(player, row, column, row + 1, column + 1, 0)) { // black piece moves
            can_move = 1;
            break;
         }
      }
      if (can_move) {
         break;
      }
   }
   if (!can_move) { // player cannot move
      return 1;
   }
   return 0;
}

int main() {
   int from_row, from_column, to_row, to_column;
   char player = 'W';
   initialize_board();
   while (!is_game_over(player)) {
      system("clear");
      printf("CHEKERS GAME\n");
      printf("Player %c's turn\n", player);
      print_board();
      printf("Enter from position: ");
      scanf("%d %d", &from_row, &from_column);
      printf("Enter to position: ");
      scanf("%d %d", &to_row, &to_column);
      int move_type = move_piece(from_row - 1, from_column - 'a', to_row - 1, to_column - 'a');
      if (move_type == -1) {
         printf("Invalid move.\n");
         continue;
      }
      if (move_type == 0) {
         player = player == 'W' ? 'B' : 'W'; // switch player
      }
   }
   printf("GAME OVER\n");
   print_board();
   if (player == 'W') {
      printf("Black wins!\n");
   } else {
      printf("White wins!\n");
   }
   return 0;
}