//FormAI DATASET v1.0 Category: Bitwise operations ; Style: light-weight
#include <stdio.h>

int main() {
    // Bitwise OR operation (|)
    unsigned int a = 10; // 1010 in binary
    unsigned int b = 13; // 1101 in binary
    unsigned int result = a | b;
    printf("%u | %u = %u\n", a, b, result); // Output: 10 | 13 = 15
    
    // Bitwise AND operation (&)
    a = 10; // 1010 in binary
    b = 13; // 1101 in binary
    result = a & b;
    printf("%u & %u = %u\n", a, b, result); // Output: 10 & 13 = 8
    
    // Bitwise XOR operation (^)
    a = 10; // 1010 in binary
    b = 13; // 1101 in binary
    result = a ^ b;
    printf("%u ^ %u = %u\n", a, b, result); // Output: 10 ^ 13 = 7
    
    // Bitwise left shift (<<)
    a = 10; // 1010 in binary
    unsigned int shift = 2;
    result = a << shift;
    printf("%u << %u = %u\n", a, shift, result); // Output: 10 << 2 = 40
    
    // Bitwise right shift (>>)
    a = 10; // 1010 in binary
    shift = 2;
    result = a >> shift;
    printf("%u >> %u = %u\n", a, shift, result); // Output: 10 >> 2 = 2
    
    // Bitwise complement (~)
    a = 10; // 1010 in binary
    result = ~a;
    printf("~%u = %u\n", a, result); // Output: ~10 = 4294967285
    
    return 0;
}