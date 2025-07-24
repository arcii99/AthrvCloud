//FormAI DATASET v1.0 Category: Recursive ; Style: artistic
#include <stdio.h>

void drawSquare(int size, int row, int col) {
   if(row<=size){
      if(col<=size){
         printf("* ");
         col++;
         drawSquare(size, row, col);
      }else{
         printf("\n");
         row++;
         drawSquare(size, row, 1);
      }
   }
}

int main() {
   int size;

   printf("Enter size of square: ");
   scanf("%d", &size);

   drawSquare(size, 1, 1);

   return 0;
}