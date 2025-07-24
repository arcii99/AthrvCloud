//FormAI DATASET v1.0 Category: Bitwise operations ; Style: relaxed
#include <stdio.h>

int main() {

    // Declare two variables to perform bitwise operations
    unsigned int a = 60; // Binary 0011 1100
    unsigned int b = 13; // Binary 0000 1101
     
    // Perform bitwise AND operator
    unsigned int result_AND = a & b; // Binary 0000 1100
     
    // Perform bitwise OR operator
    unsigned int result_OR = a | b;  // Binary 0011 1101
     
    // Perform bitwise XOR operator
    unsigned int result_XOR = a ^ b; // Binary 0011 0001
     
    // Perform bitwise NOT operator
    unsigned int result_NOT = ~a;    // Binary 1100 0011
     
    // Perform BIT SHIFT operator
    unsigned int result_SHIFT = a << 2; // Binary 1111 0000
     
    // Display the results
    printf("a & b = %u\n", result_AND);
    printf("a | b = %u\n", result_OR);
    printf("a ^ b = %u\n", result_XOR);
    printf("~a = %u\n", result_NOT);
    printf("a << 2 = %u\n", result_SHIFT);

    return 0;
}