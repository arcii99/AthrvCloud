//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define FREE_SPACE ' '

int main() {
   int calls[75] = {0};
   int num, row, col, count = 0;
   char card[ROWS][COLS] = {{FREE_SPACE}};
   srand(time(NULL));
   
   printf("Welcome to Bingo Simulator!\n");
   printf("Press enter to start the game.\n\n");
   getchar();

   // Generate Bingo Card
   printf("Your Bingo Card:\n");
   for(row = 0; row < ROWS; row++) {
      for(col = 0; col < COLS; col++) {
         if(row == 2 && col == 2) {
            card[row][col] = FREE_SPACE;
            printf("[  ] ");
         } else {
            card[row][col] = (rand() % 15) + (col * 15) + 1;
            printf("[%2d] ", card[row][col]);
         }
      }
      printf("\n");
   }
   printf("\n");
   
   // Start calling numbers
   printf("Game is on! Press enter to call a number.\n");
   while(count < 75) {
      getchar();
      num = (rand() % 75) + 1;
      if(calls[num-1] == 0) {
         printf("Number called: %d\n", num);
         calls[num-1] = 1;
         for(row = 0; row < ROWS; row++) {
            for(col = 0; col < COLS; col++) {
               if(card[row][col] == num) {
                  card[row][col] = FREE_SPACE;
               }
            }
         }
         // Check for Bingo
         int i;
         for(i = 0; i < ROWS; i++) {
            if(card[i][0] == FREE_SPACE && card[i][1] == FREE_SPACE && card[i][2] == FREE_SPACE && card[i][3] == FREE_SPACE && card[i][4] == FREE_SPACE) {
               printf("Bingo!!\n");
               return 0;
            }
            if(card[0][i] == FREE_SPACE && card[1][i] == FREE_SPACE && card[2][i] == FREE_SPACE && card[3][i] == FREE_SPACE && card[4][i] == FREE_SPACE) {
               printf("Bingo!!\n");
               return 0;
            }
         }
         if(card[0][0] == FREE_SPACE && card[1][1] == FREE_SPACE && card[2][2] == FREE_SPACE && card[3][3] == FREE_SPACE && card[4][4] == FREE_SPACE) {
            printf("Bingo!!\n");
            return 0;
         }
         if(card[0][4] == FREE_SPACE && card[1][3] == FREE_SPACE && card[2][2] == FREE_SPACE && card[3][1] == FREE_SPACE && card[4][0] == FREE_SPACE) {
            printf("Bingo!!\n");
            return 0;
         }
         count++;
      }
   }
   printf("Game over! No bingo was called.\n");
   return 0;
}