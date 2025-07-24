//FormAI DATASET v1.0 Category: Bitwise operations ; Style: artistic
#include<stdio.h>

int main() {
    int num1 = 14, num2 = 7;

    // Performing bitwise AND operation
    int and_result = num1 & num2;
    printf("%d & %d = %d\n", num1, num2, and_result);

    // Performing bitwise OR operation
    int or_result = num1 | num2;
    printf("%d | %d = %d\n", num1, num2, or_result);

    // Performing bitwise XOR operation
    int xor_result = num1 ^ num2;
    printf("%d ^ %d = %d\n", num1, num2, xor_result);

    // Performing bitwise NOT operation
    int not_result = ~num1;
    printf("~%d = %d\n", num1, not_result);

    // Performing left shift operation
    int left_shift_result = num1 << 1;
    printf("%d << 1 = %d\n", num1, left_shift_result);

    // Performing right shift operation
    int right_shift_result = num1 >> 1;
    printf("%d >> 1 = %d\n", num1, right_shift_result);

    return 0;
}