//FormAI DATASET v1.0 Category: Bitwise operations ; Style: imaginative
#include<stdio.h>

int main() {
   int a = 6, b = 5, result;
   printf("Bitwise Operations in C\n");

   // Bitwise AND operation
   result = a & b;
   printf("a & b is %d\n", result);

   // Bitwise OR operation
   result = a | b;
   printf("a | b is %d\n", result);

   // Bitwise NOT operation
   result = ~a;
   printf("~a is %d\n", result);

   // Bitwise XOR operation
   result = a ^ b;
   printf("a ^ b is %d\n", result);

   // Bitwise left shift operation
   result = a << 2;
   printf("a << 2 is %d\n", result);

   // Bitwise right shift operation
   result = a >> 2;
   printf("a >> 2 is %d\n", result);

   // Checking the nth bit of a number using a bitmask
   int n = 2; // Checking for the 2nd bit
   int mask = 1 << n;
   result = a & mask; // Performing bitwise AND operation
   if (result == 0) {
     printf("The %dth bit of %d is 0\n", n, a);
   }
   else {
     printf("The %dth bit of %d is 1\n", n, a);
   }

   // Setting the nth bit of a number using a bitmask
   n = 3; // Setting the 3rd bit
   mask = 1 << n;
   result = a | mask; // Performing bitwise OR operation
   printf("After setting the %dth bit, the result is %d\n", n, result);

   // Clearing the nth bit of a number using a bitmask
   n = 1; // Clearing the 1st bit
   mask = ~(1 << n);
   result = a & mask; // Performing bitwise AND operation
   printf("After clearing the %dth bit, the result is %d\n", n, result);

   return 0;
}