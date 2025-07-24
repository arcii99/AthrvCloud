//FormAI DATASET v1.0 Category: Pattern printing ; Style: scientific
#include <stdio.h>
int main() {
   int i, j, rows;
   printf("Enter the number of rows: ");
   scanf("%d",&rows);
   for(i=1;i<=rows;i++) {
      for(j=1;j<=rows;j++) {
         if(j<=i)
            printf("%c ", 64+j);
         else
            printf(" "); 
      }
      printf("\n");
   }
   for(i=rows;i>=1;i--) {
      for(j=1;j<=rows;j++) {
         if(j<=i)
            printf("%c ", 64+j);
         else
            printf(" "); 
      }
      printf("\n");
   }
   return 0;
}