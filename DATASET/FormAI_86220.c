//FormAI DATASET v1.0 Category: Bitwise operations ; Style: intelligent
#include <stdio.h>

int main() {
    int a = 27;
    int b = 15;

    // perform bitwise AND
    int and_result = a & b;
    printf("a & b = %d\n", and_result);

    // perform bitwise OR
    int or_result = a | b;
    printf("a | b = %d\n", or_result);

    // perform bitwise XOR
    int xor_result = a ^ b;
    printf("a ^ b = %d\n", xor_result);

    // perform bitwise NOT
    int not_result_a = ~a;
    int not_result_b = ~b;
    printf("~a = %d\n", not_result_a);
    printf("~b = %d\n", not_result_b);

    // perform left shift
    int shift_left_result = a << 2;
    printf("a << 2 = %d\n", shift_left_result);

    // perform right shift
    int shift_right_result = a >> 2;
    printf("a >> 2 = %d\n", shift_right_result);

    return 0;
}