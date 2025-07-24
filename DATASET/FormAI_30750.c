//FormAI DATASET v1.0 Category: Bitwise operations ; Style: random
#include <stdio.h>

/* Function to print binary of unsigned integer */
void printBinary(unsigned int num)
{
    if (num > 1)
        printBinary(num/2);

    printf("%d", num % 2);
}

int main()
{
    int a = 7, b = 9;
    
    printf("a = %d in binary: ", a);
    printBinary(a);
    printf("\n");
    
    printf("b = %d in binary: ", b);
    printBinary(b);
    printf("\n");
    
    // Bitwise AND
    printf("a & b = %d in binary: ", a & b);
    printBinary(a & b);
    printf("\n");
    
    // Bitwise OR
    printf("a | b = %d in binary: ", a | b);
    printBinary(a | b);
    printf("\n");
    
    // Bitwise XOR
    printf("a ^ b = %d in binary: ", a ^ b);
    printBinary(a ^ b);
    printf("\n");
    
    // Left shift
    printf("a << 2 = %d in binary: ", a << 2);
    printBinary(a << 2);
    printf("\n");
    
    // Right shift
    printf("a >> 2 = %d in binary: ", a >> 2);
    printBinary(a >> 2);
    printf("\n");
    
    // Ones complement
    printf("~a = %d in binary: ", ~a);
    printBinary(~a);
    printf("\n");
    
    // Twos complement (negative of a)
    printf("-a = %d in binary: ", -a);
    printBinary(-a);
    printf("\n");
    
    return 0;
}