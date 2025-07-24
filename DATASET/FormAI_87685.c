//FormAI DATASET v1.0 Category: Bitwise operations ; Style: recursive
#include <stdio.h>

// Recursive function to print binary representation of a decimal
void printBinary(int n)
{
    if (n == 0) {
        printf("0");
        return;
    }
    // Recursive call to print binary representation of quotient
    printBinary(n / 2);
    // Print remainder
    printf("%d", n % 2);
}

int main()
{
    int a = 15, b = 7;
    printf("Bitwise OR of %d and %d = %d\n", a, b, a | b);
    printf("Bitwise AND of %d and %d = %d\n", a, b, a & b);
    printf("Bitwise XOR of %d and %d = %d\n", a, b, a ^ b);
    printf("Bitwise NOT of %d = %d\n", a, ~a);
    printf("Bitwise NOT of %d = %d\n", b, ~b);
    printf("Right shift of %d by 1 = %d\n", a, a >> 1);
    printf("Left shift of %d by 1 = %d\n", b, b << 1);
    printf("Binary representation of %d = ", a);
    printBinary(a);
    printf("\nBinary representation of %d = ", b);
    printBinary(b);
    printf("\n");
    return 0;
}