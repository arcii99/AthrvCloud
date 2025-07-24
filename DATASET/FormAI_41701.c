//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: optimized
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
   if(num == 1)
      return false;
   if(num == 2 || num == 3)
      return true;
   if(num % 2 == 0 || num % 3 == 0)
      return false;
   int i = 5;
   int w = 2;
   while(i*i <= num) {
      if(num % i == 0)
         return false;
      i += w;
      w = 6 - w;
   }
   return true;
}

int main() {
   int count = 0;
   int num = 2;
   printf("The first 100 prime numbers are:\n");
   while(count < 100) {
      if(is_prime(num)) {
         printf("%d ", num);
         count++;
      }
      num++;
   }
   return 0;
}