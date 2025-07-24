//FormAI DATASET v1.0 Category: Bitwise operations ; Style: intelligent
#include <stdio.h>

// A function to perform bitwise operations
void bitwiseOperations(int a, int b) {
    int c = a & b;  // AND operation
    int d = a | b;  // OR operation
    int e = a ^ b;  // XOR operation
    int f = ~a;     // NOT operation on a
    int g = ~b;     // NOT operation on b

    // Printing the results of bitwise operations
    printf("a = %d, b = %d\n", a, b);
    printf("a & b = %d\n", c);
    printf("a | b = %d\n", d);
    printf("a ^ b = %d\n", e);
    printf("~a = %d\n", f);
    printf("~b = %d\n", g);
}

int main() {
    int a = 5;
    int b = 6;

    // Calling the function that performs bitwise operations
    bitwiseOperations(a, b);

    return 0;
}