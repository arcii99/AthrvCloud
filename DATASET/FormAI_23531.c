//FormAI DATASET v1.0 Category: Bitwise operations ; Style: interoperable
#include <stdio.h>

// function to print binary representation of a number
void printBinary(unsigned int number) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (number>>i)&1);
    }
}

int main() {
    unsigned int a = 60; // 0011 1100
    unsigned int b = 13; // 0000 1101

    printf("a: %d, b: %d\n", a, b);
    printf("\na | b :");
    printBinary(a | b); // bitwise OR operator

    printf("\na & b :");
    printBinary(a & b); // bitwise AND operator

    printf("\na ^ b :");
    printBinary(a ^ b); // bitwise XOR operator

    printf("\n~a :");
    printBinary(~a); // bitwise NOT operator

    printf("\na << 2 :");
    printBinary(a << 2); // bitwise left shift operator

    printf("\na >> 2 :");
    printBinary(a >> 2); // bitwise right shift operator

    return 0;
}