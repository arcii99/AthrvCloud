//FormAI DATASET v1.0 Category: Matrix operations ; Style: standalone
#include <stdio.h>

// function to print matrix
void printMatrix(int mat[3][3]) {
   int i, j;
   for(i = 0; i < 3; i++) {
      for(j = 0; j < 3; j++) {
         printf("%d ", mat[i][j]);
      }
      printf("\n");
   }
}

int main() {
   // initialize matrices
   int mat1[3][3] = { {2, 3, 4}, {5, 6, 7}, {8, 9, 1} };
   int mat2[3][3] = { {4, 5, 6}, {7, 8, 9}, {1, 2, 3} };
   int res[3][3], r, c, i;

   // matrix addition
   printf("Matrix Addition:\n");
   for(r = 0; r < 3; r++) {
      for(c = 0; c < 3; c++) {
         res[r][c] = mat1[r][c] + mat2[r][c];
      }
   }
   printMatrix(res);

   // matrix multiplication
   printf("Matrix Multiplication:\n");
   for(r = 0; r < 3; r++) {
      for(c = 0; c < 3; c++) {
         res[r][c] = 0;
         for(i = 0; i < 3; i++) {
            res[r][c] += mat1[r][i] * mat2[i][c];
         }
      }
   }
   printMatrix(res);

   // matrix transposition
   printf("Matrix Transposition:\n");
   for(r = 0; r < 3; r++) {
      for(c = r; c < 3; c++) {
         int temp = mat1[r][c];
         mat1[r][c] = mat1[c][r];
         mat1[c][r] = temp;
      }
   }
   printMatrix(mat1);

   return 0;
}