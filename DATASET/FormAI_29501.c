//FormAI DATASET v1.0 Category: Bitwise operations ; Style: intelligent
#include <stdio.h>

int main() {
    int num_1 = 10, num_2 = 5, result;

    // Bitwise AND operation
    result = num_1 & num_2;
    printf("Bitwise AND of %d and %d is %d\n", num_1, num_2, result);

    // Bitwise OR operation
    result = num_1 | num_2;
    printf("Bitwise OR of %d and %d is %d\n", num_1, num_2, result);

    // Bitwise XOR operation
    result = num_1 ^ num_2;
    printf("Bitwise XOR of %d and %d is %d\n", num_1, num_2, result);

    // Bitwise Complement operation
    result = ~num_1;
    printf("Bitwise Complement of %d is %d\n", num_1, result);

    // Bitwise Left Shift operation
    result = num_1 << 2;
    printf("Bitwise Left Shift 2 of %d is %d\n", num_1, result);

    // Bitwise Right Shift operation
    result = num_1 >> 2;
    printf("Bitwise Right Shift 2 of %d is %d\n", num_1, result);

    return 0;
}