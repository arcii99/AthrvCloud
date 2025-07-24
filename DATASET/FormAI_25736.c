//FormAI DATASET v1.0 Category: Chess engine ; Style: high level of detail
#include <stdio.h>

int main() {
   printf("Welcome to the Chess Engine!\n");

   // Board Setup
   char board[8][8] = {
      {'R','N','B','Q','K','B','N','R'},
      {'P','P','P','P','P','P','P','P'},
      {' ',' ',' ',' ',' ',' ',' ',' '},
      {' ',' ',' ',' ',' ',' ',' ',' '},
      {' ',' ',' ',' ',' ',' ',' ',' '},
      {' ',' ',' ',' ',' ',' ',' ',' '},
      {'p','p','p','p','p','p','p','p'},
      {'r','n','b','q','k','b','n','r'}
   };

   // Print Board
   printf("\nCurrent Board:\n\n");
   for(int i = 0; i < 8; i++) {
      for(int j = 0; j < 8; j++) {
         printf("%c ", board[i][j]);
      }
      printf("\n");
   }

   return 0;
}