//FormAI DATASET v1.0 Category: Bitwise operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    // Create two random numbers
    int num1 = rand();
    int num2 = rand();
    
    // Print the numbers in binary format
    printf("Random numbers: %d (%b) and %d (%b)\n\n", num1, num1, num2, num2);

    // Bitwise AND operator
    int result_and = num1 & num2;
    printf("Result of AND operation: %d (%b) & %d (%b) = %d (%b)\n\n", num1, num1, num2, num2, result_and, result_and);
    
    // Bitwise OR operator
    int result_or = num1 | num2;
    printf("Result of OR operation: %d (%b) | %d (%b) = %d (%b)\n\n", num1, num1, num2, num2, result_or, result_or);

    // Bitwise XOR operator
    int result_xor = num1 ^ num2;
    printf("Result of XOR operation: %d (%b) ^ %d (%b) = %d (%b)\n\n", num1, num1, num2, num2, result_xor, result_xor);

    // Bitwise NOT operator
    int result_not1 = ~num1;
    printf("Result of NOT operation: ~%d (%b) = %d (%b)\n\n", num1, num1, result_not1, result_not1);

    int result_not2 = ~num2;
    printf("Result of NOT operation: ~%d (%b) = %d (%b)\n\n", num2, num2, result_not2, result_not2);

    // Bitwise left shift operator
    int left_shift = num1 << 2;
    printf("Result of left shift operation: %d (%b) << 2 = %d (%b)\n\n", num1, num1, left_shift, left_shift);

    // Bitwise right shift operator
    int right_shift = num2 >> 2;
    printf("Result of right shift operation: %d (%b) >> 2 = %d (%b)\n\n", num2, num2, right_shift, right_shift);

    return 0;
}