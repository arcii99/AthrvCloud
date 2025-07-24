//FormAI DATASET v1.0 Category: Bitwise operations ; Style: shocked
#include <stdio.h>

int main() {
    int num1 = 15, num2 = 27;

    // Bitwise AND operation
    int result1 = num1 & num2;
    printf("Bitwise AND of %d and %d is %d\n", num1, num2, result1);

    // Bitwise OR operation
    int result2 = num1 | num2;
    printf("Bitwise OR of %d and %d is %d\n", num1, num2, result2);

    // Bitwise XOR operation
    int result3 = num1 ^ num2;
    printf("Bitwise XOR of %d and %d is %d\n", num1, num2, result3);

    // Bitwise NOT operation
    int result4 = ~num1;
    printf("Bitwise NOT of %d is %d\n", num1, result4);

    // Bitwise left shift operation
    int result5 = num1 << 2;
    printf("Bitwise left shift of %d by 2 is %d\n", num1, result5);

    // Bitwise right shift operation
    int result6 = num2 >> 3;
    printf("Bitwise right shift of %d by 3 is %d\n", num2, result6);

    return 0;
}