//FormAI DATASET v1.0 Category: Bitwise operations ; Style: romantic
#include <stdio.h>

int main() {
   int x = 2, y = 3;
   
   // bitwise AND
   printf("Bitwise AND operator example:\n");
   printf("%d & %d = %d\n\n", x, y, x&y);

   // bitwise OR
   printf("Bitwise OR operator example:\n");
   printf("%d | %d = %d\n\n", x, y, x|y);

   // bitwise XOR
   printf("Bitwise XOR operator example:\n");
   printf("%d ^ %d = %d\n\n", x, y, x^y);

   // bitwise NOT
   printf("Bitwise NOT operator example:\n");
   printf("~%d = %d\n~%d = %d\n\n", x, ~x, y, ~y);

   // left shift
   printf("Left shift operator example:\n");
   printf("%d << 1 = %d\n\n", x, x<<1);

   // right shift
   printf("Right shift operator example:\n");
   printf("%d >> 1 = %d\n\n", y, y>>1);

   return 0;
}