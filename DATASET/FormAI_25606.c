//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3]; // the tic tac toe board

int check_win() {
   // Check for horizontal wins
   for (int row = 0; row < 3; row++) {
      if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
         if (board[row][0] == 'X') return 1;
         else if (board[row][0] == 'O') return -1;
      }
   }

   // Check for vertical wins
   for (int col = 0; col < 3; col++) {
      if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
         if (board[0][col] == 'X') return 1;
         else if (board[0][col] == 'O') return -1;
      }
   }

   // Check for diagonal wins
   if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
      if (board[0][0] == 'X') return 1;
      else if (board[0][0] == 'O') return -1;
   }
   if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
      if (board[0][2] == 'X') return 1;
      else if (board[0][2] == 'O') return -1;
   }

   return 0; // if no one won
}

int minimax() {
   int best_score = -2; // initialize to losing score
   int row = -1, col = -1;

   for (int i = 0; i < 3; i++) { // try all possible moves
      for (int j = 0; j < 3; j++) {
         if (board[i][j] == ' ') { // check if spot is available
            board[i][j] = 'O'; // make move
            int score = -minimax(); // switch players and get score
            board[i][j] = ' '; // undo move

            if (score > best_score) { // keep best move so far
               best_score = score;
               row = i;
               col = j;
            }
         }
      }
   }

   if (row == -1 && col == -1) return 0; // no move available
   board[row][col] = 'O'; // make best move
   return 1; // success
}

void display_board() {
   for (int row = 0; row < 3; row++) {
      for (int col = 0; col < 3; col++) {
         printf(" %c ", board[row][col]);
         if (col < 2) printf("|");
      }
      printf("\n");
      if (row < 2) printf("---+---+---\n");
   }
   printf("\n");
}

int main() {
   int turn = 1; // start as player X
   srand(time(NULL)); // seed random number generator

   for (int row = 0; row < 3; row++) {
      for (int col = 0; col < 3; col++) {
         board[row][col] = ' '; // initialize board
      }
   }

   while (check_win() == 0) {
      if (turn == 1) { // player X's turn
         int row, col;

         do { // get valid move from player
            printf("Enter row (1-3): ");
            scanf("%d", &row);
            printf("Enter column (1-3): ");
            scanf("%d", &col);
            row--;
            col--;
         } while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ');
         board[row][col] = 'X';
         turn = -1;
      } else { // AI's turn (player O)
         if (!minimax()) break; // if no move available
         turn = 1;
      }

      display_board();
   }

   int winner = check_win();
   if (winner == 1) printf("Player X wins!\n");
   else if (winner == -1) printf("Player O wins!\n");
   else printf("Draw.\n");

   return 0;
}