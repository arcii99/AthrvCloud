//FormAI DATASET v1.0 Category: Bitwise operations ; Style: accurate
#include <stdio.h>

int main() {

    unsigned char a = 0b00101110; // 46 in decimal
    unsigned char b = 0b00011011; // 27 in decimal

    printf("a = %d, b = %d\n", a, b);
    printf("\n");

    // AND bitwise '&'
    unsigned char and_result = a & b;
    printf("AND Result : 0x%x\n", and_result);

    // OR bitwise '|'
    unsigned char or_result = a | b;
    printf("OR Result : 0x%x\n", or_result);

    // XOR bitwise '^'
    unsigned char xor_result = a ^ b;
    printf("XOR Result : 0x%x\n", xor_result);

    // Complement bitwise '~'
    unsigned char complement_result = ~a;
    printf("Complement Result of a : 0x%x\n", complement_result);

    printf("\n");
    printf("a = 0b00101110\n");

    // Shift left bitwise '<<'
    unsigned char shift_left = a << 2; // shift left by 2 bits
    printf("a after shift left by 2: 0x%x\n", shift_left);

    // Shift right bitwise '>>'
    unsigned char shift_right = a >> 2; // shift right by 2 bits
    printf("a after shift right by 2: 0x%x\n", shift_right);

    return 0;
}