//FormAI DATASET v1.0 Category: Bitwise operations ; Style: high level of detail
#include <stdio.h>

int main() {
    unsigned char x = 0b00001111; // binary representation of 15
    unsigned char y = 0b00010010; // binary representation of 18

    printf("x = %d\n", x); // prints x in decimal format
    printf("y = %d\n\n", y); // prints y in decimal format

    // Bitwise AND
    unsigned char z = x & y; // performs bitwise AND operation
    printf("x & y = %d\n", z); // prints z in decimal format
    printf("x & y in binary = %d%d%d%d\n\n", (z >> 3) & 1, (z >> 2) & 1, (z >> 1) & 1, z & 1); // prints z in binary format

    // Bitwise OR
    z = x | y; // performs bitwise OR operation
    printf("x | y = %d\n", z); // prints z in decimal format
    printf("x | y in binary = %d%d%d%d\n\n", (z >> 3) & 1, (z >> 2) & 1, (z >> 1) & 1, z & 1); // prints z in binary format

    // Bitwise XOR
    z = x ^ y; // performs bitwise XOR operation
    printf("x ^ y = %d\n", z); // prints z in decimal format
    printf("x ^ y in binary = %d%d%d%d\n\n", (z >> 3) & 1, (z >> 2) & 1, (z >> 1) & 1, z & 1); // prints z in binary format

    // Bitwise NOT
    z = ~x; // performs bitwise NOT operation
    printf("~x = %d\n", z); // prints z in decimal format
    printf("~x in binary = %d%d%d%d\n\n", (z >> 3) & 1, (z >> 2) & 1, (z >> 1) & 1, z & 1); // prints z in binary format

    // Left Shift
    z = x << 3; // performs left shift operation
    printf("x << 3 = %d\n", z); // prints z in decimal format
    printf("x << 3 in binary = %d%d%d%d\n\n", (z >> 3) & 1, (z >> 2) & 1, (z >> 1) & 1, z & 1); // prints z in binary format

    // Right Shift
    z = y >> 2; // performs right shift operation
    printf("y >> 2 = %d\n", z); // prints z in decimal format
    printf("y >> 2 in binary = %d%d%d%d\n\n", (z >> 3) & 1, (z >> 2) & 1, (z >> 1) & 1, z & 1); // prints z in binary format

    return 0;
}