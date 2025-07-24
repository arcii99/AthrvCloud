//FormAI DATASET v1.0 Category: Chess engine ; Style: surprised
#include <stdio.h>

#define BOARD_SIZE 8

int main() {
   printf("Wow, I can't believe I'm writing a Chess engine in C!\n");

   // Initialize the board
   char board[BOARD_SIZE][BOARD_SIZE] = {
      {'R','N','B','Q','K','B','N','R'},
      {'P','P','P','P','P','P','P','P'},
      {' ',' ',' ',' ',' ',' ',' ',' '},
      {' ',' ',' ',' ',' ',' ',' ',' '},
      {' ',' ',' ',' ',' ',' ',' ',' '},
      {' ',' ',' ',' ',' ',' ',' ',' '},
      {'p','p','p','p','p','p','p','p'},
      {'r','n','b','q','k','b','n','r'}
   };

   // Print the board
   printf("       a   b   c   d   e   f   g   h\n");
   printf("     +---+---+---+---+---+---+---+---+\n");
   for (int row = 0; row < BOARD_SIZE; row++) {
      printf("  %d  |", BOARD_SIZE - row);
      for (int col = 0; col < BOARD_SIZE; col++) {
         printf(" %c |", board[row][col]);
      }
      printf(" %d\n", BOARD_SIZE - row);
      printf("     +---+---+---+---+---+---+---+---+\n");
   }
   printf("       a   b   c   d   e   f   g   h\n");

   printf("I can't wait to implement the move logic!\n");
   return 0;
}