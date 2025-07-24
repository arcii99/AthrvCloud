//FormAI DATASET v1.0 Category: Bitwise operations ; Style: realistic
#include <stdio.h>

/* Function prototype */
void printBits(unsigned int num);

int main()
{
    /* Bitwise AND operator example */
    unsigned int num1 = 12;   // 00001100 in binary
    unsigned int num2 = 25;   // 00011001 in binary
    unsigned int result;

    result = num1 & num2;   // Performing bitwise AND operation

    printf("num1 = %d\n", num1);   // Output: num1 = 12
    printf("num2 = %d\n", num2);   // Output: num2 = 25
    printf("Result of num1 & num2: %d\n", result);   // Output: 8 (00001000 in binary)

    /* Bitwise OR operator example */
    num1 = 10;   // 00001010 in binary
    num2 = 3;    // 00000011 in binary

    result = num1 | num2;   // Performing bitwise OR operation

    printf("num1 = %d\n", num1);   // Output: num1 = 10
    printf("num2 = %d\n", num2);   // Output: num2 = 3
    printf("Result of num1 | num2: %d\n", result);   // Output: 11 (00001011 in binary)

    /* Bitwise XOR operator example */
    num1 = 15;   // 00001111 in binary
    num2 = 6;    // 00000110 in binary

    result = num1 ^ num2;   // Performing bitwise XOR operation

    printf("num1 = %d\n", num1);   // Output: num1 = 15
    printf("num2 = %d\n", num2);   // Output: num2 = 6
    printf("Result of num1 ^ num2: %d\n", result);   // Output: 9 (00001001 in binary)

    /* Bitwise left shift operator example */
    num1 = 5;   // 00000101 in binary

    result = num1 << 2;   // Shifting left by 2 bits

    printf("num1 = %d\n", num1);   // Output: num1 = 5
    printf("Result of num1 << 2: %d\n", result);   // Output: 20 (00010100 in binary)

    /* Bitwise right shift operator example */
    num1 = 15;   // 00001111 in binary

    result = num1 >> 2;   // Shifting right by 2 bits

    printf("num1 = %d\n", num1);   // Output: num1 = 15
    printf("Result of num1 >> 2: %d\n", result);   // Output: 3 (00000011 in binary)

    /* Bitwise complement operator example */
    num1 = 10;   // 00001010 in binary

    result = ~num1;   // Performing bitwise complement operation

    printf("num1 = %d\n", num1);   // Output: num1 = 10
    printf("Result of ~num1: "); 
    printBits(result);  // Output: 11110101 in binary

    return 0;
}

/**
 * Function to print binary representation of a number
 */
void printBits(unsigned int num) 
{
    // Size of integer
    int bits = sizeof(unsigned int)*8;
    // Temporary variable
    unsigned int temp;
    // Loop counter
    int i;

    // Loop through each bit
    for(i=bits-1; i>=0; i--)
    {
        // Get the i-th bit of the number
        temp = (num >> i) & 1;

        // Print the bit
        printf("%d", temp);
    }

    printf("\n");
}