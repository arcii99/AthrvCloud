//FormAI DATASET v1.0 Category: Bitwise operations ; Style: invasive
#include <stdio.h>

int main() {
    printf("Welcome to the Bitwise Invasion!\n");

    int num1 = 6;
    int num2 = 3;

    printf("Before bitwise operations:\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);

    // Bitwise AND operation
    num1 = num1 & num2;
    printf("\nAfter performing Bitwise AND operation:\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);

    // Bitwise OR operation
    num1 = num1 | num2;
    printf("\nAfter performing Bitwise OR operation:\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);

    // Bitwise XOR operation
    num1 = num1 ^ num2;
    printf("\nAfter performing Bitwise XOR operation:\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);

    // Bitwise NOT operation
    num1 = ~num1;
    printf("\nAfter performing Bitwise NOT operation:\n");
    printf("num1 = %d\n", num1);

    // Bitwise left shift operation
    num1 = num1 << 2;
    printf("\nAfter performing Bitwise left shift operation:\n");
    printf("num1 = %d\n", num1);

    // Bitwise right shift operation
    num1 = num1 >> 2;
    printf("\nAfter performing Bitwise right shift operation:\n");
    printf("num1 = %d\n", num1);

    printf("\nThank you for using the Bitwise Invasion program!\n");

    return 0;
}