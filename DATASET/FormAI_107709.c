//FormAI DATASET v1.0 Category: Bitwise operations ; Style: excited
#include <stdio.h>

int main() {
    printf("Get ready to experience the power of C Bitwise operations!\n\n");

    unsigned int a = 43;
    unsigned int b = 10;

    printf("We will perform some exciting bitwise operations on a = %u and b = %u\n\n", a, b);

    // Bitwise AND
    unsigned int result = a & b;
    printf("The bitwise AND of a and b is: %u\n", result);

    // Bitwise OR
    result = a | b;
    printf("The bitwise OR of a and b is: %u\n", result);

    // Bitwise XOR
    result = a ^ b;
    printf("The bitwise XOR of a and b is: %u\n", result);

    // Bitwise NOT
    result = ~a;
    printf("The bitwise NOT of a is: %u\n", result);

    // Bitwise LEFT SHIFT
    result = a << 2;
    printf("The bitwise LEFT SHIFT of a is: %u\n", result);

    // Bitwise RIGHT SHIFT
    result = a >> 2;
    printf("The bitwise RIGHT SHIFT of a is: %u\n", result);

    printf("\nThat was awesome! But wait, there's more!\n\n");

    // Bitwise AND Assignment
    a &= b;
    printf("The bitwise AND assignment of a and b is: %u\n", a);

    // Bitwise OR Assignment
    a |= b;
    printf("The bitwise OR assignment of a and b is: %u\n", a);

    // Bitwise XOR Assignment
    a ^= b;
    printf("The bitwise XOR assignment of a and b is: %u\n", a);

    // Bitwise LEFT SHIFT Assignment
    a <<= 2;
    printf("The bitwise LEFT SHIFT assignment of a is: %u\n", a);

    // Bitwise RIGHT SHIFT Assignment
    a >>= 2;
    printf("The bitwise RIGHT SHIFT assignment of a is: %u\n", a);

    printf("\nIs your mind blown yet? That's the power of C Bitwise operations!\n");

    return 0;
}