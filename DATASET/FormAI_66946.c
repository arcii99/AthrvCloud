//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

void hex_converter(int num)
{
    int i, j, digit;
    char hex[100];
    i = 0;
    while (num > 0)
    {
        digit = num % 16;
        if (digit < 10)
        {
            hex[i++] = digit + 48;
        }
        else
        {
            hex[i++] = digit + 55;
        }
        num /= 16;
    }
    printf("The hexadecimal value of the given number is: ");
    for (j = i - 1; j >= 0; j--)
    {
        printf("%c", hex[j]);
    }
}

int main()
{
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    hex_converter(num);
    return 0;
}