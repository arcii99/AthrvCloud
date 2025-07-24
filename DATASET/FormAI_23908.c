//FormAI DATASET v1.0 Category: Bitwise operations ; Style: expert-level
#include <stdio.h>

int main() {
    // Example program that uses bitwise operations to manipulate binary data
    unsigned int num1 = 0b00110101;
    unsigned int num2 = 0b11001100;
    unsigned int result;

    printf("num1 in binary: %d%d%d%d%d%d%d%d\n", 
           (num1 & 0b10000000) >> 7,
           (num1 & 0b01000000) >> 6,
           (num1 & 0b00100000) >> 5,
           (num1 & 0b00010000) >> 4,
           (num1 & 0b00001000) >> 3,
           (num1 & 0b00000100) >> 2,
           (num1 & 0b00000010) >> 1,
           num1 & 0b00000001);
    printf("num2 in binary: %d%d%d%d%d%d%d%d\n", 
           (num2 & 0b10000000) >> 7,
           (num2 & 0b01000000) >> 6,
           (num2 & 0b00100000) >> 5,
           (num2 & 0b00010000) >> 4,
           (num2 & 0b00001000) >> 3,
           (num2 & 0b00000100) >> 2,
           (num2 & 0b00000010) >> 1,
           num2 & 0b00000001);

    // Bitwise AND
    result = num1 & num2;
    printf("num1 & num2 in binary: %d%d%d%d%d%d%d%d\n", 
           (result & 0b10000000) >> 7,
           (result & 0b01000000) >> 6,
           (result & 0b00100000) >> 5,
           (result & 0b00010000) >> 4,
           (result & 0b00001000) >> 3,
           (result & 0b00000100) >> 2,
           (result & 0b00000010) >> 1,
           result & 0b00000001);

    // Bitwise OR
    result = num1 | num2;
    printf("num1 | num2 in binary: %d%d%d%d%d%d%d%d\n", 
           (result & 0b10000000) >> 7,
           (result & 0b01000000) >> 6,
           (result & 0b00100000) >> 5,
           (result & 0b00010000) >> 4,
           (result & 0b00001000) >> 3,
           (result & 0b00000100) >> 2,
           (result & 0b00000010) >> 1,
           result & 0b00000001);

    // Bitwise XOR
    result = num1 ^ num2;
    printf("num1 ^ num2 in binary: %d%d%d%d%d%d%d%d\n", 
           (result & 0b10000000) >> 7,
           (result & 0b01000000) >> 6,
           (result & 0b00100000) >> 5,
           (result & 0b00010000) >> 4,
           (result & 0b00001000) >> 3,
           (result & 0b00000100) >> 2,
           (result & 0b00000010) >> 1,
           result & 0b00000001);

    // Bitwise NOT
    result = ~num1;
    printf("~num1 in binary: %d%d%d%d%d%d%d%d\n", 
           (result & 0b10000000) >> 7,
           (result & 0b01000000) >> 6,
           (result & 0b00100000) >> 5,
           (result & 0b00010000) >> 4,
           (result & 0b00001000) >> 3,
           (result & 0b00000100) >> 2,
           (result & 0b00000010) >> 1,
           result & 0b00000001);

    // Bitwise LEFT SHIFT
    result = num1 << 3;
    printf("num1 << 3 in binary: %d%d%d%d%d%d%d%d\n", 
           (result & 0b10000000) >> 7,
           (result & 0b01000000) >> 6,
           (result & 0b00100000) >> 5,
           (result & 0b00010000) >> 4,
           (result & 0b00001000) >> 3,
           (result & 0b00000100) >> 2,
           (result & 0b00000010) >> 1,
           result & 0b00000001);

    // Bitwise RIGHT SHIFT
    result = num2 >> 2;
    printf("num2 >> 2 in binary: %d%d%d%d%d%d%d%d\n", 
           (result & 0b10000000) >> 7,
           (result & 0b01000000) >> 6,
           (result & 0b00100000) >> 5,
           (result & 0b00010000) >> 4,
           (result & 0b00001000) >> 3,
           (result & 0b00000100) >> 2,
           (result & 0b00000010) >> 1,
           result & 0b00000001);

    // Bitwise AND Assignment
    num1 &= 0b11000000;
    printf("num1 &= 0b11000000 in binary: %d%d%d%d%d%d%d%d\n", 
           (num1 & 0b10000000) >> 7,
           (num1 & 0b01000000) >> 6,
           (num1 & 0b00100000) >> 5,
           (num1 & 0b00010000) >> 4,
           (num1 & 0b00001000) >> 3,
           (num1 & 0b00000100) >> 2,
           (num1 & 0b00000010) >> 1,
           num1 & 0b00000001);

    // Bitwise OR Assignment
    num2 |= 0b00000011;
    printf("num2 |= 0b00000011 in binary: %d%d%d%d%d%d%d%d\n", 
           (num2 & 0b10000000) >> 7,
           (num2 & 0b01000000) >> 6,
           (num2 & 0b00100000) >> 5,
           (num2 & 0b00010000) >> 4,
           (num2 & 0b00001000) >> 3,
           (num2 & 0b00000100) >> 2,
           (num2 & 0b00000010) >> 1,
           num2 & 0b00000001);

    // Bitwise XOR Assignment
    num1 ^= 0b00110011;
    printf("num1 ^= 0b00110011 in binary: %d%d%d%d%d%d%d%d\n", 
           (num1 & 0b10000000) >> 7,
           (num1 & 0b01000000) >> 6,
           (num1 & 0b00100000) >> 5,
           (num1 & 0b00010000) >> 4,
           (num1 & 0b00001000) >> 3,
           (num1 & 0b00000100) >> 2,
           (num1 & 0b00000010) >> 1,
           num1 & 0b00000001);

    return 0;
}