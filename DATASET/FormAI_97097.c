//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Dennis Ritchie
#include <stdio.h>

/* This program demonstrates various bitwise operations. */

int main() {
    /* Declare two variables to demonstrate bitwise operations. */
    unsigned int num1 = 23;
    unsigned int num2 = 56;

    /* Demonstrate bitwise AND operation. */
    printf("Bitwise AND of %u and %u is %u.\n", num1, num2, num1 & num2);

    /* Demonstrate bitwise OR operation. */
    printf("Bitwise OR of %u and %u is %u.\n", num1, num2, num1 | num2);

    /* Demonstrate bitwise XOR operation. */
    printf("Bitwise XOR of %u and %u is %u.\n", num1, num2, num1 ^ num2);

    /* Demonstrate bitwise NOT operation. */
    printf("Bitwise NOT of %u is %u.\n", num1, ~num1);

    /* Demonstrate left shift operation. */
    printf("Left shift of %u by 2 is %u.\n", num1, num1 << 2);

    /* Demonstrate right shift operation. */
    printf("Right shift of %u by 3 is %u.\n", num2, num2 >> 3);

    /* Demonstrate bitwise AND assignment. */
    num1 &= num2;
    printf("After bitwise AND assignment, num1 is %u.\n", num1);

    /* Demonstrate bitwise OR assignment. */
    num2 |= num1;
    printf("After bitwise OR assignment, num2 is %u.\n", num2);

    /* Demonstrate bitwise XOR assignment. */
    num1 ^= num2;
    printf("After bitwise XOR assignment, num1 is %u.\n", num1);

    return 0;
}