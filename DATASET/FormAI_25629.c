//FormAI DATASET v1.0 Category: Bitwise operations ; Style: thoughtful
#include <stdio.h>

int main() {
    // declare two integers
    int a = 10, b = 7;
    
    // perform bitwise AND (&) operation
    int and_result = a & b;
    
    // perform bitwise OR (|) operation
    int or_result = a | b;
    
    // perform bitwise XOR (^) operation
    int xor_result = a ^ b;
    
    // perform bitwise NOT (~) operation
    int not_result = ~a;
    
    printf("Bitwise AND result: %d\n", and_result);
    printf("Bitwise OR result: %d\n", or_result);
    printf("Bitwise XOR result: %d\n", xor_result);
    printf("Bitwise NOT result: %d\n", not_result);
    
    // perform left shift (<<) operation
    int left_shift_result = a << 2;
    
    // perform right shift (>>) operation
    int right_shift_result = a >> 2;
    
    printf("Left shift result: %d\n", left_shift_result);
    printf("Right shift result: %d\n", right_shift_result);
    
    // create a mask to clear the last 3 bits of a
    int mask = ~0 << 3;
    
    // clear the last 3 bits of a using the mask and bitwise AND
    int new_a = a & mask;
    
    printf("New a value after clearing last 3 bits: %d\n", new_a);
    
    return 0;
}