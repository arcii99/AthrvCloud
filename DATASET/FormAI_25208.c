//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mathematical
#include <stdio.h>

// Function to convert decimal to binary
void decimalToBinary(int num)
{
    int binaryNum[32];
    int i = 0;
    while (num > 0) {
        binaryNum[i] = num % 2;
        num = num / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
    printf("\n");
}

// Function to perform bit arithmetic
void bit_arithmetic(int a, int b) 
{
    printf("The bitwise AND of %d and %d is:\n", a, b);
    printf("(%d & %d)\n", a, b);
    printf("Decimal Output: %d\n", a & b);
    printf("Binary Output: "); 
    decimalToBinary(a & b);

    printf("The bitwise OR of %d and %d is:\n", a, b);
    printf("(%d | %d)\n", a, b);
    printf("Decimal Output: %d\n", a | b);
    printf("Binary Output: ");
    decimalToBinary(a | b);

    printf("The bitwise XOR of %d and %d is:\n", a, b);
    printf("(%d ^ %d)\n", a, b);
    printf("Decimal Output: %d\n", a ^ b);
    printf("Binary Output: ");
    decimalToBinary(a ^ b);

    printf("The bitwise NOT of %d is:\n", a);
    printf("(~%d)\n", a);
    printf("Decimal Output: %d\n", ~a);
    printf("Binary Output: ");
    decimalToBinary(~a);

    printf("The left shift of %d by 2 is:\n", a);
    printf("(%d << 2)\n", a);
    printf("Decimal Output: %d\n", a << 2);
    printf("Binary Output: ");
    decimalToBinary(a << 2);

    printf("The right shift of %d by 2 is:\n", a);
    printf("(%d >> 2)\n", a);
    printf("Decimal Output: %d\n", a >> 2);
    printf("Binary Output: ");
    decimalToBinary(a >> 2);
}

int main() 
{
    bit_arithmetic(27, 15);
    return 0;
}