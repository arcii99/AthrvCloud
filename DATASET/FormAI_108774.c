//FormAI DATASET v1.0 Category: Bitwise operations ; Style: creative
#include <stdio.h>

int main() {
    // Display an introduction message to the user
    printf("Welcome to the Bitwise Operations Example Program!\n");
    printf("This program demonstrates the use of bitwise operators in C.\n\n");

    // Prompt the user to enter two integers
    int num1, num2;
    printf("Please enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // Perform bitwise AND operation on the two numbers
    int bitwiseAnd = num1 & num2;
    printf("\nThe result of the bitwise AND operation on %d and %d is %d.\n", num1, num2, bitwiseAnd);

    // Perform bitwise OR operation on the two numbers
    int bitwiseOr = num1 | num2;
    printf("The result of the bitwise OR operation on %d and %d is %d.\n", num1, num2, bitwiseOr);

    // Perform bitwise XOR operation on the two numbers
    int bitwiseXor = num1 ^ num2;
    printf("The result of the bitwise XOR operation on %d and %d is %d.\n", num1, num2, bitwiseXor);

    // Perform bitwise NOT operation on the first number
    int bitwiseNot = ~num1;
    printf("The result of the bitwise NOT operation on %d is %d.\n", num1, bitwiseNot);

    // Perform left shift operation on the first number
    int shiftLeft = num1 << 2;
    printf("The result of the left shift operation on %d by 2 bits is %d.\n", num1, shiftLeft);

    // Perform right shift operation on the first number
    int shiftRight = num1 >> 2;
    printf("The result of the right shift operation on %d by 2 bits is %d.\n", num1, shiftRight);

    // Exit the program with a success status code
    return 0;
}