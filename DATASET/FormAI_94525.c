//FormAI DATASET v1.0 Category: Bitwise operations ; Style: imaginative
#include <stdio.h>

int main() {
    int a = 5, b = 9, c = 12;
    
    // Bitwise OR operation
    int or_result = a | b;
    
    // Bitwise AND operation
    int and_result = b & c;
    
    // Bitwise XOR operation
    int xor_result = a ^ c;
    
    // Bitwise NOT operation
    int not_result = ~b;
    
    printf("Bitwise OR of %d and %d is %d\n", a, b, or_result);
    printf("Bitwise AND of %d and %d is %d\n", b, c, and_result);
    printf("Bitwise XOR of %d and %d is %d\n", a, c, xor_result);
    printf("Bitwise NOT of %d is %d\n", b, not_result);
    
    // Bitwise left shift operation
    int left_shift_result = a << 2;
    
    // Bitwise right shift operation
    int right_shift_result = c >> 2;
    
    printf("Bitwise left shift of %d by 2 is %d\n", a, left_shift_result);
    printf("Bitwise right shift of %d by 2 is %d\n", c, right_shift_result);
    
    // Bitwise assignment operators
    a |= c;
    b &= c;
    c ^= a;
    
    printf("Bitwise OR assignment of a=%d and c=%d is %d\n", a-c, c, a);
    printf("Bitwise AND assignment of b=%d and c=%d is %d\n", b+c, c, b);
    printf("Bitwise XOR assignment of c=%d and a=%d is %d\n", c+a, a, c);
    
    return 0;
}