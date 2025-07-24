//FormAI DATASET v1.0 Category: Bitwise operations ; Style: recursive
#include <stdio.h>

void binary_recursive(int x) {
    if (x > 1) {
        binary_recursive(x/2);
    }
    printf("%d", x % 2);
}

int main() {
    int a = 10, b = 5, c = 0;

    // Bitwise AND operator
    c = a & b;
    printf("a & b = %d\n", c);

    // Bitwise OR operator
    c = a | b;
    printf("a | b = %d\n", c);

    // Bitwise XOR operator
    c = a ^ b;
    printf("a ^ b = %d\n", c);

    // Bitwise NOT operator
    c = ~a;
    printf("~a = %d\n", c);

    // Bitwise left shift operator
    c = a << 1;
    printf("a << 1 = %d\n", c);

    // Bitwise right shift operator
    c = a >> 1;
    printf("a >> 1 = %d\n", c);

    // Recursive binary representation of a
    printf("Binary representation of %d: ", a);
    binary_recursive(a);
    printf("\n");

    return 0;
}