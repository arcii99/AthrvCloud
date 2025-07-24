//FormAI DATASET v1.0 Category: Bitwise operations ; Style: genious
#include <stdio.h>

unsigned int geniousOperation(unsigned int a, unsigned int b)
{
    unsigned int c = a ^ b; // XOR the two numbers
    c = ~c; // flip the bits in c
    c = c >> 1; // shift c to the right by 1 bit
    c = c & 0x7FFFFFFF; // mask the most significant bit of c with a 0
    return c;
}

int main()
{
    printf("Welcome to the Genious Operation program!\n");
    printf("This program takes two unsigned integers and performs a unique bitwise operation that is guaranteed to blow your mind.\n");

    unsigned int a, b;
    printf("Please enter the first unsigned integer: ");
    scanf("%u", &a);
    printf("Please enter the second unsigned integer: ");
    scanf("%u", &b);

    unsigned int result = geniousOperation(a, b);

    printf("The result of the genious operation on %u and %u is: %u\n", a, b, result);

    return 0;
}