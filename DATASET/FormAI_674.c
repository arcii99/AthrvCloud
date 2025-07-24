//FormAI DATASET v1.0 Category: Bitwise operations ; Style: irregular
#include <stdio.h>

int main() {

    //declaring variables
    unsigned int b = 25;
    unsigned int c = 10;

    //using bitwise AND operator
    unsigned int and_op = b & c;
    printf("AND Operation: %d\n", and_op);

    //using bitwise OR operator
    unsigned int or_op = b | c;
    printf("OR Operation: %d\n", or_op);

    //using bitwise XOR operator
    unsigned int xor_op = b ^ c;
    printf("XOR Operation: %d\n", xor_op);

    //using bitwise COMPLEMENT operator
    unsigned int comp_op = ~b;
    printf("COMPLEMENT Operation: %d\n", comp_op);

    //using bitwise LEFT SHIFT operator
    unsigned int left_shift_op = b << 2;
    printf("LEFT SHIFT Operation: %d\n", left_shift_op);

    //using bitwise RIGHT SHIFT operator
    unsigned int right_shift_op = b >> 2;
    printf("RIGHT SHIFT Operation: %d\n", right_shift_op);

    //using bitwise AND assignment operator
    unsigned int and_assignment_op = 10;
    and_assignment_op &= b;
    printf("AND Assignment Operation: %d\n", and_assignment_op);

    //using bitwise OR assignment operator
    unsigned int or_assignment_op = 10;
    or_assignment_op |= b;
    printf("OR Assignment Operation: %d\n", or_assignment_op);

    //using bitwise XOR assignment operator
    unsigned int xor_assignment_op = 10;
    xor_assignment_op ^= b;
    printf("XOR Assignment Operation: %d\n", xor_assignment_op);

    //using bitwise LEFT SHIFT assignment operator
    unsigned int left_shift_assignment_op = 10;
    left_shift_assignment_op <<= 2;
    printf("LEFT SHIFT Assignment Operation: %d\n", left_shift_assignment_op);

    //using bitwise RIGHT SHIFT assignment operator
    unsigned int right_shift_assignment_op = 10;
    right_shift_assignment_op >>= 2;
    printf("RIGHT SHIFT Assignment Operation: %d\n", right_shift_assignment_op);

    return 0;
}