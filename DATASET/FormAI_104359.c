//FormAI DATASET v1.0 Category: Matrix operations ; Style: expert-level
#include <stdio.h>

int main() {
   int m, n;
   printf("Enter the number of rows and columns of the matrix: ");
   scanf("%d %d", &m, &n);

   int matrix[m][n];
   printf("Enter the elements of the matrix:\n");
   for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
         scanf("%d", &matrix[i][j]);
      }
   }

   printf("\nThe original matrix:\n");
   for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
         printf("%d ", matrix[i][j]);
      }
      printf("\n");
   }

   // Matrix Transpose
   int transpose[n][m];
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         transpose[i][j] = matrix[j][i];
      }
   }

   printf("\nThe transpose of the matrix:\n");
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         printf("%d ", transpose[i][j]);
      }
      printf("\n");
   }

   // Matrix Addition
   int add[m][n];
   int operand[m][n];
   printf("\nEnter the elements of another matrix of same dimensions for addition:\n");
   for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
         scanf("%d", &operand[i][j]);
         add[i][j] = matrix[i][j] + operand[i][j];
      }
   }

   printf("\nThe resulting matrix after addition:\n");
   for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
         printf("%d ", add[i][j]);
      }
      printf("\n");
   }

   // Matrix Multiplication
   int p, q;
   printf("\nEnter the number of columns of the second matrix: ");
   scanf("%d", &q);

   int multiply[m][q];
   int factor[q][n];
   printf("Enter the elements of another matrix of dimension %d x %d for multiplication:\n", n, q);
   for (int i = 0; i < q; i++) {
      for (int j = 0; j < n; j++) {
         scanf("%d", &factor[i][j]);
      }
   }

   for (int i = 0; i < m; i++) {
      for (int j = 0; j < q; j++) {
         multiply[i][j] = 0;
         for (int k = 0; k < n; k++) {
            multiply[i][j] += matrix[i][k] * factor[k][j];
         }
      }
   }

   printf("\nThe resulting matrix after multiplication:\n");
   for (int i = 0; i < m; i++) {
      for (int j = 0; j < q; j++) {
         printf("%d ", multiply[i][j]);
      }
      printf("\n");
   }

   return 0;
}