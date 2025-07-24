//FormAI DATASET v1.0 Category: Bitwise operations ; Style: synchronous
#include <stdio.h>

int main() {
    // Bitwise AND - sets a 1 in each bit position where both operands have a 1
    unsigned int a = 21;    // 21 = 00010101 in binary
    unsigned int b = 11;    // 11 = 00001011 in binary
    unsigned int c = a & b; // c = 00000001
    printf("Bitwise AND: %d & %d = %d\n", a, b, c);
    
    // Bitwise OR - sets a 1 in each bit position where at least one operand has a 1
    a = 21;                 // 21 = 00010101 in binary
    b = 11;                 // 11 = 00001011 in binary
    c = a | b;              // c = 00011111
    printf("Bitwise OR: %d | %d = %d\n", a, b, c);
    
    // Bitwise XOR - sets a 1 in each bit position where exactly one operand has a 1
    a = 21;                 // 21 = 00010101 in binary
    b = 11;                 // 11 = 00001011 in binary
    c = a ^ b;              // c = 00011110
    printf("Bitwise XOR: %d ^ %d = %d\n", a, b, c);
    
    // Bitwise NOT - inverts all the bits (1s become 0s and 0s become 1s)
    a = 21;                 // 21 = 00010101 in binary
    c = ~a;                 // c = 11101010
    printf("Bitwise NOT: ~%d = %d\n", a, c);
    
    // Bitwise LEFT SHIFT - shifts all the bits to the left by a specified amount of positions
    a = 21;                 // 21 = 00010101 in binary
    c = a << 2;             // c = 01010100
    printf("Bitwise LEFT SHIFT: %d << 2 = %d\n", a, c);
    
    // Bitwise RIGHT SHIFT - shifts all the bits to the right by a specified amount of positions
    a = 21;                 // 21 = 00010101 in binary
    c = a >> 2;             // c = 00000101
    printf("Bitwise RIGHT SHIFT: %d >> 2 = %d\n", a, c);
    
    return 0;
}