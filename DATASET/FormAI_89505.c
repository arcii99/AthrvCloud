//FormAI DATASET v1.0 Category: Bitwise operations ; Style: portable
#include <stdio.h>

int main() {
    int a = 13, b = 25;

    // Bitwise AND operation: &
    printf("a & b = %d\n", a & b); // output: 9

    // Bitwise OR operation: |
    printf("a | b = %d\n", a | b); // output: 29

    // Bitwise XOR operation: ^
    printf("a ^ b = %d\n", a ^ b); // output: 20

    // Bitwise complement operation: ~
    printf("~a = %d\n", ~a); // output: -14

    // Left shift operation: <<
    printf("a << 2 = %d\n", a << 2); // output: 52

    // Right shift operation: >>
    printf("b >> 3 = %d\n", b >> 3); // output: 3

    // Setting a bit using Bitwise OR operator
    int number = 16;
    printf("Before setting the bit: %d\n", number); // output: 16
    number = number | (1 << 2);
    printf("After setting the bit: %d\n", number); // output: 20

    // Clearing a bit using Bitwise AND operator
    int num = 7;
    printf("Before clearing the bit: %d\n", num); // output: 7
    num = num & ~(1 << 1);
    printf("After clearing the bit: %d\n", num); // output: 5

    // Toggling a bit using Bitwise XOR operator
    int value = 11;
    printf("Before toggling the bit: %d\n", value); // output: 11
    value ^= (1 << 3);
    printf("After toggling the bit: %d\n", value); // output: 3

    return 0;
}