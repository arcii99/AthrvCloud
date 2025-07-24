//FormAI DATASET v1.0 Category: Binary Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decToBin(int decimal)
{
    int binary[1000], index = 0;

    // convert decimal to binary
    while (decimal > 0)
    {
        binary[index] = decimal % 2;
        decimal = decimal / 2;
        index++;
    }

    // print binary equivalent
    printf("\nBinary equivalent: ");
    for (int i = index - 1; i >= 0; i--)
    {
        printf("%d", binary[i]);
    }
}

int main()
{
    int decimal;

    printf("Retro C Binary Converter\n");

    // get decimal input from user
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // check if input is valid
    if (decimal < 0)
    {
        printf("Invalid input, please enter a positive integer.\n");
        return 0;
    }

    // call conversion function
    decToBin(decimal);

    printf("\nThanks for using Retro C Binary Converter!");

    return 0;
}