//FormAI DATASET v1.0 Category: Bitwise operations ; Style: synchronous
#include <stdio.h>

/* This program demonstrates the use of bitwise operations */

int main() {

    int a = 5;      // 00000101
    int b = 9;      // 00001001
    int result;

    // Bitwise AND operation
    result = a & b;
    printf("The result of AND operation: %d\n", result);   // 00000001
    
    // Bitwise OR operation
    result = a | b;
    printf("The result of OR operation: %d\n", result);    // 00001101
    
    // Bitwise XOR operation
    result = a ^ b;
    printf("The result of XOR operation: %d\n", result);   // 00001100
    
    // Bitwise NOT operation
    result = ~a;
    printf("The result of NOT operation on a: %d\n", result); // 11111010

    // Bitwise left shift operation
    result = a << 2;
    printf("The result of left shift operation on a: %d\n", result);  // 00010100

    // Bitwise right shift operation
    result = b >> 2;
    printf("The result of right shift operation on b: %d\n", result); // 00000010

    return 0;
}