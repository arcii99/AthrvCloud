//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5       // Number of rows in the bingo card
#define COLS 5       // Number of columns in the bingo card
#define MAX_VALUE 75 // Maximum value in the bingo game

int main(void) {
   int card[ROWS][COLS];  // Bingo card
   int numbers[MAX_VALUE]; // Array to keep track of called numbers
   int num;    // Current number called
   int count;  // Number of matches found
   int i, j;   // Loop counters

   // Initialize random number generator
   srand(time(NULL));

   // Initialize bingo card
   for (i = 0; i < ROWS; i++) {
      for (j = 0; j < COLS; j++) {
         card[i][j] = 0;
      }
   }

   // Initialize array of called numbers
   for (i = 0; i < MAX_VALUE; i++) {
      numbers[i] = 0;
   }

   // Loop until bingo is called
   do {
      // Get a random number
      num = rand() % MAX_VALUE + 1;

      // Check if the number has been called before
      if (numbers[num-1] == 0) {
         // Mark the number as called
         numbers[num-1] = 1;

         // Check if the number is on the bingo card
         for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
               if (card[i][j] == num) {
                  // Mark the number as found
                  card[i][j] = -1;
               }
            }
         }
      }

      // Print the current board
      printf("Current Board:\n");
      for (i = 0; i < ROWS; i++) {
         for (j = 0; j < COLS; j++) {
            if (card[i][j] == -1) {
               printf("%3s", "X");
            } else {
               printf("%3d", card[i][j]);
            }
         }
         printf("\n");
      }
      printf("\n");

      // Count the number of matches found
      count = 0;
      for (i = 0; i < ROWS; i++) {
         for (j = 0; j < COLS; j++) {
            if (card[i][j] == -1) {
               count++;
            }
         }
      }
   } while (count < (ROWS*COLS)); // Check if bingo has been called

   printf("BINGO!\n");

   return 0;
}