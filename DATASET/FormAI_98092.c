//FormAI DATASET v1.0 Category: Pattern printing ; Style: realistic
#include<stdio.h>

int main() {
   int rows, i, j, k;

   // Get user input for number of rows
   printf("Enter the number of rows: ");
   scanf("%d", &rows);

   // Print first half of pattern
   for(i=1; i<=rows; i++) {
      for(j=1; j<=i; j++) {
         printf("%d ", j);
      }
      for(k=i*2-2; k<rows*2-2; k++) {
        printf("  ");
      }
      for(j=i; j>0; j--) {
         printf("%d ", j);
      }
      printf("\n");
   }

   // Print second half of pattern
   for(i=rows-1; i>0; i--) {
      for(j=1; j<=i; j++) {
         printf("%d ", j);
      }
      for(k=i*2-2; k<rows*2-2; k++) {
         printf("  ");
      }
      for(j=i; j>0; j--) {
         printf("%d ", j);
      }
      printf("\n");
   }

   return 0;
}