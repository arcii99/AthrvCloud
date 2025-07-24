//FormAI DATASET v1.0 Category: Bitwise operations ; Style: relaxed
#include <stdio.h>

// testing bitwise operators in C

int main() {
    unsigned int a = 60;     // 0011 1100 in binary
    unsigned int b = 13;     // 0000 1101 in binary
    int c = -15;             // 1111 0001 in binary (2's complement representation)
    
    // testing bitwise AND operator
    unsigned int result = a & b; 
    printf("a & b = %u\n", result); // expected output: 12
    
    // testing bitwise OR operator
    result = a | b;
    printf("a | b = %u\n", result); // expected output: 61
    
    // testing bitwise XOR operator
    result = a ^ b;
    printf("a ^ b = %u\n", result); // expected output: 49
    
    // testing bitwise complement operator (~)
    result = ~a;
    printf("~a = %u\n", result); // expected output: 4294967235
    
    // testing left shift operator (<<)
    result = a << 2;
    printf("a << 2 = %u\n", result); // expected output: 240
    
    // testing right shift operator (>>)
    result = a >> 2;
    printf("a >> 2 = %u\n", result); // expected output: 15
    
    // testing one's complement operator for negative numbers (~)
    result = ~c;
    printf("~c = %u\n", result); // expected output: 14
    
    // testing sign extended right shift operator (>>)
    result = c >> 1;
    printf("c >> 1 = %d\n", result); // expected output: -8
    
    return 0;
}