//FormAI DATASET v1.0 Category: Bitwise operations ; Style: statistical
#include <stdio.h>

int main() {
    int a = 8;                          // Binary: 1000
    int b = 3;                          // Binary: 0011
    int result;
    
    result = a & b;                     // Bitwise AND operation
    printf("a & b = %d\n", result);     // Result: 0000 (Decimal: 0)
    
    result = a | b;                     // Bitwise OR operation
    printf("a | b = %d\n", result);     // Result: 1011 (Decimal: 11)
    
    result = a ^ b;                     // Bitwise XOR operation
    printf("a ^ b = %d\n", result);     // Result: 1011 (Decimal: 11)
    
    result = ~a;                        // Bitwise NOT operation (Complement)
    printf("~a = %d\n", result);        // Result: 0111 (Decimal: -9)
    
    result = a << 1;                    // Bitwise left shift operation
    printf("a << 1 = %d\n", result);    // Result: 10000 (Decimal: 16)
    
    result = b >> 1;                    // Bitwise right shift operation
    printf("b >> 1 = %d\n", result);    // Result: 0001 (Decimal: 1)
    
    return 0;
}