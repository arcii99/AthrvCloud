//FormAI DATASET v1.0 Category: Bitwise operations ; Style: bold
#include<stdio.h>
#include<stdint.h>

int main() {
    uint8_t x = 0b10101010; // Binary value 85 in decimal
    uint8_t y = 0b00111001; // Binary value 57 in decimal

    // Bitwise AND
    uint8_t and_result = x & y; // Binary value 0b00101000
    printf("Bitwise AND result is: %d\n", and_result);

    // Bitwise OR
    uint8_t or_result = x | y; // Binary value 0b10111011
    printf("Bitwise OR result is: %d\n", or_result);

    // Bitwise XOR
    uint8_t xor_result = x ^ y; // Binary value 0b10010011
    printf("Bitwise XOR result is: %d\n", xor_result);

    // Bitwise NOT
    uint8_t not_result = ~x; // Binary value 0b01010101 (two's complement of x)
    printf("Bitwise NOT result on x is: %d\n", not_result);

    // Left shift
    uint8_t left_shift_result = x << 3; // Binary value 0b01010000
    printf("Left shift result on x is: %d\n", left_shift_result);

    // Right shift
    uint8_t right_shift_result = y >> 2; // Binary value 0b00001110
    printf("Right shift result on y is: %d\n", right_shift_result);

    // Bitwise AND assignment
    uint8_t z = 0b11110000;
    z &= x; // Binary value 0b10100000 (z = z & x)
    printf("Bitwise AND assignment result on z is: %d\n", z);

    // Bitwise OR assignment
    z = 0b00001111;
    z |= y; // Binary value 0b00111111 (z = z | y)
    printf("Bitwise OR assignment result on z is: %d\n", z);

    // Bitwise XOR assignment
    z = 0b11001100;
    z ^= x; // Binary value 0b01100110 (z = z ^ x)
    printf("Bitwise XOR assignment result on z is: %d\n", z);
    
    return 0;
}