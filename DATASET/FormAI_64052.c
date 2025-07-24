//FormAI DATASET v1.0 Category: Binary Converter ; Style: decentralized
#include <stdio.h>
#include <string.h>

// define function for binary conversion
int decimalToBinary(int decimal)
{
    int binary = 0, i = 1;
    while(decimal != 0)
    {
        binary += (decimal % 2) * i;
        decimal /= 2;
        i *= 10;
    }
    return binary;
}

int main()
{
    // declare variables
    int decimal, binary;
    char input[100];

    // get input from user
    printf("Enter a decimal number to convert to binary: ");
    fgets(input, 100, stdin);

    // remove trailing newline character
    input[strcspn(input, "\n")] = 0;

    // convert input to integer
    sscanf(input, "%d", &decimal);

    // call binary conversion function
    binary = decimalToBinary(decimal);

    // print result
    printf("%d in decimal is %d in binary.\n", decimal, binary);

    return 0;
}