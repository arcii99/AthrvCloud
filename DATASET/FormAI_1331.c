//FormAI DATASET v1.0 Category: Bitwise operations ; Style: active
#include <stdio.h>

int main() {

    // Take two numbers as input from the user
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Perform bitwise AND operation
    int bitwise_AND = num1 & num2;
    printf("Bitwise AND of %d and %d = %d\n", num1, num2, bitwise_AND);

    // Perform bitwise OR operation
    int bitwise_OR = num1 | num2;
    printf("Bitwise OR of %d and %d = %d\n", num1, num2, bitwise_OR);

    // Perform bitwise XOR operation
    int bitwise_XOR = num1 ^ num2;
    printf("Bitwise XOR of %d and %d = %d\n", num1, num2, bitwise_XOR);

    // Perform left shift operation on num1
    int left_shift = num1 << 2;
    printf("Left shift of %d by 2 = %d\n", num1, left_shift);

    // Perform right shift operation on num2
    int right_shift = num2 >> 2;
    printf("Right shift of %d by 2 = %d\n", num2, right_shift);

    // ~ invert operator
    printf("Invert of %d = %d\n", num1, ~num1);

    // Setting the nth bit to 1
    int bit_number;
    printf("Enter the bit number to set (0-31): ");
    scanf("%d", &bit_number);
    int mask = 1 << bit_number;
    num1 = num1 | mask; // set the nth bit of num1
    printf("After setting bit %d, the value of num1 is %d\n", bit_number, num1);

    // Clearing the nth bit to 0
    printf("Enter the bit number to clear (0-31): ");
    scanf("%d", &bit_number);
    mask = ~(1 << bit_number);
    num2 = num2 & mask; // clear the nth bit of num2
    printf("After clearing bit %d, the value of num2 is %d\n", bit_number, num2);

    return 0;
}