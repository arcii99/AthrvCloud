//FormAI DATASET v1.0 Category: Educational ; Style: sophisticated
#include <stdio.h>

int main() {
   printf("This is a program to perform matrix multiplication!\n");
   int m, n, p, q, i, j, k;
   printf("Enter the number of rows of the first matrix: ");
   scanf("%d",&m);
   printf("Enter the number of columns of the first matrix: ");
   scanf("%d",&n);
   printf("Enter the number of rows of the second matrix: ");
   scanf("%d",&p);
   printf("Enter the number of columns of the second matrix: ");
   scanf("%d",&q);

   if(n != p) {
      printf("Error: the number of columns of the first matrix must match the number of rows of the second matrix.\n");
      return 0;
   }

   int first[m][n], second[p][q], result[m][q];

   printf("Enter the elements of the first matrix: \n");
   for(i = 0; i < m; i++) {
      for(j = 0; j < n; j++) {
         scanf("%d",&first[i][j]);
      }
   }

   printf("Enter the elements of the second matrix: \n");
   for(i = 0; i < p; i++) {
      for(j = 0; j < q; j++) {
         scanf("%d",&second[i][j]);
      }
   }

   for(i = 0; i < m; i++) {
      for(j = 0; j < q; j++) {
         result[i][j] = 0;
      }
   }

   for(i = 0; i < m; i++) {
      for(j = 0; j < q; j++) {
         for(k = 0; k < n; k++) {
            result[i][j] += first[i][k] * second[k][j];
         }
      }
   }

   printf("The product of the two matrices is: \n");
   for(i = 0; i < m; i++) {
      for(j = 0; j < q; j++) {
         printf("%d ",result[i][j]);
      }
      printf("\n");
   }

   return 0;
}