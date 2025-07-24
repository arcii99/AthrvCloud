//FormAI DATASET v1.0 Category: Bitwise operations ; Style: sophisticated
#include<stdio.h>
#include<stdint.h>
#include <inttypes.h>
/*This is a sophisticated program that demonstrates bitwise operations in C!*/

int main(void){

   uint16_t num1, num2;
   uint32_t result; 
    
   printf("Enter an unsigned 16-bit integer number 1: ");
   scanf("%"SCNu16, &num1);
    
   printf("Enter another unsigned 16-bit integer number 2: ");
   scanf("%"SCNu16, &num2);

   result = (num1 & num2); //bitwise AND operation
   printf("\nRESULT OF BITWISE AND : %"PRIu32"\n", result);

   result = (num1 | num2); //bitwise OR operation
   printf("\nRESULT OF BITWISE OR : %"PRIu32"\n", result);

   result = (num1 ^ num2); //bitwise XOR operation
   printf("\nRESULT OF BITWISE XOR : %"PRIu32"\n", result);

   result = (~num1); //bitwise NOT operation
   printf("\nRESULT OF BITWISE NOT ON NUMBER 1: %"PRIu32"\n", result);

   result = num1 << 2; //left bit shift operation
   printf("\nRESULT OF LEFT BIT SHIFT BY 2 : %"PRIu32"\n", result);

   result = num2 >> 2; //right bit shift operation
   printf("\nRESULT OF RIGHT BIT SHIFT BY 2 : %"PRIu32"\n", result);

   printf("\nSophisticated Bitwise Operations Program Completed!\n");

   return 0;
}
