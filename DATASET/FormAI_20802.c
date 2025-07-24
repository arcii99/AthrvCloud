//FormAI DATASET v1.0 Category: Data mining ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main() {
   int data[10] = {1, 2, 2, 3, 4, 4, 4, 5, 6, 7};
   int freq[10] = {0};
   int i, j;

   for (i = 0; i < 10; i++) {
      freq[data[i]]++;
   }

   printf("Data\tFrequency\n");
   for (i = 0; i < 10; i++) {
      if (freq[i]) {
         printf("%d\t%d\n", i, freq[i]);
      }
   }

   return 0;
}