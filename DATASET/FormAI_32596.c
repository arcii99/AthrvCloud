//FormAI DATASET v1.0 Category: Bitwise operations ; Style: all-encompassing
#include<stdio.h>

// Function to print the bits of an integer
void printBits(int n)
{
    int size = sizeof(n) * 8;
    for(int i = size - 1; i >= 0; i--)
        printf("%d", (n >> i) & 1);
    printf("\n");
}

// Function to perform a bitwise AND operation between two numbers and return the result
int bitwiseAnd(int a, int b)
{
    return a & b;
}

// Function to perform a bitwise OR operation between two numbers and return the result
int bitwiseOr(int a, int b)
{
    return a | b;
}

// Function to perform a bitwise XOR operation between two numbers and return the result
int bitwiseXor(int a, int b)
{
    return a ^ b;
}

// Function to perform a bitwise NOT operation on a number and return the result
int bitwiseNot(int n)
{
    return ~n;
}

// Function to perform a left shift operation on a number and return the result
int leftShift(int n, int shift)
{
    return n << shift;
}

// Function to perform a right shift operation on a number and return the result
int rightShift(int n, int shift)
{
    return n >> shift;
}

int main()
{
    int a = 10, b = 5;
    
    // Perform a bitwise AND operation on a and b
    int andResult = bitwiseAnd(a, b);
    printf("Bitwise AND result of %d and %d is %d\n", a, b, andResult);
    printf("Binary representation of %d: ", a);
    printBits(a);
    printf("Binary representation of %d: ", b);
    printBits(b);
    printf("Binary representation of %d: ", andResult);
    printBits(andResult);
    
    // Perform a bitwise OR operation on a and b
    int orResult = bitwiseOr(a, b);
    printf("Bitwise OR result of %d and %d is %d\n", a, b, orResult);
    printf("Binary representation of %d: ", orResult);
    printBits(orResult);
    
    // Perform a bitwise XOR operation on a and b
    int xorResult = bitwiseXor(a, b);
    printf("Bitwise XOR result of %d and %d is %d\n", a, b, xorResult);
    printf("Binary representation of %d: ", xorResult);
    printBits(xorResult);
    
    // Perform a bitwise NOT operation on a
    int notResult = bitwiseNot(a);
    printf("Bitwise NOT result of %d is %d\n", a, notResult);
    printf("Binary representation of %d: ", notResult);
    printBits(notResult);
    
    // Perform a left shift operation on a
    int leftShiftResult = leftShift(a, 2);
    printf("Left shift result of %d by 2 is %d\n", a, leftShiftResult);
    printf("Binary representation of %d: ", leftShiftResult);
    printBits(leftShiftResult);
    
    // Perform a right shift operation on a
    int rightShiftResult = rightShift(a, 2);
    printf("Right shift result of %d by 2 is %d\n", a, rightShiftResult);
    printf("Binary representation of %d: ", rightShiftResult);
    printBits(rightShiftResult);
    
    return 0;
}