//FormAI DATASET v1.0 Category: Bitwise operations ; Style: complete
#include <stdio.h>

int main() {
    int a = 23, b = 13, result;

    // Bitwise AND
    result = a & b;
    printf("Bitwise AND: %d & %d = %d\n", a, b, result);

    // Bitwise OR
    result = a | b;
    printf("Bitwise OR: %d | %d = %d\n", a, b, result);

    // Bitwise XOR
    result = a ^ b;
    printf("Bitwise XOR: %d ^ %d = %d\n", a, b, result);

    // Bitwise NOT
    result = ~a;
    printf("Bitwise NOT: ~%d = %d\n", a, result);

    // Bitwise Left-shift
    result = a << 2;
    printf("Bitwise Left-shift: %d << 2 = %d\n", a, result);

    // Bitwise Right-shift
    result = a >> 2;
    printf("Bitwise Right-shift: %d >> 2 = %d\n", a, result);
    
    // Bit masking on a
    result = a & 0x0F;
    printf("Bit masking on %d: 0x%x & 0x0F = 0x%x\n", a, a, result);
    
    // Setting a bit
    a |= 1UL << 5;
    printf("Setting 5th bit of %d: %d\n", a, a);
    
    // Clearing a bit
    a &= ~(1UL << 2);
    printf("Clearing 2nd bit of %d: %d\n", a, a);
    
    // Toggling a bit
    a ^= 1UL << 3;
    printf("Toggling 3rd bit of %d: %d\n", a, a);

    return 0;
}