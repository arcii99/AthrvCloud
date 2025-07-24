//FormAI DATASET v1.0 Category: Bitwise operations ; Style: unmistakable
#include <stdio.h>

int main() {
    int num1 = 10;
    int num2 = 5;
    int result;

    // AND operation
    result = num1 & num2;
    printf("AND operation: %d\n", result);

    // OR operation
    result = num1 | num2;
    printf("OR operation: %d\n", result);

    // XOR operation
    result = num1 ^ num2;
    printf("XOR operation: %d\n", result);

    // Shift left operation
    result = num1 << 2;
    printf("Shift left operation: %d\n", result);

    // Shift right operation
    result = num1 >> 2;
    printf("Shift right operation: %d\n", result);

    // Complement operation
    result = ~num1;
    printf("Complement operation: %d\n", result);

    // Using bitwise operation to check if a number is even or odd
    int num3 = 8;
    if (num3 & 1) {
        printf("%d is odd\n", num3);
    }
    else {
        printf("%d is even\n", num3);
    }

    return 0;
}