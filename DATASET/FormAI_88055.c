//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int decimal, i = 1, j, remainder;
    char hexadecimal[20];

    printf("Enter a decimal number to convert to hexadecimal: ");
    scanf("%d", &decimal);

    while (decimal != 0)
    {
        remainder = decimal % 16;
        if (remainder < 10)
            hexadecimal[i++] = 48 + remainder;
        else
            hexadecimal[i++] = 55 + remainder;
        decimal /= 16;
    }

    printf("The hexadecimal equivalent is: ");

    for (j = i; j > 0; j--)
        printf("%c", hexadecimal[j]);

    return 0;
}