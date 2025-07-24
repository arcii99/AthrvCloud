//FormAI DATASET v1.0 Category: Binary Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void to_binary(int decimal_number);

int main()
{
    char input[20];

    printf("Enter a decimal number: ");
    fgets(input, 20, stdin);

    int decimal_number = atoi(input);

    if (decimal_number < 0)
    {
        printf("Invalid number entered. Please enter a positive decimal number.\n");
        exit(1);
    }

    printf("The binary representation of %d is: ", decimal_number);
    to_binary(decimal_number);

    printf("\n");

    return 0;
}

void to_binary(int decimal_number)
{
    char binary[65];
    int index = 0;

    while (decimal_number > 0)
    {
        binary[index++] = (decimal_number % 2) + '0';
        decimal_number /= 2;
    }

    for (int i = index - 1; i >= 0; i--)
    {
        printf("%c", binary[i]);
    }
}