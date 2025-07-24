//FormAI DATASET v1.0 Category: Bitwise operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BITS 8

// Function to print a binary string
void printBinary(unsigned int num) {
    for (int i = NUM_BITS - 1; i >= 0; i--) {
        printf("%d", ((num >> i) & 1));
    }
}

int main() {
    srand(time(0));
    unsigned int a = rand() % (1 << NUM_BITS); // Generate a random unsigned int between 0 and (2^NUM_BITS - 1)
    unsigned int b = rand() % (1 << NUM_BITS);

    printf("a = ");
    printBinary(a);
    printf(" = %u\n", a);

    printf("b = ");
    printBinary(b);
    printf(" = %u\n", b);

    printf("a & b = ");
    printBinary(a & b);
    printf(" = %u\n", a & b);

    printf("a | b = ");
    printBinary(a | b);
    printf(" = %u\n", a | b);

    printf("a ^ b = ");
    printBinary(a ^ b);
    printf(" = %u\n", a ^ b);

    printf("~a = ");
    printBinary(~a);
    printf(" = %u\n", ~a);

    printf("a << 2 = ");
    printBinary(a << 2);
    printf(" = %u\n", a << 2);

    printf("b >> 3 = ");
    printBinary(b >> 3);
    printf(" = %u\n", b >> 3);

    return 0;
}