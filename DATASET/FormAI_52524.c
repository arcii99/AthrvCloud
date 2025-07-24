//FormAI DATASET v1.0 Category: Bitwise operations ; Style: shocked
#include<stdio.h>

int main()
{
    int num1 = 23, num2 = 45, result;

    printf("Binary value of num1 is: %d\n", num1);
    printf("Binary value of num2 is: %d\n", num2);

    //bitwise AND operator
    result = num1 & num2;
    printf("Result of bitwise AND operation: %d\n", result);

    //bitwise OR operator
    result = num1 | num2;
    printf("Result of bitwise OR operation: %d\n", result);

    //bitwise XOR operator
    result = num1 ^ num2;
    printf("Result of bitwise XOR operation: %d\n", result);

    //bitwise NOT operator
    result = ~num1;
    printf("Result of bitwise NOT operation on num1: %d\n", result);
    result = ~num2;
    printf("Result of bitwise NOT operation on num2: %d\n", result);

    //bitwise left shift operator
    result = num1 << 2;
    printf("Result of left shift operation on num1 by 2 bits: %d\n", result);

    //bitwise right shift operator
    result = num2 >> 3;
    printf("Result of right shift operation on num2 by 3 bits: %d\n", result);

    return 0;
}