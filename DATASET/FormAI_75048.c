//FormAI DATASET v1.0 Category: Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLS 6

void drawBoard(int board[][COLS]);
int checkGameOver(int board[][COLS]);

int main(void) {
   int board[ROWS][COLS] = {0};
   int gameover = 0, player = 1;
   int column, i;
   time_t t;

   srand((unsigned) time(&t));

   printf("Welcome to Connect 4 Game!\n");
   drawBoard(board);

   while (!gameover) {
      printf("\nPlayer %d, please choose a column (1-6): ", player);
      scanf("%d", &column);

      if (column < 1 || column > COLS) {
         printf("\nInvalid column number. Please choose again.\n");
         continue;
      }

      column--;

      for (i = ROWS - 1; i >= 0; i--) {
         if (board[i][column] == 0) {
            board[i][column] = player;
            break;
         }
      }

      if (i < 0) {
         printf("\nColumn is full. Please choose another column.\n");
         continue;
      }

      drawBoard(board);

      gameover = checkGameOver(board);

      if (gameover == 1) {
         printf("\nPlayer %d wins!\n", player);
      } else if (gameover == 2) {
         printf("\nDraw! Game over.\n");
      }

      player = (player == 1) ? 2 : 1;
   }

   return 0;
}

void drawBoard(int board[][COLS]) {
   int i, j;

   printf("\n  1 2 3 4 5 6 \n");
   printf("-------------\n");

   for (i = ROWS - 1; i >= 0; i--) {
      printf("|");
      for (j = 0; j < COLS; j++) {
         if (board[i][j] == 0) {
            printf(" |");
         } else if (board[i][j] == 1) {
            printf("X|");
         } else {
            printf("O|");
         }
      }
      printf("\n");
      printf("-------------\n");
   }
}

int checkGameOver(int board[][COLS]) {
   int i, j, countX = 0, countO = 0;

   // Check horizontal lines
   for (i = 0; i < ROWS; i++) {
      countX = 0;
      countO = 0;

      for (j = 0; j < COLS; j++) {
         if (board[i][j] == 1) {
            countX++;
            countO = 0;
         } else if (board[i][j] == 2) {
            countX = 0;
            countO++;
         } else {
            countX = 0;
            countO = 0;
         }

         if (countX >= 4) {
            return 1;
         } else if (countO >= 4) {
            return 1;
         }
      }
   }

   // Check vertical lines
   for (j = 0; j < COLS; j++) {
      countX = 0;
      countO = 0;

      for (i = 0; i < ROWS; i++) {
         if (board[i][j] == 1) {
            countX++;
            countO = 0;
         } else if (board[i][j] == 2) {
            countX = 0;
            countO++;
         } else {
            countX = 0;
            countO = 0;
         }

         if (countX >= 4) {
            return 1;
         } else if (countO >= 4) {
            return 1;
         }
      }
   }

   // Check diagonal lines (bottom-left to top-right)
   for (i = 0; i <= ROWS - 4 ; i++) {
      countX = 0;
      countO = 0;

      for (j = 0; j < COLS && i + j < ROWS; j++) {
         if (board[i + j][j] == 1) {
            countX++;
            countO = 0;
         } else if (board[i + j][j] == 2) {
            countX = 0;
            countO++;
         } else {
            countX = 0;
            countO = 0;
         }

         if (countX >= 4) {
            return 1;
         } else if (countO >= 4) {
            return 1;
         }
      }
   }

   for (j = 1; j <= COLS - 4 ; j++) {
      countX = 0;
      countO = 0;

      for (i = 0; i < ROWS && i + j < COLS; i++) {
         if (board[i][i + j] == 1) {
            countX++;
            countO = 0;
         } else if (board[i][i + j] == 2) {
            countX = 0;
            countO++;
         } else {
            countX = 0;
            countO = 0;
         }

         if (countX >= 4) {
            return 1;
         } else if (countO >= 4) {
            return 1;
         }
      }
   }

   // Check diagonal lines (top-left to bottom-right)
   for (j = 0; j <= COLS - 4 ; j++) {
      countX = 0;
      countO = 0;

      for (i = ROWS - 1; i >= 0 && i - j >= 0; i--) {
         if (board[i - j][i] == 1) {
            countX++;
            countO = 0;
         } else if (board[i - j][i] == 2) {
            countX = 0;
            countO++;
         } else {
            countX = 0;
            countO = 0;
         }

         if (countX >= 4) {
            return 1;
         } else if (countO >= 4) {
            return 1;
         }
      }
   }

   for (i = 1; i <= ROWS - 4 ; i++) {
      countX = 0;
      countO = 0;

      for (j = 0; j < COLS && i + j < ROWS; j++) {
         if (board[ROWS - 1 - i - j][j] == 1) {
            countX++;
            countO = 0;
         } else if (board[ROWS - 1 - i - j][j] == 2) {
            countX = 0;
            countO++;
         } else {
            countX = 0;
            countO = 0;
         }

         if (countX >= 4) {
            return 1;
         } else if (countO >= 4) {
            return 1;
         }
      }
   }

   // Check for draw game
   for (i = ROWS - 1; i >= 0; i--) {
      for (j = 0; j < COLS; j++) {
         if (board[i][j] == 0) {
            return 0;
         }
      }
   }

   return 2; // It's a draw
}