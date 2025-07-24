//FormAI DATASET v1.0 Category: Bitwise operations ; Style: bold
#include <stdio.h>

int main() {
    unsigned int x = 15;  // binary equivalent 0000 1111
    unsigned int y = 6;   // binary equivalent 0000 0110
    
    // bitwise OR operation (|)
    unsigned int or_result = x | y;   // binary equivalent 0000 1111 | 0000 0110 = 0000 1111 (decimal 15)
    printf("Bitwise OR operation: %d | %d = %d\n", x, y, or_result);
    
    // bitwise AND operation (&)
    unsigned int and_result = x & y;  // binary equivalent 0000 1111 & 0000 0110 = 0000 0110 (decimal 6)
    printf("Bitwise AND operation: %d & %d = %d\n", x, y, and_result);
    
    // bitwise XOR operation (^)
    unsigned int xor_result = x ^ y;  // binary equivalent 0000 1111 ^ 0000 0110 = 0000 1001 (decimal 9)
    printf("Bitwise XOR operation: %d ^ %d = %d\n", x, y, xor_result);
    
    // bitwise NOT operation (~)
    unsigned int not_result = ~x;    // binary equivalent ~0000 1111 = 1111 0000 (decimal -16 in 2's complement form)
    printf("Bitwise NOT operation: ~%d = %d\n", x, not_result);
    
    // left shift operation (<<)
    unsigned int left_shift_result = x << 2;   // binary equivalent 0000 1111 << 2 = 0011 1100 (decimal 60)
    printf("Left shift operation: %d << 2 = %d\n", x, left_shift_result);
    
    // right shift operation (>>)
    unsigned int right_shift_result = y >> 1;  // binary equivalent 0000 0110 >> 1 = 0000 0011 (decimal 3)
    printf("Right shift operation: %d >> 1 = %d\n", y, right_shift_result);
    
    return 0;
}