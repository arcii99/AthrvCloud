//FormAI DATASET v1.0 Category: Bitwise operations ; Style: introspective
#include <stdio.h>

int main() {
    int a = 13; // 00001101
    int b = 5;  // 00000101

    // Bitwise AND operator
    int c = a & b; // 00000101
    printf("a & b = %d\n", c);
    
    // Bitwise OR operator
    c = a | b; // 00001101
    printf("a | b = %d\n", c);
    
    // Bitwise XOR operator
    c = a ^ b; // 00001000
    printf("a ^ b = %d\n", c);
    
    // Negation operator
    c = ~a; // 11110010
    printf("~a = %d\n", c);
    
    // Shift left operator
    c = a << 2; // 00110100
    printf("a << 2 = %d\n", c);
    
    // Shift right operator
    c = a >> 2; // 00000011
    printf("a >> 2 = %d\n", c);

    return 0;
}