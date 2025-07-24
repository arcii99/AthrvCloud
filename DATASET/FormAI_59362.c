//FormAI DATASET v1.0 Category: Bitwise operations ; Style: unmistakable
#include <stdio.h>

/* This program demonstrates the bitwise operations in C language */

int main() {

    /* Declare the variables */
    int num1 = 10;
    int num2 = 20;
    int result;

    /* Display the numbers */
    printf("num1 = %d, num2 = %d\n", num1, num2);

    /* Perform the Bitwise OR operation */
    result = num1 | num2;
    printf("Bitwise OR: num1 | num2 = %d\n", result);

    /* Perform the Bitwise AND operation */
    result = num1 & num2;
    printf("Bitwise AND: num1 & num2 = %d\n", result);

    /* Perform the Bitwise XOR operation */
    result = num1 ^ num2;
    printf("Bitwise XOR: num1 ^ num2 = %d\n", result);

    /* Perform the Bitwise NOT operation */
    result = ~num1;
    printf("Bitwise NOT: ~num1 = %d\n", result);

    /* Perform the left shift operation */
    result = num1 << 2;
    printf("Left shift: num1 << 2 = %d\n", result);

    /* Perform the right shift operation */
    result = num1 >> 2;
    printf("Right shift: num1 >> 2 = %d\n", result);

    /* Combine the Bitwise AND and NOT operations */
    result = num1 & (~num2);
    printf("Bitwise AND and NOT: num1 & (~num2) = %d\n", result);

    /* Combine the Bitwise OR and XOR operations */
    result = (num1 | num2) ^ (num1 & num2);
    printf("Bitwise OR and XOR: (num1 | num2) ^ (num1 & num2) = %d\n", result);

    return 0;
}