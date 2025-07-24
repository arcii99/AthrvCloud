//FormAI DATASET v1.0 Category: Bitwise operations ; Style: safe
#include <stdio.h>

/* Function to print bits in binary format */
void print_binary(unsigned int num, int bits)
{
    int i;
    for (i = bits - 1; i >= 0; i--) // Loop through each bit
        printf("%d", (num >> i) & 1); // Print the bit
}

int main()
{
    unsigned int x = 0xAAAA, y = 0xCCCC;
    
    printf("x in binary: ");
    print_binary(x, 16); // Print x in binary format
    printf("\n");
    
    printf("y in binary: ");
    print_binary(y, 16); // Print y in binary format
    printf("\n");

    printf("x & y in binary: ");
    print_binary(x & y, 16); // Print x & y in binary format
    printf("\n");

    printf("x | y in binary: ");
    print_binary(x | y, 16); // Print x | y in binary format
    printf("\n");

    printf("~x in binary: ");
    print_binary(~x, 16); // Print ~x in binary format
    printf("\n");

    printf("x ^ y in binary: ");
    print_binary(x ^ y, 16); // Print x ^ y in binary format
    printf("\n");

    printf("x << 1 in binary: ");
    print_binary(x << 1, 16); // Print x shifted left by one bit in binary format
    printf("\n");

    printf("y >> 1 in binary: ");
    print_binary(y >> 1, 16); // Print y shifted right by one bit in binary format
    printf("\n");

    return 0;
}