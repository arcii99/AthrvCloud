//FormAI DATASET v1.0 Category: Bitwise operations ; Style: enthusiastic
#include <stdio.h>

int main() {
    int a = 5; // 0101 in binary
    int b = 3; // 0011 in binary

    int c = a | b; // Bitwise OR
    printf("a | b = %d\n", c); // Output: 7 (0111 in binary)

    c = a & b; // Bitwise AND
    printf("a & b = %d\n", c); // Output: 1 (0001 in binary)

    c = a ^ b; // Bitwise XOR
    printf("a ^ b = %d\n", c); // Output: 6 (0110 in binary)

    c = ~a; // Bitwise NOT
    printf("~a = %d\n", c); // Output: -6 (11111010 in binary)

    c = a << 1; // Bitwise Left Shift
    printf("a << 1 = %d\n", c); // Output: 10 (1010 in binary)

    c = b >> 1; // Bitwise Right Shift
    printf("b >> 1 = %d\n", c); // Output: 1 (0001 in binary)

    return 0;
}