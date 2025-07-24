//FormAI DATASET v1.0 Category: Bitwise operations ; Style: beginner-friendly
#include <stdio.h>

int main() {
    // Bitwise AND operation example
    int num1 = 12; // Binary representation: 0000 1100
    int num2 = 8; // Binary representation: 0000 1000
    int result = num1 & num2; // Binary representation: 0000 1000

    printf("Bitwise AND: %d\n", result);

    // Bitwise OR operation example
    num1 = 20; // Binary representation: 0001 0100
    num2 = 14; // Binary representation: 0000 1110
    result = num1 | num2; // Binary representation: 0001 1110

    printf("Bitwise OR: %d\n", result);

    // Bitwise XOR operation example
    num1 = 33; // Binary representation: 0010 0001
    num2 = 51; // Binary representation: 0011 0011
    result = num1 ^ num2; // Binary representation: 0001 0010

    printf("Bitwise XOR: %d\n", result);

    // Bitwise NOT operation example
    num1 = 7; // Binary representation: 0000 0111
    result = ~num1; // Binary representation: 1111 1000

    printf("Bitwise NOT: %d\n", result);

    // Bitwise left shift operation example
    num1 = 8; // Binary representation: 0000 1000
    result = num1 << 2; // Binary representation: 0010 0000

    printf("Bitwise left shift: %d\n", result);

    // Bitwise right shift operation example
    num1 = 64; // Binary representation: 0100 0000
    result = num1 >> 3; // Binary representation: 0000 0100

    printf("Bitwise right shift: %d\n", result);

    return 0;
}