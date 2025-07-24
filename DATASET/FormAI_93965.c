//FormAI DATASET v1.0 Category: Arithmetic ; Style: interoperable
#include <stdio.h>

int main() {
    int a = 10, b = 20, c = 30;
    printf("Welcome to Arithmetic Operations program!\n");

    // Addition
    int sum = a + b;
    printf("Addition of %d and %d is: %d\n", a, b, sum);
 
    // Subtraction
    int diff = c - b;
    printf("Subtraction of %d and %d is: %d\n", c, b, diff);
 
    // Multiplication
    int mult = a * b;
    printf("Multiplication of %d and %d is: %d\n", a, b, mult);
 
    // Division
    float div = (float)a / b;
    printf("Division of %d and %d is: %f\n", a, b, div);
    
    // Modulo
    int mod = c % a;
    printf("Modulo of %d and %d is: %d\n", c, a, mod);
    
    // Bitwise Operations
    int x = 5, y = 7;
    int bitwise_and = x & y;
    printf("Bitwise AND of %d and %d is: %d\n", x, y, bitwise_and);
    int bitwise_or = x | y;
    printf("Bitwise OR of %d and %d is: %d\n", x, y, bitwise_or);
    int bitwise_xor = x ^ y;
    printf("Bitwise XOR of %d and %d is: %d\n", x, y, bitwise_xor);
    int bitwise_compl = ~x;
    printf("Bitwise complement of %d is: %d\n", x, bitwise_compl);
    int bitwise_shift_left = x << 2;
    printf("Bitwise shift left of %d is: %d\n", x, bitwise_shift_left);
    int bitwise_shift_right = x >> 2;
    printf("Bitwise shift right of %d is: %d\n", x, bitwise_shift_right);

    return 0;
}