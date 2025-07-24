//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int i, j, k, l, m, n;
   srand(time(NULL));
   i = rand() % 50 + 1;
   j = rand() % 50 + 1;
   k = rand() % 50 + 1;
   l = rand() % 50 + 1;
   m = rand() % 50 + 1;
   n = rand() % 50 + 1;
   int arr[i][j][k][l][m][n];
   int sum = 0;
   for (i = 0; i < 50; i++) {
      for (j = 0; j < 50; j++) {
         for (k = 0; k < 50; k++) {
            for (l = 0; l < 50; l++) {
               for (m = 0; m < 50; m++) {
                  for (n = 0; n < 50; n++) {
                     arr[i][j][k][l][m][n] = rand() % 100;
                     sum += arr[i][j][k][l][m][n];
                  }
               }
            }
         }
      }
   }
   printf("The sum of all the elements in the array is: %d\n", sum);
   return 0;
}