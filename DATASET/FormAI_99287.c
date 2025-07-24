//FormAI DATASET v1.0 Category: Graph representation ; Style: energetic
#include <stdio.h>

int main() {
   int i, j, rows, columns, count = 1;

   printf("Enter the number of rows: ");
   scanf("%d", &rows);

   printf("Enter the number of columns: ");
   scanf("%d", &columns);

   int a[rows][columns];

   //populate the array
   for (i = 0; i < rows; i++) {
      for (j = 0; j < columns; j++) {
         a[i][j] = count++;
      }
   }
   
   //display the graph representation
   printf("\nGraph representation:\n\n");

   for (i = 0; i < rows; i++) {
      for (j = 0; j < columns; j++) {
         if (a[i][j] % 2 == 0) {
            printf("   *");
         } else {
            printf(" ___");
         }
      }
      printf("\n");

      for (j = 0; j < columns; j++) {
         if (a[i][j] % 3 == 0) {
            printf("| %d ", a[i][j]);
         } else {
            printf("|   ");
         }
      }
      printf("|\n");
   }

   //end program
   printf("\n");
   return 0;
}