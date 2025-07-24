//FormAI DATASET v1.0 Category: Bitwise operations ; Style: energetic
#include <stdio.h>

int main() {
    printf("Welcome to my unique bitwise operations program!\n");
    
    // Let's declare some variables to work with
    unsigned int x = 7; // 111 in binary
    unsigned int y = 3; // 011 in binary
    
    // Let's do some bitwise AND operation
    printf("\nBitwise AND Operation:\n");
    printf("%d & %d = %d\n", x, y, (x & y)); // output: 3
    
    // Let's do some bitwise OR operation
    printf("\nBitwise OR Operation:\n");
    printf("%d | %d = %d\n", x, y, (x | y)); // output: 7
    
    // Let's do some bitwise XOR operation
    printf("\nBitwise XOR Operation:\n");
    printf("%d ^ %d = %d\n", x, y, (x ^ y)); // output: 4
    
    // Let's do some bitwise complement operation
    printf("\nBitwise Complement Operation:\n");
    printf("~%d = %d\n", x, (~x)); // output: -8 (due to two's complement)
    
    // Let's do some bitwise left shift operation
    printf("\nBitwise Left Shift Operation:\n");
    printf("%d << %d = %d\n", x, 2, (x << 2)); // output: 28 (11100 in binary)
    
    // Let's do some bitwise right shift operation
    printf("\nBitwise Right Shift Operation:\n");
    printf("%d >> %d = %d\n", x, 2, (x >> 2)); // output: 1 (001 in binary)

    return 0;
}