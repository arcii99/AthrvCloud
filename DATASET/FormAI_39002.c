//FormAI DATASET v1.0 Category: Pattern printing ; Style: multiplayer
#include <stdio.h>

int main() {

   int row, col, n;
   printf("Enter the size of pattern: ");
   scanf("%d", &n);
  
   for (row = 1; row <= n; row++) {
       
       for (col = 1; col <= n; col++) {
           
           if (col == 1 || row == 1 || row == n/2+1) {

               printf("*");
           }
           
           else if (row <= n/2 && col == row+1) {
               
               printf("*");
           }
           
           else if (row > n/2 && col == n-row+1) {

               printf("*");
           }
           
           else {

               printf(" ");
           }
       }
       printf("\n");
   }
   return 0;
}