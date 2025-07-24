//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: expert-level
#include <stdio.h>

// function to convert decimal to hexadecimal
char* decimalToHexadecimal(int decimal)
{
    int quotient, remainder;
    int i, j = 0;
    char* hexadecimal = (char*) malloc(sizeof(char) * 32);

    quotient = decimal;
    while (quotient)
    {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimal[j++] = 48 + remainder;
        else
            hexadecimal[j++] = 55 + remainder; 

        quotient = quotient / 16;
    }

    if (j == 0)
        hexadecimal[j++] = '0';

    reverseString(hexadecimal, j);

    hexadecimal[j] = '\0'; 

    return hexadecimal;
}

// function to convert hexadecimal to decimal
int hexadecimalToDecimal(char* hexadecimal)
{
    int decimal = 0;
    int i;

    for (i = 0; hexadecimal[i]; i++)
    {
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9')
            decimal = decimal * 16 + hexadecimal[i] - '0';
        else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F')
            decimal = decimal * 16 + hexadecimal[i] - 'A' + 10;
        else if (hexadecimal[i] >= 'a' && hexadecimal[i] <= 'f')
            decimal = decimal * 16 + hexadecimal[i] - 'a' + 10;
    }

    return decimal;
}

int main()
{
    int decimalNumber;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    printf("Hexadecimal of %d is %s\n", decimalNumber, decimalToHexadecimal(decimalNumber));

    char hexadecimal[32];

    printf("Enter a hexadecimal number: ");
    scanf("%s", hexadecimal);

    printf("Decimal of %s is %d\n", hexadecimal, hexadecimalToDecimal(hexadecimal));

    return 0;
}

// function to reverse a string
void reverseString(char* string, int length)
{
    int start = 0;
    int end = length - 1;
    char temp;

    while (start < end)
    {
        temp = string[start];
        string[start] = string[end];
        string[end] = temp;
        start++;
        end--;
    }
}