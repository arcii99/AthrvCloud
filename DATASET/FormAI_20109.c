//FormAI DATASET v1.0 Category: Bitwise operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int left_shift(int num, int shift) {
    return num << shift;
}

int right_shift(int num, int shift) {
    return num >> shift;
}

int and_op(int num1, int num2) {
    return num1 & num2;
}

int xor_op(int num1, int num2) {
    return num1 ^ num2;
}

int or_op(int num1, int num2) {
    return num1 | num2;
}

int main() {
    int num1, num2, shift;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Bitwise AND operation
    printf("AND operation: %d & %d = %d\n", num1, num2, and_op(num1, num2));

    // Bitwise XOR operation
    printf("XOR operation: %d ^ %d = %d\n", num1, num2, xor_op(num1, num2));

    // Bitwise OR operation
    printf("OR operation: %d | %d = %d\n", num1, num2, or_op(num1, num2));

    // Bitwise left shift operation
    printf("Enter the number of shifts for left shift operation: ");
    scanf("%d", &shift);
    printf("Left Shift operation: %d << %d = %d\n", num1, shift, left_shift(num1, shift));

    // Bitwise right shift operation
    printf("Enter the number of shifts for right shift operation: ");
    scanf("%d", &shift);
    printf("Right Shift operation: %d >> %d = %d\n", num1, shift, right_shift(num1, shift));

    return 0;
}