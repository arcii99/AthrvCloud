//FormAI DATASET v1.0 Category: Binary Converter ; Style: Donald Knuth
/* C Program to Convert Decimal to Binary */

#include <stdio.h>

int main()
{
    int decimalnum, remainder, quotient, i=0, j;
    char binarynum[100];

    printf("Enter decimal number: ");
    scanf("%d", &decimalnum);

    quotient = decimalnum;

    while (quotient != 0)
    {
        binarynum[i++] = quotient % 2 + '0';
        quotient = quotient / 2;
    }

    printf("Equivalent binary value of decimal number %d: ", decimalnum);
    for (j = i - 1; j >= 0; j--)
        printf("%c", binarynum[j]);

    return 0;
}

/* Donald Knuth's Binary Converter Example Program */