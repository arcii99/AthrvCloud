//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: safe
#include <stdio.h>
#include <string.h>
#include <math.h>

int hex_to_decimal(char hex[]);

int main()
{
    char hex[20];
    int decimal;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    decimal = hex_to_decimal(hex);

    printf("Decimal equivalent of %s is %d", hex, decimal);
    return 0;
}

int hex_to_decimal(char hex[])
{
    int i, len, decimal = 0, val;

    len = strlen(hex);

    for(i=0; hex[i]!='\0'; i++)
    {
        len--;
        if(hex[i]>='0' && hex[i]<='9')
        {
            val = hex[i] - 48;
        }
        else if(hex[i]>='a' && hex[i]<='f')
        {
            val = hex[i] - 97 + 10;
        }
        else if(hex[i]>='A' && hex[i]<='F')
        {
            val = hex[i] - 65 + 10;
        }

        decimal += val * pow(16, len);
    }
    return decimal;
}