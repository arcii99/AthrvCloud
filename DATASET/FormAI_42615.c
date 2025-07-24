//FormAI DATASET v1.0 Category: Bitwise operations ; Style: genious
#include <stdio.h>

// Function to print binary representation of a number
void printBinary(int num)
{
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--)
        printf("%d", (num >> i) & 1);
 
    printf("\n");
}

int main()
{
    int a = 10, b = 20, c = 30;
 
    printf("The values of a, b and c are: %d %d %d\n", a, b, c);

    // Bitwise OR example
    int or_result = a | b;
    printf("The result of bitwise OR between a and b is: ");
    printBinary(or_result);

    // Bitwise AND example
    int and_result = a & b;
    printf("The result of bitwise AND between a and b is: ");
    printBinary(and_result);

    // Bitwise XOR example
    int xor_result = a ^ b;
    printf("The result of bitwise XOR between a and b is: ");
    printBinary(xor_result);

    // Bitwise Complement example
    int complement_a = ~a;
    printf("The complement of a is: ");
    printBinary(complement_a);

    printf("The complement of b is: ");
    printBinary(~b);

    // Bitwise Left shift example
    int left_shift_result = a << 2;
    printf("The result of left shift of a by 2 is: ");
    printBinary(left_shift_result);

    // Bitwise Right shift example
    int right_shift_result = a >> 2;
    printf("The result of right shift of a by 2 is: ");
    printBinary(right_shift_result);

    // Bitwise Conditional Operators Example
    int result1 = a > b ? a : b;
    printf("The result of conditional operator with a > b is: %d\n", result1);

    int result2 = c > b ? a : b;
    printf("The result of conditional operator with c > b is: %d\n", result2);

    return 0;
}