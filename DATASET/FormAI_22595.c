//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: portable
#include <stdio.h>

// function to convert decimal number to hexadecimal
void decToHex(int decimalNumber)
{
    int quotient = decimalNumber;
    int remainder = 0;
    int i = 0;
    char hexadecimal[20];

    while (quotient != 0)
    {
        remainder = quotient % 16;

        if (remainder < 10)
            hexadecimal[i] = remainder + 48;
        else
            hexadecimal[i] = remainder + 55;

        quotient = quotient / 16;
        i++;
    }

    printf("Hexadecimal number of %d is: ", decimalNumber);

    for (int j = i - 1; j >= 0; j--)
        printf("%c", hexadecimal[j]);

    printf("\n");
}

// main function
int main()
{
    int decimalNumber;
    printf("Enter the decimal number you want to convert to hexadecimal: ");
    scanf("%d", &decimalNumber);

    decToHex(decimalNumber);

    return 0;
}