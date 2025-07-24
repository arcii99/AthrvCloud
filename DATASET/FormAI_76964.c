//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Ada Lovelace
#include <stdio.h>

int count_bits(int num) {
   int count = 0;
   while(num) {
      if(num & 1)
         count++;
      num >>= 1;
   }
   return count;
}

int main() {
   int arr[5] = {2, 5, 9, 12, 17};
   int total_bits = 0;

   for(int i=0; i<5; i++) {
      total_bits += count_bits(arr[i]);
   }

   printf("Total number of set bits: %d\n", total_bits);
   return 0;
}