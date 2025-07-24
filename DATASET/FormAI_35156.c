//FormAI DATASET v1.0 Category: Data mining ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

#define MAX_ROWS 5
#define MAX_COLS 4

int main() {
   int matrix[MAX_ROWS][MAX_COLS] = { {12, 13, 10, 14}, {99, 87, 38, 49}, {0, 1, 2, 3}, {2, 4, 6, 8}, {11, 22, 33, 44} };
   int sum_cols[MAX_COLS] = {0};
   
   for(int i = 0; i < MAX_COLS; i++) {
      for(int j = 0; j < MAX_ROWS; j++) {
         sum_cols[i] += matrix[j][i];
      }
   }

   printf("Column-wise totals of the matrix are:\n");
   for(int i = 0; i < MAX_COLS; i++) {
      printf("Column %d: %d\n", i+1, sum_cols[i]);
   }

   int min_val = matrix[0][0], max_val = matrix[0][0];
   for(int i = 0; i < MAX_ROWS; i++) {
      for(int j = 0; j < MAX_COLS; j++) {
         if(matrix[i][j] < min_val) {
            min_val = matrix[i][j];
         }
         if(matrix[i][j] > max_val) {
            max_val = matrix[i][j];
         }
      }
   }

   printf("Minimum value in the matrix: %d\n", min_val);
   printf("Maximum value in the matrix: %d\n", max_val);

   int count_odd = 0, count_even = 0;
   for(int i = 0; i < MAX_ROWS; i++) {
      for(int j = 0; j < MAX_COLS; j++) {
         if(matrix[i][j] % 2 == 0) {
            count_even++;
         }
         else {
            count_odd++;
         }
      }
   }

   printf("Number of odd values in the matrix: %d\n", count_odd);
   printf("Number of even values in the matrix: %d\n", count_even);

   return 0;
}