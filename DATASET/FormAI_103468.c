//FormAI DATASET v1.0 Category: Bitwise operations ; Style: happy
#include <stdio.h>

int main() {
    printf("Hooray! Let's use bitwise operations to make some magic happen!\n");
    
    int a = 7;          // Binary: 0111
    int b = 9;          // Binary: 1001
    int bitwiseAnd = a & b;     // Binary: 0001
    
    printf("Let's perform a bitwise AND operation on %d and %d\n", a, b);
    printf("The result is %d\n", bitwiseAnd);
    
    int bitwiseOr = a | b;      // Binary: 1111
    
    printf("Let's perform a bitwise OR operation on %d and %d\n", a, b);
    printf("The result is %d\n", bitwiseOr);
    
    int bitwiseXor = a ^ b;     // Binary: 1110
    
    printf("Let's perform a bitwise XOR operation on %d and %d\n", a, b);
    printf("The result is %d\n", bitwiseXor);
    
    int bitwiseNotA = ~a;       // Binary: 1000 0000 0000 0000 0000 0000 0000 0110 (-8 in 32-bit two's complement)
    
    printf("Let's perform a bitwise NOT operation on %d\n", a);
    printf("The result is %d\n", bitwiseNotA);
    
    int bitwiseNotB = ~b;       // Binary: 1000 0000 0000 0000 0000 0000 0000 0110 (-10 in 32-bit two's complement)
    
    printf("Let's perform a bitwise NOT operation on %d\n", b);
    printf("The result is %d\n", bitwiseNotB);
    
    int leftShiftA = a << 2;    // Binary: 11100 (28 in decimal)
    
    printf("Let's perform a left shift operation on %d\n", a);
    printf("The result is %d\n", leftShiftA);
    
    int rightShiftB = b >> 2;   // Binary: 10 (2 in decimal)
    
    printf("Let's perform a right shift operation on %d\n", b);
    printf("The result is %d\n", rightShiftB);
    
    printf("Wow! Bitwise operations are amazing! Let's use them more often.\n");
    
    return 0;
}