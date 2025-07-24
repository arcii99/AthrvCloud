//FormAI DATASET v1.0 Category: Bitwise operations ; Style: enthusiastic
#include <stdio.h>

int main() {
    printf("Welcome to this amazing program showcasing the power of C Bitwise Operations!\n");
    printf("We will perform some basic operations on two numbers using the different bitwise operators.\n");

    int num1 = 23;
    int num2 = 56;

    printf("Numbers used in the program: num1=%d, num2=%d\n\n", num1, num2);

    // Bitwise AND operator
    printf("Bitwise AND operator:\n");
    int result = num1 & num2;
    printf("%d & %d = %d\n\n", num1, num2, result);

    // Bitwise OR operator
    printf("Bitwise OR operator:\n");
    result = num1 | num2;
    printf("%d | %d = %d\n\n", num1, num2, result);

    // Bitwise XOR operator
    printf("Bitwise XOR operator:\n");
    result = num1 ^ num2;
    printf("%d ^ %d = %d\n\n", num1, num2, result);

    // Bitwise left shift operator
    printf("Bitwise left shift operator:\n");
    result = num1 << 2;
    printf("%d << 2 = %d\n\n", num1, result);

    // Bitwise right shift operator
    printf("Bitwise right shift operator:\n");
    result = num2 >> 3;
    printf("%d >> 3 = %d\n\n", num2, result);

    printf("That's it folks! This program showcases some of the basic operations that can be performed using C Bitwise Operators.\n");

    return 0;
}