//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: puzzling
#include <stdio.h>

void decimal_to_hexadecimal(int decimal_number)
{
    char hexadecimal_number[100];
    int i = 0;

    while (decimal_number != 0)
    {
        int remainder = decimal_number % 16;

        if (remainder < 10)
            hexadecimal_number[i++] = 48 + remainder;
        else
            hexadecimal_number[i++] = 55 + remainder;

        decimal_number /= 16;
    }

    printf("The hexadecimal value is: ");

    for (int j = i - 1; j >= 0; j--)
        printf("%c", hexadecimal_number[j]);
}

int main()
{
    int decimal_number;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal_number);

    decimal_to_hexadecimal(decimal_number);
    
    return 0;
}