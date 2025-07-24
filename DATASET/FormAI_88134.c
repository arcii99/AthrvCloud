//FormAI DATASET v1.0 Category: Bitwise operations ; Style: innovative
#include <stdio.h>

// Function to print binary of a number
void printBinary(unsigned int num) {
    if (num > 1) printBinary(num >> 1);
    printf("%d", num & 1);
}

int main() {
    unsigned int a, b;

    printf("Enter two unsigned integers: ");
    scanf("%u %u", &a, &b);

    printf("\nBinary representation of a: ");
    printBinary(a);
    printf("\nBinary representation of b: ");
    printBinary(b);

    // Bitwise OR operator
    printf("\na | b = %u\nBinary representation of a | b: ", a | b);
    printBinary(a | b);

    // Bitwise AND operator
    printf("\na & b = %u\nBinary representation of a & b: ", a & b);
    printBinary(a & b);

    // Bitwise XOR operator
    printf("\na ^ b = %u\nBinary representation of a ^ b: ", a ^ b);
    printBinary(a ^ b);

    // Bitwise NOT operator
    printf("\n~a = %u\nBinary representation of ~a: ", ~a);
    printBinary(~a);

    // Bitwise Left Shift operator
    printf("\na << 1 = %u\nBinary representation of a << 1: ", a << 1);
    printBinary(a << 1);

    // Bitwise Right Shift operator
    printf("\na >> 1 = %u\nBinary representation of a >> 1: ", a >> 1);
    printBinary(a >> 1);

    return 0;
}