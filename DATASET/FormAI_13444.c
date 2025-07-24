//FormAI DATASET v1.0 Category: Bitwise operations ; Style: excited
#include <stdio.h>

int main() {
    // Welcome user
    printf("Welcome to the Bitwise Operation Magic Show!\n");

    // Initialize variables
    int a = 12, b = 25, c, d, e;

    // Binary AND operator
    c = a & b;
    printf("a & b = %d\n", c);

    // Binary OR operator
    c = a | b;
    printf("a | b = %d\n", c);

    // Binary XOR operator
    c = a ^ b;
    printf("a ^ b = %d\n", c);

    // Binary NOT operator
    d = ~a;
    printf("~a = %d\n", d);

    // Left Shift operator
    e = a << 2;
    printf("a << 2 = %d\n", e);

    // Right Shift operator
    e = a >> 2;
    printf("a >> 2 = %d\n", e);

    // Let's do some magic!
    printf("\n\nAbracadabra! Watch this:\n\n");

    // Magical bitwise operation
    e = (a ^ b) + ~(~a | ~b);
    printf("(a ^ b) + ~(~a | ~b) = %d\n", e);

    // Thank you message
    printf("\nThanks for watching the Bitwise Operation Magic Show!\n");

    return 0;
}