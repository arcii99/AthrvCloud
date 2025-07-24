//FormAI DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>

int main() {
   int array1[3][3], array2[3][3], result[3][3], i, j, k, sum;

   printf("Enter the first matrix:\n");
   for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
         scanf("%d", &array1[i][j]);
      }
   }

   printf("Enter the second matrix:\n");
   for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
         scanf("%d", &array2[i][j]);
      }
   }

   for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
         sum = 0;
         for (k = 0; k < 3; k++) {
            sum = sum + array1[i][k] * array2[k][j];
         }
         result[i][j] = sum;
      }
   }

   printf("\nProduct of two matrices:\n");
   for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
         printf("%d\t", result[i][j]);
      }
      printf("\n");
   }

   return 0;
}