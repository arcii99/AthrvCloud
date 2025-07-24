//FormAI DATASET v1.0 Category: Bitwise operations ; Style: modular
// Bitwise operations example program in modular style
#include <stdio.h>

// Function to perform the bitwise AND operation
int bitwiseAnd(int a, int b) {
    return a & b;
}

// Function to perform the bitwise OR operation
int bitwiseOr(int a, int b) {
    return a | b;
}

// Function to perform the bitwise XOR operation
int bitwiseXor(int a, int b) {
    return a ^ b;
}

// Function to perform the bitwise NOT operation
int bitwiseNot(int a) {
    return ~a;
}

// Function to perform the left shift operation
int leftShift(int a, int b) {
    return a << b;
}

// Function to perform the right shift operation
int rightShift(int a, int b) {
    return a >> b;
}

int main() {
    int a = 9;  // binary representation: 0000 1001
    int b = 12; // binary representation: 0000 1100

    printf("Bitwise AND: %d\n", bitwiseAnd(a, b));   // Output: 8
    printf("Bitwise OR: %d\n", bitwiseOr(a, b));     // Output: 13
    printf("Bitwise XOR: %d\n", bitwiseXor(a, b));   // Output: 5
    printf("Bitwise NOT of %d: %d\n", a, bitwiseNot(a)); // Output: -10
    printf("Left shift of %d by %d: %d\n", a, 2, leftShift(a, 2)); // Output: 36
    printf("Right shift of %d by %d: %d\n", a, 2, rightShift(a, 2)); // Output: 2

    return 0;
}