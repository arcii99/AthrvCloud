//FormAI DATASET v1.0 Category: Bitwise operations ; Style: shocked
#include <stdio.h>

int main() {
    int num1 = 37;        // 0010 0101 in binary
    int num2 = 25;        // 0001 1001 in binary
    
    printf("Initial Values:\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n\n", num2);
    
    // Bitwise AND operator
    int result1 = num1 & num2;        // 0000 0001 in binary
    printf("Result of Bitwise AND operator:\n");
    printf("num1 & num2 = %d\n\n", result1);

    // Bitwise OR operator
    int result2 = num1 | num2;        // 0011 1101 in binary
    printf("Result of Bitwise OR operator:\n");
    printf("num1 | num2 = %d\n\n", result2);

    // Bitwise XOR operator
    int result3 = num1 ^ num2;        // 0011 1100 in binary
    printf("Result of Bitwise XOR operator:\n");
    printf("num1 ^ num2 = %d\n\n", result3);
    
    // Bitwise NOT operator
    int result4 = ~num1;              // 1101 1010 in binary (two's complement)
    printf("Result of Bitwise NOT operator:\n");
    printf("~num1 = %d\n\n", result4);
    
    // Bitwise left shift operator
    int result5 = num1 << 2;          // 1001 0100 in binary
    printf("Result of Bitwise left shift operator:\n");
    printf("num1 << 2 = %d\n\n", result5);

    // Bitwise right shift operator
    int result6 = num2 >> 1;          // 0000 1100 in binary
    printf("Result of Bitwise right shift operator:\n");
    printf("num2 >> 1 = %d\n\n", result6);

    printf("Final Values:\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);

    return 0;
}