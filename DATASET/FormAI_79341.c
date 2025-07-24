//FormAI DATASET v1.0 Category: Arithmetic ; Style: optimized
#include <stdio.h>

int main() {
   int num1 = 10, num2 = 20, num3 = 30, num4 = 40;

   printf("Initial values: num1 = %d, num2 = %d, num3 = %d, num4 = %d\n", num1, num2, num3, num4);

   // swap the values of num1 and num2
    num1 = num1 ^ num2;
    num2 = num2 ^ num1;
    num1 = num1 ^ num2;

   // add 5 to num3 and subtract 5 from num4
    num3 += 5;
    num4 -= 5;

   printf("Final values: num1 = %d, num2 = %d, num3 = %d, num4 = %d\n", num1, num2, num3, num4);

   return 0;
}