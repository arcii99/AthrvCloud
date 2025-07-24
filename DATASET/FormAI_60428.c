//FormAI DATASET v1.0 Category: Pattern printing ; Style: imaginative
#include <stdio.h>

int main() {
   int rowCount, colCount, rowCounter, colCounter, num;
   printf("Enter the number of rows to be printed: ");
   scanf("%d", &rowCount);
   colCount = (2 * rowCount) - 1;
   num = rowCount;

   for (rowCounter = 1; rowCounter <= rowCount; rowCounter++) {
      for (colCounter = 1; colCounter <= colCount; colCounter++) {
         if (colCounter >= num && colCounter <= colCount - num + 1) {
            printf("%d", num);
         } else {
            printf(" ");
         }
      }
      printf("\n");
      num--;
   }
   num = 2;
   for (rowCounter = rowCount; rowCounter >= 1; rowCounter--) {
      for (colCounter = 1; colCounter <= colCount; colCounter++) {
         if (colCounter >= num && colCounter <= colCount - num + 1) {
            printf("%d", num);
         } else {
            printf(" ");
         }
      }
      printf("\n");
      num++;
   }

   return 0;
}