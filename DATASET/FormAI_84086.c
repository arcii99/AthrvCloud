//FormAI DATASET v1.0 Category: Binary Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char binary[100], decimal[100];
    int input, i = 0, j, rem, quotient;

    printf("Enter a decimal number: ");
    scanf("%d", &input);

    quotient = input;
    while(quotient != 0)
    {
        rem = quotient % 2;
        binary[i++] = rem + '0';
        quotient = quotient / 2;
    }
    binary[i] = '\0';

    printf("Binary number is: ");
    for(j = strlen(binary)-1; j >= 0; j--)
    {
        printf("%c", binary[j]);
    }
    printf("\n");

    return 0;
}