//FormAI DATASET v1.0 Category: Bitwise operations ; Style: ephemeral
#include <stdio.h>

int main() {
    // Welcome message
    printf("Welcome to my Bitwise Operations example program!\n");

    // Get two numbers from the user
    int num1, num2;
    printf("Please enter two numbers separated by a space: ");
    scanf("%d %d", &num1, &num2);

    // Perform Bitwise AND operation
    int bitwise_and = num1 & num2;
    printf("The Bitwise AND of %d and %d is %d.\n", num1, num2, bitwise_and);

    // Perform Bitwise OR operation
    int bitwise_or = num1 | num2;
    printf("The Bitwise OR of %d and %d is %d.\n", num1, num2, bitwise_or);

    // Perform Bitwise XOR operation
    int bitwise_xor = num1 ^ num2;
    printf("The Bitwise XOR of %d and %d is %d.\n", num1, num2, bitwise_xor);

    // Perform Bitwise NOT operation
    int bitwise_not = ~num1;
    printf("The Bitwise NOT of %d is %d.\n", num1, bitwise_not);

    // Perform Bitwise Left Shift operation
    int bitwise_left_shift = num1 << num2;
    printf("The Bitwise Left Shift of %d by %d is %d.\n", num1, num2, bitwise_left_shift);

    // Perform Bitwise Right Shift operation
    int bitwise_right_shift = num1 >> num2;
    printf("The Bitwise Right Shift of %d by %d is %d.\n", num1, num2, bitwise_right_shift);

    // Success message
    printf("Thank you for using my program. Have a great day!\n");

    return 0;
}