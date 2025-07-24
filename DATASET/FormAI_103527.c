//FormAI DATASET v1.0 Category: Bitwise operations ; Style: innovative
#include <stdio.h>

// this program performs bitwise operations on two numbers

// function to extract the nth bit of a number
int get_bit(int num, int n) {
    return (num >> n) & 1; // shift the number to the right by n bits and perform a bitwise AND operation with 1 to get the nth bit
}

int main() {
    int num1 = 27, num2 = 48; // initialize two numbers
    int result; // to store the result of the bitwise operations

    printf("The first number is %d\n", num1);
    printf("The second number is %d\n\n", num2);

    printf("Bitwise AND operation:\n");
    result = num1 & num2;
    printf("%d & %d = %d\n\n", num1, num2, result);

    printf("Bitwise OR operation:\n");
    result = num1 | num2;
    printf("%d | %d = %d\n\n", num1, num2, result);

    printf("Bitwise XOR operation:\n");
    result = num1 ^ num2;
    printf("%d ^ %d = %d\n\n", num1, num2, result);

    printf("Bitwise NOT operation on the first number:\n");
    result = ~num1;
    printf("~%d = %d\n\n", num1, result);

    printf("Bitwise left shift operation on the second number:\n");
    result = num2 << 2;
    printf("%d << 2 = %d\n\n", num2, result);

    printf("Bitwise right shift operation on the first number:\n");
    result = num1 >> 3;
    printf("%d >> 3 = %d\n\n", num1, result);

    printf("Extracting the 3rd bit of the first number:\n");
    result = get_bit(num1, 2); // remember, we start counting from 0, so to get the 3rd bit we pass 2 as the second argument
    printf("The 3rd bit of %d is %d\n\n", num1, result);

    printf("Extracting the 6th bit of the second number:\n");
    result = get_bit(num2, 5); // same logic as before for getting the 6th bit
    printf("The 6th bit of %d is %d\n\n", num2, result);

    return 0; // all done!
}