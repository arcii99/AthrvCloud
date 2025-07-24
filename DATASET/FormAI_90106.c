//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Linus Torvalds
#include <stdio.h>

// Define constants
#define TRUE 1
#define FALSE 0

// Function to perform bitwise OR operation
int bitwise_or(int a, int b) {
    int result = a | b;
    return result;
}

// Function to perform bitwise AND operation
int bitwise_and(int a, int b) {
    int result = a & b;
    return result;
}

// Function to perform bitwise XOR operation
int bitwise_xor(int a, int b) {
    int result = a ^ b;
    return result;
}

int main() {
    int a = 5;
    int b = 3;

    // Perform bitwise OR operation
    int or_result = bitwise_or(a, b);
    printf("Bitwise OR result: %d\n", or_result);

    // Perform bitwise AND operation
    int and_result = bitwise_and(a, b);
    printf("Bitwise AND result: %d\n", and_result);

    // Perform bitwise XOR operation
    int xor_result = bitwise_xor(a, b);
    printf("Bitwise XOR result: %d\n", xor_result);

    return 0;
}