//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: beginner-friendly
#include<stdio.h>

int main()
{
    int decimal, remainder, i=1, j, quotient;
    char hexadecimalvalue[20];

    printf("Enter decimal number: ");
    scanf("%d", &decimal);

    quotient = decimal;

    while(quotient != 0)
    {
        remainder = quotient % 16;

        if(remainder < 10)
        {
            hexadecimalvalue[i++] = 48 + remainder;
        }
        else
        {
            hexadecimalvalue[i++] = 55 + remainder;
        }

        quotient = quotient / 16;
    }

    printf("Hexadecimal value of %d is: ", decimal);
    for(j = i; j > 0; j--)
    {
        printf("%c", hexadecimalvalue[j]);
    }

    return 0;
}