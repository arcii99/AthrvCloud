//FormAI DATASET v1.0 Category: Bitwise operations ; Style: innovative
#include <stdio.h>

int main() {
   // Bitwise AND
   int x = 7;   // 0111b in binary
   int y = 12;  // 1100b in binary
   int z = x & y;
   printf("%d & %d = %d\n", x, y, z);  // prints: 4
   
   // Bitwise OR
   x = 7;    // 0111b in binary
   y = 12;   // 1100b in binary
   z = x | y;
   printf("%d | %d = %d\n", x, y, z);   // prints: 15
   
   // Bitwise XOR
   x = 7;    // 0111b in binary
   y = 12;   // 1100b in binary
   z = x ^ y;
   printf("%d ^ %d = %d\n", x, y, z);   // prints: 11
   
   // Bitwise NOT
   x = 7;    // 0111b in binary
   z = ~x;
   printf("~%d = %d\n", x, z);   // prints: -8
   
   // Left shift
   x = 7;    // 0111b in binary
   z = x << 2;
   printf("%d << 2 = %d\n", x, z);   // prints: 28
   
   // Right shift
   x = 7;    // 0111b in binary
   z = x >> 2;
   printf("%d >> 2 = %d\n", x, z);   // prints: 1
   
   return 0;
}