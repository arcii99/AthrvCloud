//FormAI DATASET v1.0 Category: Bitwise operations ; Style: decentralized
#include <stdio.h>

// Bitwise XOR Operation
int bitwiseXOR(int a, int b) {
    return (a ^ b); 
}

// Bitwise AND Operation
int bitwiseAND(int a, int b) {
    return (a & b); 
}

// Bitwise OR Operation
int bitwiseOR(int a, int b) {
    return (a | b); 
}

// Bitwise Left Shift Operation
int bitwiseLeftShift(int a, int b) {
    return (a << b); 
}

// Bitwise Right Shift Operation
int bitwiseRightShift(int a, int b) {
    return (a >> b); 
}

int main() {

    // Variables for Bitwise Operations
    int a = 12, b = 15;

    // Bitwise XOR Operation
    printf("Bitwise XOR Operation: %d\n", bitwiseXOR(a, b));

    // Bitwise AND Operation
    printf("Bitwise AND Operation: %d\n", bitwiseAND(a, b));

    // Bitwise OR Operation
    printf("Bitwise OR Operation: %d\n", bitwiseOR(a, b));

    // Bitwise Left Shift Operation
    printf("Bitwise Left Shift Operation: %d\n", bitwiseLeftShift(a, 2));

    // Bitwise Right Shift Operation
    printf("Bitwise Right Shift Operation: %d\n", bitwiseRightShift(a, 2));

    return 0;
}