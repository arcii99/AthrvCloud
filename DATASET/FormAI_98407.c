//FormAI DATASET v1.0 Category: Bitwise operations ; Style: minimalist
#include <stdio.h>

// Function to perform bitwise operations
void performBitwiseOperations(int num1, int num2) {
    int bitwiseAnd = num1 & num2;
    int bitwiseOr = num1 | num2;
    int bitwiseXor = num1 ^ num2;
    int leftShift = num1 << 2;
    int rightShift = num2 >> 2;
    int bitwiseNot1 = ~num1;
    int bitwiseNot2 = ~num2;

    printf("Bitwise AND operation: %d & %d = %d\n", num1, num2, bitwiseAnd);
    printf("Bitwise OR operation: %d | %d = %d\n", num1, num2, bitwiseOr);
    printf("Bitwise XOR operation: %d ^ %d = %d\n", num1, num2, bitwiseXor);
    printf("Left shift operation: %d << 2 = %d\n", num1, leftShift);
    printf("Right shift operation: %d >> 2 = %d\n", num2, rightShift);
    printf("Bitwise NOT operation of %d = %d\n", num1, bitwiseNot1);
    printf("Bitwise NOT operation of %d = %d\n", num2, bitwiseNot2);
}

int main() {
    int num1 = 12;
    int num2 = 6;

    printf("Performing bitwise operations on %d and %d:\n", num1, num2);
    performBitwiseOperations(num1, num2);

    return 0;
}