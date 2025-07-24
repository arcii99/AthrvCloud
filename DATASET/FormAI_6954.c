//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
   int rows, cols, i, j, k;
   char symbol;
   
   printf("Enter the number of rows: ");
   scanf("%d", &rows);
   
   printf("Enter the number of columns: ");
   scanf("%d", &cols);
   
   printf("Enter the symbol to use: ");
   scanf("%c", &symbol);
   scanf("%c", &symbol);
   
   for(i=0; i<rows; i++) {
      for(j=0; j<cols; j++) {
         if(i==0 || i==rows-1 || j==0 || j==cols-1) {
            printf("%c", symbol);
         }
         else {
            printf(" ");
         }
      }
      printf("\n");
   }
   
   printf("The pixel art has been successfully generated!");
   return 0;
}