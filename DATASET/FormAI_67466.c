//FormAI DATASET v1.0 Category: Matrix operations ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
   int a[3][3], b[3][3], c[3][3];
   int i, j, k;

   printf("Enter the elements of 3x3 matrix A:\n");
   for(i=0; i<3; i++) {
      for(j=0; j<3; j++) {
         scanf("%d", &a[i][j]);
      }
   }
   printf("Enter the elements of 3x3 matrix B:\n");
   for(i=0; i<3; i++) {
      for(j=0; j<3; j++) {
         scanf("%d", &b[i][j]);
      }
   }

   // matrix addition
   for(i=0; i<3; i++) {
      for(j=0; j<3; j++) {
         c[i][j] = a[i][j] + b[i][j];
      }
   }
   printf("Matrix A + B is:\n");
   for(i=0; i<3; i++) {
      for(j=0; j<3; j++) {
         printf("%d ", c[i][j]);
      }
      printf("\n");
   }

   // matrix multiplication
   for(i=0; i<3; i++) {
      for(j=0; j<3; j++) {
         c[i][j] = 0;
         for(k=0; k<3; k++) {
            c[i][j] += a[i][k] * b[k][j];
         }
      }
   }
   printf("Matrix A * B is:\n");
   for(i=0; i<3; i++) {
      for(j=0; j<3; j++) {
         printf("%d ", c[i][j]);
      }
      printf("\n");
   }

   return 0;
}