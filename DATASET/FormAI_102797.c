//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>

void decToHex(long int decimalNumber)
{
    char hexadecimalNumber[20];
    int index = 0;
    long int tempDecimalNumber = decimalNumber;

    while(tempDecimalNumber != 0)
    {
        int remainder = tempDecimalNumber % 16;

        if(remainder < 10)
        {
            hexadecimalNumber[index] = 48 + remainder;
            index++;
        }
        else
        {
            hexadecimalNumber[index] = 55 + remainder;
            index++;
        }

        tempDecimalNumber /= 16;
    }

    printf("\nHexadecimal value of decimal number %ld is: ", decimalNumber);
    for(int i = index - 1; i >= 0; i--)
    {
        printf("%c", hexadecimalNumber[i]);
    }
}

int main()
{
    long int decimalNumber;

    printf("Enter a decimal number: ");
    scanf("%ld", &decimalNumber);

    decToHex(decimalNumber);

    return 0;
}