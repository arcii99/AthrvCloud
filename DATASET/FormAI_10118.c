//FormAI DATASET v1.0 Category: Binary Converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

void binary_converter(int number);

int main()
{
    int decimal_number;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal_number);

    binary_converter(decimal_number);

    return 0;
}

void binary_converter(int number)
{
    int binary_array[32]; // max length of 32 bits
    int count = 0;

    while(number > 0)
    {
        binary_array[count] = number % 2;
        number = number / 2;
        count++;
    }

    printf("The binary equivalent is: ");

    for(int i = count - 1; i >= 0; i--)
    {
        printf("%d", binary_array[i]);
    }

    printf("\n");
}