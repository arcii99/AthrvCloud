//FormAI DATASET v1.0 Category: Bitwise operations ; Style: beginner-friendly
#include <stdio.h>

// A function to print bit pattern of a number
void printBits(unsigned int num)
{
    for(int i=31;i>=0;i--)
    {
        if((num>>i)&1)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

int main()
{
    unsigned int num1 = 7, num2 = 15;
    
    printf("Bitwise AND (num1 & num2): %u\n", num1 & num2); // Bitwise AND
    printf("Bitwise OR (num1 | num2): %u\n", num1 | num2); // Bitwise OR
    printf("Bitwise XOR (num1 ^ num2): %u\n", num1 ^ num2); // Bitwise XOR
    printf("Bitwise Complement (~num1): %u\n", ~num1); // Bitwise Complement
    printf("Left Shift (num1 << 1): %u\n", num1 << 1); // Left Shift
    printf("Right Shift (num1 >> 1): %u\n", num1 >> 1); // Right Shift

    printf("\nBinary of num1: ");
    printBits(num1);
    printf("Binary of num2: ");
    printBits(num2);
    
    return 0;
}