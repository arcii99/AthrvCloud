//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: ultraprecise
#include <stdio.h>

int main()
{
    int decimal_num, quotient, remainder, i = 1, j, temp;
    char hexadecimal_num[100];

    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);

    quotient = decimal_num;

    while (quotient != 0)
    {
        temp = quotient % 16;

        // To convert integer into character
        if (temp < 10)
        {
            temp += 48;
        }
        else
        {
            temp += 55;
        }

        hexadecimal_num[i++] = temp;
        quotient /= 16;
    }

    printf("Equivalent hexadecimal value of decimal number %d: ", decimal_num);

    for (j = i - 1; j > 0; j--)
    {
        printf("%c", hexadecimal_num[j]);
    }

    return 0;
}