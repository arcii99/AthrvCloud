//FormAI DATASET v1.0 Category: Bitwise operations ; Style: sophisticated
#include <stdio.h>

/*
    This program demonstrates the use of bitwise operators in C programming language.
    It takes two integer inputs from the user and performs various operations using bitwise operators.
*/

int main() {
    int num1, num2, result;

    // taking inputs from the user
    printf("Enter two integers: ");
    scanf("%d%d", &num1, &num2);

    // bitwise AND
    result = num1 & num2;
    printf("\n%d & %d = %d\n", num1, num2, result);

    // bitwise OR
    result = num1 | num2;
    printf("\n%d | %d = %d\n", num1, num2, result);

    // bitwise XOR
    result = num1 ^ num2;
    printf("\n%d ^ %d = %d\n", num1, num2, result);

    // bitwise NOT
    result = ~num1;
    printf("\n~%d = %d\n", num1, result);

    // left shift
    result = num1 << 1;
    printf("\n%d << 1 = %d\n", num1, result);

    // right shift
    result = num1 >> 1;
    printf("\n%d >> 1 = %d\n", num1, result);

    return 0;
}