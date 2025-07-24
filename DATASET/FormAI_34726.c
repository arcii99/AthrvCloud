//FormAI DATASET v1.0 Category: Pattern printing ; Style: peaceful
#include <stdio.h>
int main() {
   // Declare variables
   int rows, columns, i, j;
   
   // Prompt user for input
   printf("Enter the number of rows: ");
   scanf("%d", &rows);
   printf("Enter the number of columns: ");
   scanf("%d", &columns);
   
   // Print the pattern
   for(i = 1; i <= rows; i++) {
      for(j = 1; j <= columns; j++) {
         if(i == rows/2 || j == columns/2) {
            printf("*");
         } else {
            printf(" ");
         }
      }
      printf("\n"); // Move to the next line
   }
   
   return 0;
}