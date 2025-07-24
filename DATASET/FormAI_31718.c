//FormAI DATASET v1.0 Category: Bitwise operations ; Style: accurate
#include<stdio.h>

int main() {
    int a = 6, b = 5;
    printf("Initial Values of a and b : %d %d\n", a, b);

    // Bitwise AND operation
    int bitAnd = a & b;
    printf("Result of Bitwise AND : %d\n", bitAnd);

    // Bitwise OR operation
    int bitOr = a | b;
    printf("Result of Bitwise OR : %d\n", bitOr);

    // Bitwise Negation operation
    int bitNeg = ~a;
    printf("Result of Bitwise Negation : %d\n", bitNeg);

    // Bitwise XOR operation
    int bitXor = a ^ b;
    printf("Result of Bitwise XOR : %d\n", bitXor);

    // Left Shift operation
    int leftShift = a << 2;
    printf("Result of Left Shift : %d\n", leftShift);

    // Right Shift operation
    int rightShift = b >> 1;
    printf("Result of Right Shift : %d\n", rightShift);

    // Unsigned Right Shift Operation
    unsigned int unsignedRightShift = a >> 1;
    printf("Result of Unsigned Right Shift : %u\n", unsignedRightShift);

    return 0;
}