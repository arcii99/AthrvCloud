//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int decimalNumber, remainder, quotient;
    int i = 1, j, temp;
    char hexadecimalNumber[100];

    printf("Enter decimal number: ");
    scanf("%ld", &decimalNumber);

    quotient = decimalNumber;

    while (quotient != 0)
    {
        temp = quotient % 16;

        if (temp < 10)
        {
            temp = temp + 48;
        }
        else
        {
            temp = temp + 55;
        }

        hexadecimalNumber[i++] = temp;
        quotient = quotient / 16;
    }

    printf("The hexadecimal number is: ");

    for (j = i - 1; j > 0; j--)
    {
        printf("%c", hexadecimalNumber[j]);
    }

    return 0;
}