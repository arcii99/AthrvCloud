//FormAI DATASET v1.0 Category: Bitwise operations ; Style: portable
#include <stdio.h>

void binary_print(unsigned int num)
{
    //print the bits of a number
    unsigned int mask = 0x80000000; //10000000 00000000 00000000 00000000
    int i;
    for (i = 0; i < 32; i++)
    {
        if ((num & mask) == 0){ printf("0");}
        else{ printf("1");}
        //shift the mask to the right by one
        mask = mask >> 1;
    }
    printf("\n");
}

int main()
{
    unsigned int a = 15; //00000000 00000000 00000000 00001111
    unsigned int b = 2; //00000000 00000000 00000000 00000010
    unsigned int result;

    //Bitwise AND
    result = a & b; //00000000 00000000 00000000 00000010
    printf("Bitwise AND:\n");
    binary_print(result);

    //Bitwise OR
    result = a | b; //00000000 00000000 00000000 00001111
    printf("\nBitwise OR:\n");
    binary_print(result);

    //Bitwise XOR
    result = a ^ b; //00000000 00000000 00000000 00001101
    printf("\nBitwise XOR:\n");
    binary_print(result);

    //Bitwise NOT
    result = ~a; // 11111111 11111111 11111111 11110000
    printf("\nBitwise NOT:\n");
    binary_print(result);

    //Bitwise left shift
    result = a << 2; //00000000 00000000 00000000 00111100
    printf("\nBitwise left shift:\n");
    binary_print(result);

    //Bitwise right shift
    result = a >> 2; //00000000 00000000 00000000 00000011
    printf("\nBitwise right shift:\n");
    binary_print(result);


    return 0;
}