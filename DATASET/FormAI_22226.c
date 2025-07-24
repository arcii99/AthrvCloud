//FormAI DATASET v1.0 Category: Bitwise operations ; Style: relaxed
#include <stdio.h>

int main() {

    int a = 10, b = 15, c;

    // Bitwise AND operator (&)
    c = a & b;
    printf("a & b = %d\n", c);

    // Bitwise OR operator (|)
    c = a | b;
    printf("a | b = %d\n", c);

    // Bitwise XOR operator (^)
    c = a ^ b;
    printf("a ^ b = %d\n", c);

    // Bitwise complement operator (~)
    c = ~a;
    printf("~a = %d\n", c);

    // Left shift operator (<<)
    c = a << 2;
    printf("a << 2 = %d\n", c);

    // Right shift operator (>>)
    c = b >> 2;
    printf("b >> 2 = %d\n", c);

    return 0;
}