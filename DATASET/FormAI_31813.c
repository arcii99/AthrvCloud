//FormAI DATASET v1.0 Category: Bitwise operations ; Style: cheerful
#include <stdio.h>

int main() {

    printf("Hello there! Let's have some fun with bitwise operations!\n");
    printf("We can use bitwise operators to perform operations on individual bits of binary numbers.\n");
    printf("For example, let's declare two variables, a and b, and assign them some values.\n");

    int a = 5;
    int b = 3;

    printf("The values of a and b are %d and %d respectively.\n", a, b);

    printf("Using the AND operator (&), we can perform a bitwise AND operation on a and b.\n");
    int result = a & b;
    printf("a & b = %d\n", result);

    printf("Using the OR operator (|), we can perform a bitwise OR operation on a and b.\n");
    result = a | b;
    printf("a | b = %d\n", result);

    printf("Using the XOR operator (^), we can perform a bitwise XOR operation on a and b.\n");
    result = a ^ b;
    printf("a ^ b = %d\n", result);

    printf("Using the left shift operator (<<), we can shift the bits of a to the left by a specified number of positions.\n");
    int shift_amount = 2;
    result = a << shift_amount;
    printf("a << %d = %d\n", shift_amount, result);

    printf("Using the right shift operator (>>), we can shift the bits of a to the right by a specified number of positions.\n");
    result = a >> shift_amount;
    printf("a >> %d = %d\n", shift_amount, result);

    printf("Now let's have some more fun by using bitwise operators to set and clear individual bits of a number.\n");
    printf("Using the bitwise OR operator (|), we can set a particular bit to 1.\n");
    int bit = 2;
    result = a | (1 << bit);
    printf("Setting bit %d of a to 1: %d\n", bit, result);

    printf("Using the bitwise AND operator (&), we can clear a particular bit to 0.\n");
    result = a & ~(1 << bit);
    printf("Clearing bit %d of a to 0: %d\n", bit, result);

    printf("That was fun! Let's try some more bitwise operations!\n");
    printf("Press any key to continue...\n");

    getchar(); // wait for user input

    printf("Using the bitwise NOT operator (~), we can invert all the bits of a number.\n");
    result = ~a;
    printf("~a: %d\n", result);

    printf("We can also use the bitwise AND operator (&) to check if a particular bit is set or not.\n");
    result = a & (1 << bit);
    if (result) {
        printf("Bit %d of a is set.\n", bit);
    } else {
        printf("Bit %d of a is not set.\n", bit);
    }

    printf("That's all for now! Have fun with bitwise operations!\n");

    return 0;
}