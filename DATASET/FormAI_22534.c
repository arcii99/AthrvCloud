//FormAI DATASET v1.0 Category: Bitwise operations ; Style: standalone
#include<stdio.h>

int main(){
    int a = 7, b = 3, c = 0;

    // Bitwise AND
    c = a & b;  // 0111 & 0011 = 0011
    printf("a & b = %d\n", c);

    // Bitwise OR
    c = a | b;  // 0111 | 0011 = 0111
    printf("a | b = %d\n", c);

    // Bitwise XOR
    c = a ^ b;  // 0111 ^ 0011 = 0100
    printf("a ^ b = %d\n", c);

    // Bitwise NOT
    c = ~a;     // ~0111 = 1000 (2's complement)
    printf("~a = %d\n", c);

    // Left Shift
    c = a << 1; // 0111 << 1 = 1110
    printf("a << 1 = %d\n", c);

    // Right Shift
    c = a >> 1; // 0111 >> 1 = 0011
    printf("a >> 1 = %d\n", c);

    return 0;
}