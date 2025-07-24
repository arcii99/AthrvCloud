//FormAI DATASET v1.0 Category: Bitwise operations ; Style: lively
#include <stdio.h>

int main() {
    int num1 = 15, num2 = 7;                              // Initialize two integers, num1 and num2, to 15 and 7 respectively
    int result_AND = num1 & num2;                         // Perform the bitwise AND operation on num1 and num2, store the result in result_AND
    int result_OR = num1 | num2;                          // Perform the bitwise OR operation on num1 and num2, store the result in result_OR
    int result_XOR = num1 ^ num2;                         // Perform the bitwise XOR operation on num1 and num2, store the result in result_XOR
    int result_LEFT_SHIFT = num1 << 2;                    // Perform the left shift operation on num1, with a shift of 2 bits, store the result in result_LEFT_SHIFT
    int result_RIGHT_SHIFT = num1 >> 2;                   // Perform the right shift operation on num1, with a shift of 2 bits, store the result in result_RIGHT_SHIFT
    int result_COMPLEMENT = ~num1;                        // Perform the bitwise NOT operation on num1, store the result in result_COMPLEMENT
    
    printf("num1                      = %d\n", num1);     // Print num1's value
    printf("num2                      = %d\n", num2);     // Print num2's value
    printf("num1 & num2               = %d\n", result_AND);       // Print the result of the bitwise AND operation
    printf("num1 | num2               = %d\n", result_OR);        // Print the result of the bitwise OR operation
    printf("num1 ^ num2               = %d\n", result_XOR);       // Print the result of the bitwise XOR operation
    printf("num1 << 2                 = %d\n", result_LEFT_SHIFT); // Print the result of the left shift operation
    printf("num1 >> 2                 = %d\n", result_RIGHT_SHIFT);// Print the result of the right shift operation
    printf("~num1                     = %d\n", result_COMPLEMENT);// Print the result of the bitwise NOT operation on num1
    
    return 0;                                              // Return 0 to the OS to signify successful completion of the program
}