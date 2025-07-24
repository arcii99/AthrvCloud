//FormAI DATASET v1.0 Category: Bitwise operations ; Style: enthusiastic
#include <stdio.h>

int main() {

    printf("Welcome to my Bitwise Operations Program!\n");
    printf("This program will demonstrate the power and flexibility of C's bitwise operators.\n");

    // bitwise NOT operator (~)
    unsigned int num1 = 10;
    printf("Initial value of num1: %u\n", num1);
    num1 = ~num1;
    printf("Value of num1 after applying the ~ operator: %u\n", num1);

    // bitwise AND operator (&)
    unsigned int num2 = 35;
    unsigned int num3 = 57;
    unsigned int result = num2 & num3;
    printf("\nInitial values of num2 and num3: %u and %u\n", num2, num3);
    printf("Value of num2 & num3: %u\n", result);

    // bitwise OR operator (|)
    unsigned int num4 = 136;
    unsigned int num5 = 233;
    unsigned int result2 = num4 | num5;
    printf("\nInitial values of num4 and num5: %u and %u\n", num4, num5);
    printf("Value of num4 | num5: %u\n", result2);

    // bitwise XOR operator (^)
    unsigned int num6 = 72;
    unsigned int num7 = 105;
    unsigned int result3 = num6 ^ num7;
    printf("\nInitial values of num6 and num7: %u and %u\n", num6, num7);
    printf("Value of num6 ^ num7: %u\n", result3);

    // bitshift left operator (<<)
    unsigned int num8 = 164;
    unsigned int result4 = num8 << 2;
    printf("\nInitial value of num8: %u\n", num8);
    printf("Value of num8 << 2: %u\n", result4);

    // bitshift right operator (>>)
    unsigned int num9 = 107;
    unsigned int result5 = num9 >> 3;
    printf("\nInitial value of num9: %u\n", num9);
    printf("Value of num9 >> 3: %u\n", result5);

    printf("\nThanks for checking out my program! I hope you found it informative and useful.\n");

    return 0;
}