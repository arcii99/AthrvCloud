//FormAI DATASET v1.0 Category: Bitwise operations ; Style: retro
#include <stdio.h>

int main() {
    unsigned int num = 170; // binary 10101010
    unsigned int mask = 85; // binary 01010101
    unsigned int result;

    printf("Original number: %u\n", num);
    printf("Mask: %u\n", mask);

    // Bitwise AND operator
    result = num & mask;
    printf("Bitwise AND result: %u\n", result);

    // Bitwise OR operator
    result = num | mask;
    printf("Bitwise OR result: %u\n", result);

    // Bitwise XOR operator
    result = num ^ mask;
    printf("Bitwise XOR result: %u\n", result);

    // Bitwise NOT operator
    result = ~num;
    printf("Bitwise NOT result: %u\n", result);

    // Bitwise left shift operator
    result = num << 2;
    printf("Bitwise left shift result: %u\n", result);

    // Bitwise right shift operator
    result = num >> 2;
    printf("Bitwise right shift result: %u\n", result);

    // Bitwise complement operator
    result = !num;
    printf("Bitwise complement result: %u\n", result);

    return 0;
}