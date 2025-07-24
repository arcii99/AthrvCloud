//FormAI DATASET v1.0 Category: Bitwise operations ; Style: all-encompassing
#include <stdio.h>
#include <stdbool.h>

int main() {
    int num = 5; // Assigning a value to num (101 in binary)
    int mask = 7; // Assigning a value to mask (111 in binary)
    int result;

    // Performing Bitwise AND operation
    result = num & mask;
    printf("Bitwise AND operation result: %d\n", result); // Output: 5

    // Performing Bitwise OR operation
    result = num | mask;
    printf("Bitwise OR operation result: %d\n", result); // Output: 7

    // Performing Bitwise XOR operation
    result = num ^ mask;
    printf("Bitwise XOR operation result: %d\n", result); // Output: 2

    // Performing Bitwise NOT operation
    result = ~num;
    printf("Bitwise NOT operation result: %d\n", result); // Output: -6

    // Performing Bitwise Left Shift operation
    result = num << 2;
    printf("Bitwise Left Shift operation result: %d\n", result); // Output: 20

    // Performing Bitwise Right Shift operation
    result = num >> 2;
    printf("Bitwise Right Shift operation result: %d\n", result); // Output: 1

    // Performing Bitwise Boolean operation
    bool b_result = num && mask;
    printf("Bitwise Boolean operation result: %d\n", b_result); // Output: 1 (true)

    // Performing Bitwise Comparison operation
    b_result = (num == mask);
    printf("Bitwise Comparison operation result: %d\n", b_result); // Output: 0 (false)

    return 0;
}