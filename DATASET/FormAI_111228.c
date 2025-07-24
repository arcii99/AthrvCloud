//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: immersive
#include <stdio.h>

int main()
{
    int decimal_num, quotient, remainder;
    int i, j = 0;
    char hex_num[100];

    // taking decimal input from user
    printf("Enter a Decimal Number: ");
    scanf("%d", &decimal_num);

    quotient = decimal_num;

    // converting decimal to hexadecimal
    while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
            hex_num[j++] = 48 + remainder;
        else
            hex_num[j++] = 55 + remainder;
        quotient = quotient / 16;
    }

    // printing hexadecimal equivalent of decimal number
    printf("\n\nHexadecimal Equivalent of %d is: ", decimal_num);
    for (i = j; i >= 0; i--)
            printf("%c", hex_num[i]);

    return 0;
}