//FormAI DATASET v1.0 Category: Bitwise operations ; Style: accurate
#include <stdio.h>

// Function to display binary representation of a number
void binary(long n) {
    if (n > 1)
        binary(n/2);

    printf("%ld", n % 2);
}

int main() {
    unsigned int x = 0b1100110;  // binary representation of 102
    unsigned int y = 0b1010010;  // binary representation of 82

    // Bitwise AND operation
    printf("x & y = ");
    binary(x & y);  // output: 1000000

    // Bitwise OR operation
    printf("\nx | y = ");
    binary(x | y);  // output: 1110110

    // Bitwise XOR operation
    printf("\nx ^ y = ");
    binary(x ^ y);  // output: 110010

    // Bitwise NOT operation
    printf("\n~x = ");
    binary(~x);  // output: 11111111111111111111111100110001

    // Left shift operation
    printf("\nx << 2 = ");
    binary(x << 2);  // output: 110011000

    // Right shift operation
    printf("\nx >> 2 = ");
    binary(x >> 2);  // output: 1100

    // Bitwise AND assignment
    x &= y;
    printf("\nBitwise AND assignment: x = ");
    binary(x);  // output: 1000000

    // Bitwise XOR assignment
    x ^= y;
    printf("\nBitwise XOR assignment: x = ");
    binary(x);  // output: 1110110

    // Bitwise OR assignment
    x |= y;
    printf("\nBitwise OR assignment: x = ");
    binary(x);  // output: 1111110

    return 0;
}