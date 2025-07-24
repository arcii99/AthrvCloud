//FormAI DATASET v1.0 Category: Bitwise operations ; Style: synchronous
#include <stdio.h>

// Function to perform the bitwise NOT operation
void bitwise_not(int num1)
{
    printf("The bitwise NOT of %d is %d.\n", num1, ~num1);
}

// Function to perform the bitwise AND operation
void bitwise_and(int num1, int num2)
{
    printf("The bitwise AND of %d and %d is %d.\n", num1, num2, num1 & num2);
}

// Function to perform the bitwise OR operation
void bitwise_or(int num1, int num2)
{
    printf("The bitwise OR of %d and %d is %d.\n", num1, num2, num1 | num2);
}

// Function to perform the bitwise XOR operation
void bitwise_xor(int num1, int num2)
{
    printf("The bitwise XOR of %d and %d is %d.\n", num1, num2, num1 ^ num2);
}

// Function to perform the left shift operation
void left_shift(int num1, int shift)
{
    printf("The left shift of %d by %d bits is %d.\n", num1, shift, num1 << shift);
}

// Function to perform the right shift operation
void right_shift(int num1, int shift)
{
    printf("The right shift of %d by %d bits is %d.\n", num1, shift, num1 >> shift);
}

int main() {
    int num1 = 10;
    int num2 = 20;
    int shift = 3;
    
    bitwise_not(num1);
    
    bitwise_and(num1, num2);
    
    bitwise_or(num1, num2);
    
    bitwise_xor(num1, num2);
    
    left_shift(num1, shift);
    
    right_shift(num1, shift);
    
    return 0;
}