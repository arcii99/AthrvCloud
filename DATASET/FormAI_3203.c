//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main() {
   srand(time(NULL));
   int num[ROWS][COLS];
   int picked[ROWS * COLS]; // used to store the numbers that have been picked
   int num_picked = 0;
   int row, col;
   
   /* initialize the matrix with 0s */
   for(row=0; row<ROWS; row++) {
      for(col=0; col<COLS; col++) {
         num[row][col] = 0;
      }
   }

   printf("\n\t************BINGO SIMULATOR************\n\n");

   /* mark the center cell as already picked */
   picked[num_picked++] = (ROWS/2) * COLS + COLS/2;
   num[ROWS/2][COLS/2] = -1;

   /* print the empty matrix */
   printf("    ");
   for(col=0; col<COLS; col++) {
      printf("%2c ",'A'+col);
   }

   printf("\n   +");
   for(col=0; col<COLS; col++) {
      printf("--+");
   }

   printf("\n");

   for(row=0; row<ROWS; row++) {
      printf("%2d |", row+1);

      for(col=0; col<COLS; col++) {
         printf("%2d|", num[row][col]);
      }

      printf("\n");

      printf("   +");
      for(col=0; col<COLS; col++) {
         printf("--+");
      }
      printf("\n");
   }

   /* play the game until all numbers have been picked */
   while(num_picked < ROWS * COLS) {
      printf("\n\tPress Enter to continue...");
      getchar();

      /* generate a random number that has not been picked yet */
      int number;
      do {
        number = rand() % (ROWS * COLS) + 1;
      } while(check_number(picked, num_picked, number));

      /* mark the number as picked */
      picked[num_picked++] = number;

      /* find the corresponding cell in the matrix */
      row = (number - 1) / COLS;
      col = (number - 1) % COLS;

      /* mark the cell as picked */
      num[row][col] = -1;

      /* print the updated matrix */
      system("clear"); // clears the terminal screen
      printf("\n\t************BINGO SIMULATOR************\n\n");

      printf("    ");
      for(col=0; col<COLS; col++) {
         printf("%2c ", 'A'+col);
      }
      printf("\n");

      for(row=0; row<ROWS; row++) {
         printf("%2d |", row+1);

         for(col=0; col<COLS; col++) {
            if(num[row][col] == -1) {
               printf(" X|");
            } else if(check_number(picked, num_picked, row*COLS+col+1)) {
               printf(" O|");
            } else {
               printf("%2d|", num[row][col]);
            }
         }
         printf("\n");

         printf("   +");
         for(col=0; col<COLS; col++) {
            printf("--+");
         }
         printf("\n");
      }
   }

   /* print the final message */
   printf("\n\n\t*** BINGO! All numbers have been picked. ***\n");

   return 0;
}

/* checks if a number has already been picked */
int check_number(int picked[], int num_picked, int number) {
   int i;
   for(i=0; i<num_picked; i++) {
      if(picked[i] == number) {
         return 1;
      }
   }
   return 0;
}