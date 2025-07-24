//FormAI DATASET v1.0 Category: Bitwise operations ; Style: protected
#include <stdio.h>

int main() {

    unsigned int a = 0b1011;
    unsigned int b = 0b1100;
    unsigned int mask = 0b0111;

    // AND operation with mask
    unsigned int masked_a = a & mask; // 0b0011
    unsigned int masked_b = b & mask; // 0b0100

    // OR operation with mask
    unsigned int new_a = a | mask; // 0b1111
    unsigned int new_b = b | mask; // 0b1111

    // XOR operation with mask
    unsigned int toggled_a = a ^ mask; // 0b1100
    unsigned int toggled_b = b ^ mask; // 0b1011

    // LEFT SHIFT operation
    unsigned int shift_left_a = a << 2; // 0b1011  -> 0b110100
    unsigned int shift_left_b = b << 3; // 0b1100  -> 0b1100000

    // RIGHT SHIFT operation
    unsigned int shift_right_a = a >> 2; // 0b1011  -> 0b10
    unsigned int shift_right_b = b >> 3; // 0b1100  -> 0b1

    // NEGATION operation
    unsigned int negated_a = ~a; // 0b1011  -> 0b11111111111111111111111111110000
    unsigned int negated_b = ~b; // 0b1100  -> 0b11111111111111111111111111100111

    printf("a & mask = 0b%04x\n", masked_a);
    printf("b & mask = 0b%04x\n", masked_b);
    printf("a | mask = 0b%04x\n", new_a);
    printf("b | mask = 0b%04x\n", new_b);
    printf("a ^ mask = 0b%04x\n", toggled_a);
    printf("b ^ mask = 0b%04x\n", toggled_b);
    printf("a << 2 = 0b%08x\n", shift_left_a);
    printf("b << 3 = 0b%08x\n", shift_left_b);
    printf("a >> 2 = 0b%04x\n", shift_right_a);
    printf("b >> 3 = 0b%04x\n", shift_right_b);
    printf("~a = 0x%08x\n", negated_a);
    printf("~b = 0x%08x\n", negated_b);

    return 0;
}