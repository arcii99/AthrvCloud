//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_hex(char hex_num[], int len)
{
    printf("Hexadecimal value: ");
    for (int i = 0; i < len; i++)
    {
        printf("%c", hex_num[i]);
    }
    printf("\n");
}

int main()
{
    char hex_num[10];
    int decimal_num, remainder;
    int i = 0, j = 0;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);
    printf("Decimal value: %d\n", decimal_num);
    while (decimal_num > 0)
    {
        remainder = decimal_num % 16;
        if (remainder < 10)
        {
            hex_num[i] = remainder + 48;
            i++;
        }
        else
        {
            hex_num[i] = remainder + 55;
            i++;
        }
        decimal_num = decimal_num / 16;
    }
    hex_num[i] = '\0';
    int len = strlen(hex_num);
    char hex_num_reverse[10];
    for (int k = len - 1; k >= 0; k--)
    {
        hex_num_reverse[j] = hex_num[k];
        j++;
    }
    hex_num_reverse[j] = '\0';
    print_hex(hex_num_reverse, len);
    return 0;
}