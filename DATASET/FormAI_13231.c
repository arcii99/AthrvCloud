//FormAI DATASET v1.0 Category: Binary Converter ; Style: Alan Touring
#include <stdio.h>

void toBinary(int decimal); // function prototype

int main()
{
    int decimal;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    printf("The binary equivalent is: ");
    toBinary(decimal);

    printf("\n");

    return 0;
}

void toBinary(int decimal)
{
    int binary[32], index = 0;

    // convert decimal to binary
    while(decimal > 0)
    {
        binary[index] = decimal % 2;
        decimal /= 2;
        index++;
    }

    // print binary number in reverse order
    for(int i = index - 1; i >= 0; i--)
    {
        printf("%d", binary[i]);
    }
}