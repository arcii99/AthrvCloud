//FormAI DATASET v1.0 Category: Bitwise operations ; Style: careful
#include <stdio.h>

int main() {
    int num1 = 5, num2 = 9;
    printf("num1 = %d\nnum2 = %d\n", num1, num2);
    
    // Bitwise AND operation
    int bitwise_and = num1 & num2;
    printf("\nBitwise AND operation: num1 & num2 = %d\n", bitwise_and);
    
    // Bitwise OR operation
    int bitwise_or = num1 | num2;
    printf("\nBitwise OR operation: num1 | num2 = %d\n", bitwise_or);
    
    // Bitwise XOR operation
    int bitwise_xor = num1 ^ num2;
    printf("\nBitwise XOR operation: num1 ^ num2 = %d\n", bitwise_xor);
    
    // Bitwise complement operator
    int bitwise_comp = ~num1;
    printf("\nBitwise Complement operation: ~num1 = %d\n", bitwise_comp);
    
    // Bitwise left shift operator
    int left_shift = num1 << 2;
    printf("\nBitwise left shift operation: num1 << 2 = %d\n", left_shift);
    
    // Bitwise right shift operator
    int right_shift = num2 >> 1;
    printf("\nBitwise right shift operation: num2 >> 1 = %d\n", right_shift);
    
    return 0;
}