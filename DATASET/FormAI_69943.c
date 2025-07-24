//FormAI DATASET v1.0 Category: Bitwise operations ; Style: ultraprecise
#include <stdio.h>

int main() {
    int a = 5; // 101 in binary
    int b = 3; // 011 in binary
    
    // Bitwise AND operation
    int c = a & b; // 001 in binary
    printf("a & b = %d\n", c);
    
    // Bitwise OR operation
    int d = a | b; // 111 in binary
    printf("a | b = %d\n", d);
    
    // Bitwise XOR operation
    int e = a ^ b; // 110 in binary
    printf("a ^ b = %d\n", e);
    
    // Bitwise NOT operation
    int f = ~a; // 11111111111111111111111111111010 in binary
    printf("~a = %d\n", f);
    
    // Left shift operation
    int g = a << 1; // 1010 in binary
    printf("a << 1 = %d\n", g);
    
    // Right shift operation
    int h = a >> 1; // 10 in binary
    printf("a >> 1 = %d\n", h);
    
    return 0;
}