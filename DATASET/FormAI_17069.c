//FormAI DATASET v1.0 Category: Binary Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// iterate through each bit and print in reverse order
void printBinary(unsigned int num)
{
    // base case
    if (num/2 == 0)
    {
        printf("%d", num % 2);
        return;
    }

    // recursive case
    printBinary(num / 2);
    printf("%d", num % 2);
}

int main(int argc, char *argv[])
{
    // check for valid input
    if (argc != 2)
    {
        fprintf(stderr, "Usage: binaryConverter [decimal]\n");
        return 1;
    }

    unsigned int decimal = atoi(argv[1]);

    // check for negative input
    if (decimal < 0)
    {
        fprintf(stderr, "Error: decimal value must be non-negative.\n");
        return 1;
    }

    printf("Binary representation of %u: ", decimal);
    printBinary(decimal);
    printf("\n");

    return 0;
}