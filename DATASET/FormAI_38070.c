//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mathematical
#include <stdio.h>

// Function to perform OR operation between two numbers
int bitwiseOr(int x, int y) {
    int result = x | y;
    return result;
}

// Function to perform AND operation between two numbers
int bitwiseAnd(int x, int y) {
    int result = x & y;
    return result;
}

// Function to perform NOT operation on a number
int bitwiseNot(int x) {
    int result = ~x;
    return result;
}

// Function to perform XOR operation between two numbers
int bitwiseXor(int x, int y) {
    int result = x ^ y;
    return result;
}

int main() {
    int a = 10;
    int b = 5;
    
    printf("Bitwise OR of %d and %d is %d\n", a, b, bitwiseOr(a, b));
    printf("Bitwise AND of %d and %d is %d\n", a, b, bitwiseAnd(a, b));
    printf("Bitwise NOT of %d is %d\n", a, bitwiseNot(a));
    printf("Bitwise XOR of %d and %d is %d\n", a, b, bitwiseXor(a, b));
    
    return 0;
}