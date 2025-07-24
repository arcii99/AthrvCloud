//FormAI DATASET v1.0 Category: Pattern printing ; Style: active
#include <stdio.h>

int main() {
   int rows, i, j, k;
   printf("Enter the number of rows: ");
   scanf("%d", &rows);
   for(i = 1; i <= rows; i++){
      for(j = 1; j <= i; j++){
         printf("%d ", j);
      }
      k = j - 2;
      for(j = k; j >= 1; j--){
         printf("%d ", j);
      }
      printf("\n");
   }
   for(i = rows-1; i >= 1; i--){
      for(j = 1; j <= i; j++){
         printf("%d ", j);
      }
      k = j - 2;
      for(j = k; j >= 1; j--){
         printf("%d ", j);
      }
      printf("\n");
   }
   return 0;
}