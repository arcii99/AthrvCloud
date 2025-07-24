//FormAI DATASET v1.0 Category: Pattern printing ; Style: Cryptic
#include <stdio.h>

int main() {
   int n = 5;
   int arr[50][50];
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         arr[i][j] = 0;
      }
   }

   for (int i = 0; i < n; i++) {
      arr[i][i] = 1;
   }

   for (int i = 0; i < n; i++) {
      arr[n - i - 1][i] = 1;
   }

   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         printf("%d ", arr[i][j]);
      }
      printf("\n");
   }
   return 0;
}