//FormAI DATASET v1.0 Category: Matrix operations ; Style: detailed
#include<stdio.h>

int main() {
   int m, n, p, q, i, j, k;
   int A[10][10], B[10][10], C[10][10];

   printf("Enter number of rows and columns of A matrix: ");
   scanf("%d%d", &m, &n);

   printf("Enter elements of A matrix:\n");
   for(i=0; i<m; i++)
      for(j=0; j<n; j++)
         scanf("%d", &A[i][j]);

   printf("Enter number of rows and columns of B matrix: ");
   scanf("%d%d", &p, &q);

   if(n != p)
      printf("Matrices can't be multiplied\n");
   else {

      printf("Enter elements of B matrix:\n");
      for(i=0; i<p; i++)
         for(j=0; j<q; j++)
            scanf("%d", &B[i][j]);

      for(i=0; i<m; i++) {
         for(j=0; j<q; j++) {
            C[i][j] = 0;
            for(k=0; k<p; k++)
               C[i][j] += A[i][k] * B[k][j];
         }
      }

      printf("Product of the matrices is:\n");
      for(i=0; i<m; i++) {
         for(j=0; j<q; j++)
            printf("%d ", C[i][j]);
         printf("\n");
      }
   }

   return 0;
}