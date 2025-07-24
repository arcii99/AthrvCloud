//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Ada Lovelace
#include<stdio.h>

int main() {
    unsigned int a = 10; // 0000 1010
    unsigned int b = 5; // 0000 0101
    unsigned int c;

    // Bitwise AND operator - & 
    c = a & b; // 0000 0000
    printf("a & b = %u\n", c);

    // Bitwise OR operator - | 
    c = a | b; // 0000 1111
    printf("a | b = %u\n", c);

    // Bitwise XOR operator - ^ 
    c = a ^ b; // 0000 1111
    printf("a ^ b = %u\n", c);

    // Bitwise complement operator - ~ 
    c = ~a; // 1111 0101
    printf("~a = %u\n", c);

    // Bitwise left shift operator - << 
    c = a << 2; // 0010 1000
    printf("a << 2 = %u\n", c);

    // Bitwise right shift operator - >> 
    c = a >> 2; // 0000 0010
    printf("a >> 2 = %u\n", c);

    return 0;
}