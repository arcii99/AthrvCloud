//FormAI DATASET v1.0 Category: Pattern printing ; Style: portable
#include <stdio.h>

int main() {
   int rows, cols, i, j, num = 1;
   printf("Enter the number of rows: ");
   scanf("%d", &rows);

   printf("Enter the number of columns: ");
   scanf("%d", &cols);

   // Upper part of the pattern
   
   for(i=0; i<(rows+1)/2; i++) {
       for(j=0; j<(cols+1)/2-i-1; j++) {
           printf("  ");
       }
       for(;j<(cols+1)/2+i; j++) {
           printf("%d ", num++);
       }
       for(;j<cols; j++) {
           printf("  ");
       }
       printf("\n");
   }

   // Lower part of the pattern
   num = rows*cols;
   for(i=0; i<rows/2; i++) {
       for(j=0; j<=i; j++) {
           printf("  ");
       }
       for(;j<cols-i-1; j++) {
           printf("%d ", num--);
       }
       for(;j<cols; j++) {
           printf("  ");
       }
       printf("\n");
   }
   return 0;
}