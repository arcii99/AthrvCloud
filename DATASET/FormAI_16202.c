//FormAI DATASET v1.0 Category: Pattern printing ; Style: complete
#include <stdio.h>

int main() {
   int rows, i, j, k;   
   char symbol;

   printf("How many rows do you want? ");   
   scanf("%d", &rows);
   printf("What character do you want to use? ");
   scanf(" %c", &symbol);

   for (i = 1; i <= rows; i++) {
      for (j = 1; j <= i; j++) {
         printf("%c", symbol);
      }
      for (k = j; k <= rows; k++) {
         printf(" ");
      }
      printf("\n");
   }

   for (i = rows - 1; i >= 1; i--) {
      for (j = 1; j <= i; j++) {
         printf("%c", symbol);
      }
      for (k = j; k <= rows; k++) {
         printf(" ");
      }
      printf("\n");
   }

   return 0;
}