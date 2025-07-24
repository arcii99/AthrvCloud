//FormAI DATASET v1.0 Category: Bitwise operations ; Style: minimalist
#include <stdio.h>

int main() {
    int number = 53; // binary representation is 00110101
    int mask = 7; // binary representation is 00000111
    int result;

    printf("Number: %d\n", number);
    printf("Mask: %d\n", mask);

    // Bitwise AND operation
    result = number & mask;
    printf("Result of AND operation: %d\n", result); // prints 5 (00000101)

    // Bitwise OR operation
    result = number | mask;
    printf("Result of OR operation: %d\n", result); // prints 55 (00110111)

    // Bitwise XOR operation
    result = number ^ mask;
    printf("Result of XOR operation: %d\n", result); // prints 50 (00110010)

    // Bitwise NOT operation
    result = ~number;
    printf("Result of NOT operation: %d\n", result); // prints -54 (11001010)

    // Bitwise left shift operation
    result = number << 2;
    printf("Result of left shift operation: %d\n", result); // prints 212 (11010100)

    // Bitwise right shift operation
    result = number >> 2;
    printf("Result of right shift operation: %d\n", result); // prints 13 (00001101)

    return 0;
}