//FormAI DATASET v1.0 Category: Database Indexing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
   char table[20][20];
   char index[20][20];
   int i, j, rows, columns;
   
   printf("Enter the number of rows and columns: ");
   scanf("%d %d", &rows, &columns);

   printf("Enter the table contents: \n");
   for (i = 0; i < rows; i++) {
      for (j = 0; j < columns; j++) {
         scanf("%s", &table[i][j]);
      }
   }
   
   printf("Enter the index values: \n");
   for (i = 0; i < rows; i++) {
      scanf("%s", &index[i]);
   }
   
   printf("Indexing table...\n");
   
   for (i = 0; i < rows; i++) {
      for (j = 0; j < columns; j++) {
         if (table[i][j] == index[i]) {
            printf("%s ", &table[i][j]);
         }
      }
   }
   
   return 0;
}