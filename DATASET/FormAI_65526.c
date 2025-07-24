//FormAI DATASET v1.0 Category: Bitwise operations ; Style: creative
#include <stdio.h>

int main() {
    int x = 5;  // Decimal 5 is equivalent to binary 0101 in binary
    int y = 3;  // Decimal 3 is equivalent to binary 0011 in binary

    // Bitwise AND
    int result_and = x & y;  // Using Bitwise AND operator
    printf("The result of Bitwise AND between %d and %d is %d\n", x, y, result_and);

    // Bitwise OR
    int result_or = x | y;  // Using Bitwise OR operator
    printf("The result of Bitwise OR between %d and %d is %d\n", x, y, result_or);

    // Bitwise XOR
    int result_xor = x ^ y;  // Using Bitwise XOR operator
    printf("The result of Bitwise XOR between %d and %d is %d\n", x, y, result_xor);

    // Bitwise NOT
    int result_not = ~x;  // Using Bitwise NOT operator
    printf("The result of Bitwise NOT of %d is %d\n", x, result_not);

    // Bitwise Left Shift
    int result_lshift = x << 2;  // Using Bitwise Left Shift operator
    printf("The result of Bitwise Left Shift of %d by 2 is %d\n", x, result_lshift);

    // Bitwise Right Shift
    int result_rshift = x >> 1;  // Using Bitwise Right Shift operator
    printf("The result of Bitwise Right Shift of %d by 1 is %d\n", x, result_rshift);

    return 0;
}