//FormAI DATASET v1.0 Category: Bitwise operations ; Style: lively
#include <stdio.h>

// Function to print binary representation of a number
void printBinary(int num)
{
    int arr[16], i = 0;

    while (num > 0) {
        arr[i++] = num % 2;
        num /= 2;
    }

    for (int j = i - 1; j >= 0; j--)
        printf("%d", arr[j]);
}

int main()
{
    int a = 10, b = 5;

    // Binary representation of a
    printf("Binary representation of %d: ", a);
    printBinary(a);
    printf("\n");

    // Binary representation of b
    printf("Binary representation of %d: ", b);
    printBinary(b);
    printf("\n\n");

    // Bitwise AND operation
    printf("Bitwise AND of a & b: %d\n", a & b);
    printf("Binary representation of %d & %d: ", a, b);
    printBinary(a & b);
    printf("\n\n");

    // Bitwise OR operation
    printf("Bitwise OR of a | b: %d\n", a | b);
    printf("Binary representation of %d | %d: ", a, b);
    printBinary(a | b);
    printf("\n\n");

    // Bitwise XOR operation
    printf("Bitwise XOR of a ^ b: %d\n", a ^ b);
    printf("Binary representation of %d ^ %d: ", a, b);
    printBinary(a ^ b);
    printf("\n\n");

    // Left shift operation
    printf("Left shift of a by 1: %d\n", a<<1);
    printf("Binary representation of %d << 1: ", a);
    printBinary(a<<1);
    printf("\n\n");

    // Right shift operation
    printf("Right shift of a by 1: %d\n", a>>1);
    printf("Binary representation of %d >> 1: ", a);
    printBinary(a>>1);
    printf("\n\n");

    return 0;
}