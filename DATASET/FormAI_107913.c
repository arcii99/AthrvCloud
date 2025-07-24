//FormAI DATASET v1.0 Category: Bitwise operations ; Style: automated
#include <stdio.h>

int main() {
    int num1 = 10, num2 = 5;
    int result;

    // Bitwise AND
    result = num1 & num2;
    printf("Bitwise AND of %d and %d is %d\n", num1, num2, result);

    // Bitwise OR
    result = num1 | num2;
    printf("Bitwise OR of %d and %d is %d\n", num1, num2, result);

    // Bitwise XOR
    result = num1 ^ num2;
    printf("Bitwise XOR of %d and %d is %d\n", num1, num2, result);

    // Bitwise Complement
    result = ~num1;
    printf("Bitwise complement of %d is %d\n", num1, result);

    // Left Shift
    result = num1 << 2;
    printf("Left shift of %d by 2 is %d\n", num1, result);

    // Right Shift
    result = num1 >> 2;
    printf("Right shift of %d by 2 is %d\n", num1, result);

    return 0;
}