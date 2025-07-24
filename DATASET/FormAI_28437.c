//FormAI DATASET v1.0 Category: Bitwise operations ; Style: ephemeral
#include <stdio.h>

int main() {
    int num1 = 10, num2 = 15;

    // Performing Bitwise AND operation
    int result = num1 & num2;

    printf("The Bitwise AND value of %d and %d is %d\n\n", num1, num2, result);

    // Performing Bitwise OR operation
    result = num1 | num2;

    printf("The Bitwise OR value of %d and %d is %d\n\n", num1, num2, result);

    // Performing Bitwise XOR operation
    result = num1 ^ num2;

    printf("The Bitwise XOR value of %d and %d is %d\n\n", num1, num2, result);

    // Performing Bitwise NOT operation
    result = ~num1;

    printf("The Bitwise NOT value of %d is %d\n\n", num1, result);

    // Performing Bitwise LEFT SHIFT operation
    result = num1 << 2;

    printf("The Bitwise LEFT SHIFT value of %d is %d\n\n", num1, result);

    // Performing Bitwise RIGHT SHIFT operation
    result = num2 >> 2;

    printf("The Bitwise RIGHT SHIFT value of %d is %d\n\n", num2, result);

    return 0;
}