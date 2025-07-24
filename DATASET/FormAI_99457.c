//FormAI DATASET v1.0 Category: Bitwise operations ; Style: detailed
#include <stdio.h>

int main() {
   unsigned int x, y, z;

   printf("Enter two integers: ");
   scanf("%d%d",&x,&y);

   printf("\nBitwise AND of %d and %d = %d", x, y, x&y);
   printf("\nBitwise OR of %d and %d = %d", x, y, x|y);
   printf("\nBitwise XOR of %d and %d = %d", x, y, x^y);

   z = ~x;
   printf("\nBitwise NOT of %d = %d", x, z);

   z = x<<1;
   printf("\nLeft Shift of %d = %d", x, z);

   z = x>>1;
   printf("\nRight Shift of %d = %d\n", x, z);

   return 0;
}