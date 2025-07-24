//FormAI DATASET v1.0 Category: Game ; Style: portable
#include <stdio.h>

int main() {
   int rows, cols, i, j;

   printf("Enter the number of rows: ");
   scanf("%d", &rows);
   printf("Enter the number of columns: ");
   scanf("%d", &cols);

   int gameBoard[rows][cols];

   // initialize game board
   for (i = 0; i < rows; i++) {
      for (j = 0; j < cols; j++) {
         gameBoard[i][j] = 0;
      }
   }

   // randomly place obstacles
   for (i = 0; i < rows; i++) {
      for (j = 0; j < cols; j++) {
         if ((rand() % 5) == 0) {
            gameBoard[i][j] = 1;
         }
      }
   }

   // print game board
   for (i = 0; i < rows; i++) {
      for (j = 0; j < cols; j++) {
         if (gameBoard[i][j] == 1) {
            printf("# ");
         } else {
            printf(". ");
         }
      }
      printf("\n");
   }

   return 0;
}