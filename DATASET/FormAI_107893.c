//FormAI DATASET v1.0 Category: Bitwise operations ; Style: calm
#include <stdio.h>

int main() {

    unsigned int num1, num2;

    printf("Enter two numbers: ");
    scanf("%u %u", &num1, &num2);

    printf("\nBitwise AND of %u and %u: %u", num1, num2, num1 & num2);
    printf("\nBitwise OR of %u and %u: %u", num1, num2, num1 | num2);
    printf("\nBitwise XOR of %u and %u: %u", num1, num2, num1 ^ num2);
    printf("\nOne's complement of %u: %u", num1, ~num1);
    printf("\nLeft shift of %u by 2 bits: %u", num1, num1 << 2);
    printf("\nRight shift of %u by 2 bits: %u", num1, num1 >> 2);

    return 0;
}