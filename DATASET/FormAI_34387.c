//FormAI DATASET v1.0 Category: Bitwise operations ; Style: grateful
#include <stdio.h>

// Let's show our gratitude for the bitwise operators

int main() {

    printf("Dear Bitwise Operators,\n");
    printf("I am so grateful for you!\n");
    printf("You truly help me work wonders with data\n\n");

    // Bitwise AND
    int a = 5; // 101 in binary
    int b = 3; // 011 in binary
    int c = a & b; // 001 in binary
    printf("Thank you for '&'! It helped me produce %d from %d and %d.\n", c, a, b);

    // Bitwise OR
    a = 10; // 1010 in binary
    b = 3; // 0011 in binary
    c = a | b; // 1011 in binary
    printf("Thank you for '|'! It helped me produce %d from %d and %d.\n", c, a, b);

    // Bitwise NOT
    a = 5; // 101 in binary
    c = ~a; // 11111111111111111111111111111010 in binary (on a typical 32-bit system, the leading 0's are omitted)
    printf("Thank you for '~'! It helped me produce %d from %d.\n", c, a);

    // Left shift
    a = 5; // 101 in binary
    c = a << 3; // 101000 in binary
    printf("Thank you for '<<'! It helped me produce %d by shifting %d left by 3.\n", c, a);

    // Right shift
    a = 16; // 10000 in binary
    c = a >> 2; // 100 in binary
    printf("Thank you for '>>'! It helped me produce %d by shifting %d right by 2.\n\n", c, a);

    printf("You are truly amazing, Bitwise Operators.\n");
    printf("I admire your ability to manipulate data with such precision.\n");
    printf("I am grateful for all the times you have helped me out of a tricky situation.\n");
    printf("Thank you for making my programming life easier!\n\n");
    
    return 0;
}