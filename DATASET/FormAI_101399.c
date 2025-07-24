//FormAI DATASET v1.0 Category: Bitwise operations ; Style: thoughtful
#include <stdio.h>

int main() {
    int number1 = 10;
    int number2 = 25;
    int result_or, result_and, result_xor, result_not;

    // OR operation
    result_or = number1 | number2;
    printf("Result of OR operation is %d\n", result_or);

    // AND operation
    result_and = number1 & number2;
    printf("Result of AND operation is %d\n", result_and);

    // XOR operation
    result_xor = number1 ^ number2;
    printf("Result of XOR operation is %d\n", result_xor);

    // NOT operation
    result_not = ~number1;
    printf("Result of NOT operation is %d\n", result_not);

    // Left shift operation
    number1 = number1 << 2;
    printf("Number after left shift operation is %d\n", number1);

    // Right shift operation
    number2 = number2 >> 1;
    printf("Number after right shift operation is %d\n", number2);

    return 0;
}