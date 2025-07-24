//FormAI DATASET v1.0 Category: Arithmetic ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

int main() {
   int x = 5;
   int y = 2;
   int z = 1;
   float a = 7.0;
   float b = 3.0;
   float c = 2.0;
   
   printf("x = %d, y = %d, z = %d, a = %.2f, b = %.2f, c = %.2f\n\n", x, y, z, a, b, c);
   
   // Arithmetic operations with mixed data types
   int int_result = x + y - z;
   float float_result = a / b * c;
   double double_result = x * y / (a - b) + z;

   printf("int_result = %d\n", int_result);
   printf("float_result = %.2f\n", float_result);
   printf("double_result = %.2f\n\n", double_result);

   // Increment and decrement operators
   int i = 0;
   printf("i = %d\n", i);
   i++;
   printf("i = %d\n", i);
   i--;
   printf("i = %d\n\n", i);

   // Bitwise operators
   int bitwise_and = x & y;
   int bitwise_or = x | y;
   int bitwise_xor = x ^ y;
   int bitwise_complement = ~x;

   printf("bitwise_and = %d\n", bitwise_and);
   printf("bitwise_or = %d\n", bitwise_or);
   printf("bitwise_xor = %d\n", bitwise_xor);
   printf("bitwise_complement = %d\n\n", bitwise_complement);

   // Conditional operators
   int result1 = x > y ? 1 : 0;
   int result2 = x < y ? 1 : 0;
   int result3 = x == y ? 1 : 0;
   int result4 = a != b ? 1 : 0;

   printf("result1 = %d\n", result1);
   printf("result2 = %d\n", result2);
   printf("result3 = %d\n", result3);
   printf("result4 = %d\n\n", result4);

   // Logical operators
   int logical_and = x > y && z < y;
   int logical_or = x > y || z < y;
   int logical_not = !(x > y);

   printf("logical_and = %d\n", logical_and);
   printf("logical_or = %d\n", logical_or);
   printf("logical_not = %d\n", logical_not);

   return 0;
}