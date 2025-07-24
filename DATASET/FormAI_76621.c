//FormAI DATASET v1.0 Category: Bitwise operations ; Style: satisfied
#include <stdio.h>

int main() {
    unsigned int num1 = 7;  // 0111 in binary
    unsigned int num2 = 10; // 1010 in binary

    // Bitwise AND operation
    unsigned int result = num1 & num2;
    printf("Bitwise AND of %u and %u = %u\n", num1, num2, result);

    // Bitwise OR operation
    result = num1 | num2;
    printf("Bitwise OR of %u and %u = %u\n", num1, num2, result);

    // Bitwise XOR operation
    result = num1 ^ num2;
    printf("Bitwise XOR of %u and %u = %u\n", num1, num2, result);

    // Bitwise NOT operation
    result = ~num1;
    printf("Bitwise NOT of %u = %u\n", num1, result);

    // Bitwise shift left operation
    result = num1 << 1;
    printf("Bitwise shift left of %u by 1 = %u\n", num1, result);

    // Bitwise shift right operation
    result = num2 >> 1;
    printf("Bitwise shift right of %u by 1 = %u\n", num2, result);

    return 0;
}