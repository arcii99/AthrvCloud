//FormAI DATASET v1.0 Category: Bitwise operations ; Style: decentralized
#include<stdio.h>

int main() {
    unsigned int num1 = 25;  // Binary equivalent 00011001
    unsigned int num2 = 42;  // Binary equivalent 00101010
    
    printf("Bitwise AND operator (%d & %d) = %d\n", num1, num2, num1 & num2);
    printf("Bitwise OR operator (%d | %d) = %d\n", num1, num2, num1 | num2);
    printf("Bitwise XOR operator (%d ^ %d) = %d\n", num1, num2, num1 ^ num2);
    printf("Left shift operator (%d << 2) = %d\n", num1, num1 << 2);
    printf("Right shift operator (%d >> 1) = %d\n", num2, num2 >> 1);
    printf("One's complement operator (~%d) = %d\n", num1, ~num1);

    // Decentralized implementation
    unsigned int andResult = num1 & num2;
    unsigned int orResult = num1 | num2;
    unsigned int xorResult = num1 ^ num2;
    unsigned int leftShiftResult = num1 << 2;
    unsigned int rightShiftResult = num2 >> 1;
    unsigned int complementResult = ~num1;

    // Outputting results in decentralized style
    printf("\nDecentralized implementation:\n");
    printf("Bitwise AND operator (%d & %d) = %d\n", num1, num2, andResult);
    printf("Bitwise OR operator (%d | %d) = %d\n", num1, num2, orResult);
    printf("Bitwise XOR operator (%d ^ %d) = %d\n", num1, num2, xorResult);
    printf("Left shift operator (%d << 2) = %d\n", num1, leftShiftResult);
    printf("Right shift operator (%d >> 1) = %d\n", num2, rightShiftResult);
    printf("One's complement operator (~%d) = %d\n", num1, complementResult);

    return 0;
}