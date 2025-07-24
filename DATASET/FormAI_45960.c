//FormAI DATASET v1.0 Category: Bitwise operations ; Style: puzzling
#include <stdio.h>

int main() {
   int a = 10, b = 15;
   printf("Initial values: a = %d, b = %d\n", a, b);
   
   a ^= b;
   b ^= a;
   a ^= b;
   printf("After swapping: a = %d, b = %d\n", a, b);

   int n = 6, k = 4;
   printf("Initial values: n = %d, k = %d\n", n, k);

   int result = n & (1 << k);
   printf("The %dth bit of n is %d\n", k, (result > 0));

   int x = 7, y = 3;
   printf("Initial values: x = %d, y = %d\n", x, y);

   x = x & ~(1 << y);
   printf("After clearing %dth bit of x, x = %d\n", y, x);

   int num = 100;
   printf("Initial value: num = %d\n", num);

   int count = 0;
   while(num) {
      count++;
      num &= (num - 1);
   }

   printf("The number of set bits in %d = %d\n", 100, count);
   
   return 0;
}