//FormAI DATASET v1.0 Category: Bitwise operations ; Style: expert-level
#include <stdio.h>

// Function to print binary representation of a number
void printBinary(int num) {
    int i;
    for (i = 31; i >= 0; i--)
        printf("%d", (num >> i) & 1);
}

int main() {
    int a = 10;
    int b = 20;

    printf("a = ");
    printBinary(a);
    printf("\n");

    printf("b = ");
    printBinary(b);
    printf("\n");

    // Bitwise AND operator
    int c = a & b;
    printf("a & b = ");
    printBinary(c);
    printf("\n");

    // Bitwise OR operator
    int d = a | b;
    printf("a | b = ");
    printBinary(d);
    printf("\n");

    // Bitwise XOR operator
    int e = a ^ b;
    printf("a ^ b = ");
    printBinary(e);
    printf("\n");

    // Bitwise NOT operator
    int f = ~a;
    printf("~a = ");
    printBinary(f);
    printf("\n");

    // Left shift operator
    int g = a << 2;
    printf("a << 2 = ");
    printBinary(g);
    printf("\n");

    // Right shift operator
    int h = b >> 2;
    printf("b >> 2 = ");
    printBinary(h);
    printf("\n");

    return 0;
}