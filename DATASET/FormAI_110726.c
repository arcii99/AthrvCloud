//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void convert(char hex_num[]);

int main()
{
    char hex_num[10];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_num);

    convert(hex_num);

    return 0;
}

void convert(char hex_num[])
{
    int decimal_num = 0, base = 1;
    int i = 0;
    while (hex_num[i])
    {
        if (hex_num[i] >= '0' && hex_num[i] <= '9')
        {
            decimal_num += (hex_num[i] - '0') * base;
            base *= 16;
        }
        else if (hex_num[i] >= 'A' && hex_num[i] <= 'F')
        {
            decimal_num += (hex_num[i] - 55) * base;
            base *= 16;
        }
        else if (hex_num[i] >= 'a' && hex_num[i] <= 'f')
        {
            decimal_num += (hex_num[i] - 87) * base;
            base *= 16;
        }
        else
        {
            printf("Invalid hexadecimal number");
            exit(0);
        }
        i++;
    }
    printf("Decimal number is: %d", decimal_num);
}