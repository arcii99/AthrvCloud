//FormAI DATASET v1.0 Category: Bitwise operations ; Style: protected
#include <stdio.h>

int main() {
    unsigned int num1 = 17; // 00010001
    unsigned int num2 = 10; // 00001010

    // Bitwise AND
    unsigned int result1 = num1 & num2;
    printf("result of num1 & num2 is %u\n", result1); // 00000000

    // Bitwise OR
    unsigned int result2 = num1 | num2;
    printf("result of num1 | num2 is %u\n", result2); // 00011011

    // Bitwise XOR
    unsigned int result3 = num1 ^ num2;
    printf("result of num1 ^ num2 is %u\n", result3); // 00011011

    // Bitwise NOT (1's complement)
    unsigned int result4 = ~num1;
    printf("result of ~num1 is %u\n", result4); // 11101110

    // Left shift
    unsigned int result5 = num2 << 3;
    printf("result of num2 << 3 is %u\n", result5); // 01010000

    // Right shift
    unsigned int result6 = num1 >> 2;
    printf("result of num1 >> 2 is %u\n", result6); // 00000100

    return 0;
}