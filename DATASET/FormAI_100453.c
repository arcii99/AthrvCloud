//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mathematical
#include<stdio.h>

/* Bitwise Operations Example Program */

int main() {
    int num1 = 8;  // Binary 1000
    int num2 = 12; // Binary 1100
    int result;

    // Bitwise AND operation
    result = num1 & num2;
    printf("The result of bitwise AND operation between %d and %d is %d. \n", num1, num2, result);
    // Output: The result of bitwise AND operation between 8 and 12 is 8.

    // Bitwise OR operation
    result = num1 | num2;
    printf("The result of bitwise OR operation between %d and %d is %d. \n", num1, num2, result);
    // Output: The result of bitwise OR operation between 8 and 12 is 12.

    // Bitwise XOR operation
    result = num1 ^ num2;
    printf("The result of bitwise XOR operation between %d and %d is %d. \n", num1, num2, result);
    // Output: The result of bitwise XOR operation between 8 and 12 is 4.

    // Bitwise NOT operation
    result = ~num1;
    printf("The result of bitwise NOT operation on %d is %d. \n", num1, result);
    // Output: The result of bitwise NOT operation on 8 is -9.
    
    // Bitwise LEFT SHIFT operation
    result = num1 << 2;
    printf("The result of bitwise LEFT SHIFT operation on %d by 2 is %d. \n", num1, result);
    // Output: The result of bitwise LEFT SHIFT operation on 8 by 2 is 32.

    // Bitwise RIGHT SHIFT operation
    result = num2 >> 2;
    printf("The result of bitwise RIGHT SHIFT operation on %d by 2 is %d. \n", num2, result);
    // Output: The result of bitwise RIGHT SHIFT operation on 12 by 2 is 3.
    
    return 0;
}