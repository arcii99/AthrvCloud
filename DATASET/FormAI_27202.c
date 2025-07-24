//FormAI DATASET v1.0 Category: Bitwise operations ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>

int main(){
   int a = 5, b = 9, c = 2, d = 6, result1, result2, result3, result4;
   
   // Bitwise AND operator
   result1 = a & b;
   printf("Bitwise AND operation of %d and %d = %d\n", a, b, result1);
   
   // Bitwise OR operator
   result2 = c | d;
   printf("Bitwise OR operation of %d and %d = %d\n", c, d, result2);
   
   // Bitwise XOR operator
   result3 = a ^ c;
   printf("Bitwise XOR operation of %d and %d = %d\n", a, c, result3);
   
   // Bitwise NOT operator
   result4 = ~d;
   printf("Bitwise NOT operation of %d = %d\n", d, result4);
   
   return 0;
}