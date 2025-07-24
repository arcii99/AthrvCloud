//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Ken Thompson
#include <stdio.h>

int main() {
    int a = 10;
    int b = 5;

    printf("a = %d, b = %d\n\n", a, b);

    // Performing bitwise AND operation
    int bitwise_and_result = a & b;
    printf("Bitwise AND result: %d\n", bitwise_and_result);

    // Performing bitwise OR operation
    int bitwise_or_result = a | b;
    printf("Bitwise OR result: %d\n", bitwise_or_result);

    // Performing bitwise XOR operation
    int bitwise_xor_result = a ^ b;
    printf("Bitwise XOR result: %d\n", bitwise_xor_result);

    // Performing left shift operation
    int left_shift_result = a << 1;
    printf("Left Shift result: %d\n", left_shift_result);

    // Performing right shift operation
    int right_shift_result = a >> 1;
    printf("Right Shift result: %d\n", right_shift_result);

    // Performing bitwise NOT operation
    int bitwise_not_result = ~a;
    printf("Bitwise NOT result: %d\n\n", bitwise_not_result);

    printf("Let's perform some swaps using bitwise operations!\n\n");

    int x = 10;
    int y = 5;

    printf("x = %d, y = %d\n\n", x, y);

    // Swapping two numbers using XOR operator
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;

    printf("After swap using XOR operator: x = %d, y = %d\n\n", x, y);

    int p = 10;
    int q = 5;

    printf("p = %d, q = %d\n\n", p, q);

    // Swapping two numbers using bitwise addition
    p = p + q;
    q = p - q;
    p = p - q;

    printf("After swap using bitwise addition: p = %d, q = %d\n", p, q);
    
    return 0;
}