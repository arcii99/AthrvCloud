//FormAI DATASET v1.0 Category: Bitwise operations ; Style: dynamic
#include <stdio.h>

int main() {
    int num1, num2;

    printf("Enter two numbers (separated by a space): ");
    scanf("%d %d", &num1, &num2);

    // bitwise AND operation
    int and_result = num1 & num2;
    printf("Bitwise AND Result: %d\n", and_result);

    // bitwise OR operation
    int or_result = num1 | num2;
    printf("Bitwise OR Result: %d\n", or_result);

    // bitwise XOR operation
    int xor_result = num1 ^ num2;
    printf("Bitwise XOR Result: %d\n", xor_result);

    // bitwise NOT operation
    int not_result = ~num1;
    printf("Bitwise NOT Result: %d\n", not_result);

    // bitwise left shift operation
    int left_shift_result = num1 << 1;
    printf("Bitwise Left Shift Result: %d\n", left_shift_result);

    // bitwise right shift operation
    int right_shift_result = num1 >> 1;
    printf("Bitwise Right Shift Result: %d\n", right_shift_result);

    return 0;
}