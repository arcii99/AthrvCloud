//FormAI DATASET v1.0 Category: Bitwise operations ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// Function to print a binary number
void printBinary(int n) {
    if (n > 1) {
        printBinary(n / 2);
    }

    printf("%d", n % 2);
}

int main() {
    int a = 7;
    int b = 5;

    printf("a = %d     binary: ", a);
    printBinary(a);
    printf("\n");

    printf("b = %d     binary: ", b);
    printBinary(b);
    printf("\n");

    printf("\nBitwise AND operator (&):\n");
    printf("a & b = %d     binary: ", a & b);
    printBinary(a & b);
    printf("\n");

    printf("\nBitwise OR operator (|):\n");
    printf("a | b = %d     binary: ", a | b);
    printBinary(a | b);
    printf("\n");

    printf("\nBitwise XOR operator (^):\n");
    printf("a ^ b = %d     binary: ", a ^ b);
    printBinary(a ^ b);
    printf("\n");

    printf("\nBitwise left shift operator (<<):\n");
    printf("a << 1 = %d     binary: ", a << 1);
    printBinary(a << 1);
    printf("\n");

    printf("\nBitwise right shift operator (>>):\n");
    printf("a >> 1 = %d     binary: ", a >> 1);
    printBinary(a >> 1);
    printf("\n");

    printf("\nBitwise complement operator (~):\n");
    printf("~a = %d     binary: ", ~a);
    printBinary(~a);
    printf("\n");

    return 0;
}