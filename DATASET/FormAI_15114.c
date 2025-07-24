//FormAI DATASET v1.0 Category: Binary Converter ; Style: safe
#include <stdio.h>
#include <string.h>

#define MAX_BITS 32

unsigned int input_decimal()
{
    unsigned int decimal;
    printf("Enter a decimal number: ");
    scanf("%u", &decimal);
    return decimal;
}

void to_binary(unsigned int decimal, char *binary)
{
    int i;
    for (i = 0; i < MAX_BITS; i++)
    {
        binary[i] = '0';
    }
    i = MAX_BITS - 1;
    while (decimal > 0)
    {
        if (decimal % 2 == 0)
        {
            binary[i] = '0';
        }
        else
        {
            binary[i] = '1';
        }
        decimal = decimal / 2;
        i--;
    }
}

int main()
{
    unsigned int decimal;
    char binary[MAX_BITS + 1];

    decimal = input_decimal();
    to_binary(decimal, binary);

    printf("Decimal: %u\n", decimal);
    printf("Binary: %s\n", binary);

    return 0;
}