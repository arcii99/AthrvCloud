//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: grateful
#include <stdio.h>

int main()
{
    int dec, rem, i = 0;
    char hex[50];

    printf("Enter a decimal number: ");
    scanf("%d", &dec);

    while (dec > 0)
    {
        rem = dec % 16;

        if (rem < 10)
        {
            hex[i] = rem + 48;
        }
        else
        {
            hex[i] = rem + 55;
        }

        dec = dec / 16;
        i++;
    }

    printf("Hexadecimal value: ");

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", hex[j]);
    }

    printf("\n");

    return 0;
}