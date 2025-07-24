//FormAI DATASET v1.0 Category: Stock market tracker ; Style: imaginative
#include <stdio.h>

int main() {
   int num[] = {12, 8, 5, 2, 10};
   int i, j, temp;

   printf("Original Array: ");
   for (i = 0; i < 5; i++)
      printf("%d ", num[i]);

   for (i = 0; i < 5; i++) {
      for (j = i+1; j < 5; j++){
          if(num[i] > num[j]) {
             temp = num[i];
             num[i] = num[j];
             num[j] = temp;
          }
      }
   }

   printf("\nSorted Array: ");
   for (i = 0; i < 5; i++)
      printf("%d ", num[i]);

   return 0;
}