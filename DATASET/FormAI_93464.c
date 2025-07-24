//FormAI DATASET v1.0 Category: Bitwise operations ; Style: unmistakable
#include <stdio.h>

/* Define constants for bitwise operations */
#define BIT_0 0x01
#define BIT_1 0x02
#define BIT_2 0x04
#define BIT_3 0x08
#define BIT_4 0x10
#define BIT_5 0x20
#define BIT_6 0x40
#define BIT_7 0x80

int main() {
    unsigned char data = 0x0F; // Initialize data to 00001111
    printf("Original Data: 0x%X\n\n", data);

    /* Bitwise AND operation example */
    printf("Bitwise AND operation with 0x01: 0x%X\n", (data & BIT_0)); // Result will be 00000001
    printf("Bitwise AND operation with 0x02: 0x%X\n", (data & BIT_1)); // Result will be 00000010
    printf("Bitwise AND operation with 0x04: 0x%X\n", (data & BIT_2)); // Result will be 00000100
    printf("Bitwise AND operation with 0x08: 0x%X\n", (data & BIT_3)); // Result will be 00001000
    printf("Bitwise AND operation with 0x10: 0x%X\n", (data & BIT_4)); // Result will be 00000000
    printf("Bitwise AND operation with 0x20: 0x%X\n", (data & BIT_5)); // Result will be 00000000
    printf("Bitwise AND operation with 0x40: 0x%X\n", (data & BIT_6)); // Result will be 00000000
    printf("Bitwise AND operation with 0x80: 0x%X\n", (data & BIT_7)); // Result will be 00000000

    /* Bitwise OR operation example */
    printf("\nBitwise OR operation with 0x80: 0x%X\n", (data | BIT_7)); // Result will be 00001111
    printf("Bitwise OR operation with 0x10: 0x%X\n", (data | BIT_4)); // Result will be 00011111

    /* Bitwise XOR operation example */
    printf("\nBitwise XOR operation with 0x01: 0x%X\n", (data ^ BIT_0)); // Result will be 00001110
    printf("Bitwise XOR operation with 0x0F: 0x%X\n", (data ^ 0x0F)); // Result will be 00000000

    /* Bitwise NOT operation example */
    printf("\nBitwise NOT operation: 0x%X\n", (~data)); // Result will be 0xF0

    /* Bitwise shift left operation example */
    printf("\nBitwise shift left operation: 0x%X\n", (data << 1)); // Result will be 00011110

    /* Bitwise shift right operation example */
    printf("\nBitwise shift right operation: 0x%X\n", (data >> 1)); // Result will be 00000111

    return 0;
}