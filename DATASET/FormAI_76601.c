//FormAI DATASET v1.0 Category: Pattern printing ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
   int size, i, j, mid;
   printf("Enter size of pattern (odd number): ");
   scanf("%d", &size);
   
   if(size % 2 == 0) {
      printf("Error: Size of pattern must be an odd number.\n");
      return 0;
   }
   
   mid = size / 2;
   
   // upper half of pattern
   for(i=0; i<mid; i++) {
      for(j=0; j<size; j++) {
         if(j <= i || j >= size-i-1)
            printf("* ");
         else
            printf("  ");
      }
      printf("\n");
   }
   
   // middle row of pattern
   for(j=0; j<size; j++)
      printf("* ");
   printf("\n");
   
   // lower half of pattern
   for(i=mid-1; i>=0; i--) {
      for(j=0; j<size; j++) {
         if(j <= i || j >= size-i-1)
            printf("* ");
         else
            printf("  ");
      }
      printf("\n");
   }
   
   return 0;
}