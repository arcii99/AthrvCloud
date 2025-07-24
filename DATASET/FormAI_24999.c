//FormAI DATASET v1.0 Category: Bitwise operations ; Style: excited
#include <stdio.h>

int main() {
    // This program demonstrates the power of bitwise operations
    printf("Get ready to be amazed! Let's start with some binary numbers:\n");
    
    // Let's choose two random numbers to demonstrate the bitwise AND operator
    int num1 = 0b11100101;
    int num2 = 0b10011110;

    // Bitwise AND will only output 1 if both operands have a corresponding 1 in their binary representation
    int result = num1 & num2;

    printf("\nUsing the bitwise AND operator, we get:\n");
    printf("%d (in decimal)\n", result);
    printf("0b%d (in binary)\n", result);

    // Now let's move on to the bitwise OR operator and choose two more random numbers
    int num3 = 0b11110101;
    int num4 = 0b01101110;

    // Bitwise OR will output 1 if either operand has a corresponding 1 in their binary representation
    result = num3 | num4;

    printf("\nUsing the bitwise OR operator, we get:\n");
    printf("%d (in decimal)\n", result);
    printf("0b%d (in binary)\n", result);

    // Finally, let's show the bitwise XOR operator with the last two random numbers
    int num5 = 0b10101010;
    int num6 = 0b01010101;

    // Bitwise XOR will output 1 if operands have a different corresponding bit
    result = num5 ^ num6;

    printf("\nUsing the bitwise XOR operator, we get:\n");
    printf("%d (in decimal)\n", result);
    printf("0b%d (in binary)\n", result);

    printf("\nTa-daaaa! You just witnessed the power of bitwise operations. Amazing, right?\n");
    return 0;
}