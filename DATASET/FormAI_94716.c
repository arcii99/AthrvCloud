//FormAI DATASET v1.0 Category: Binary Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

char* binary_converter(int decimal)
{
    int remainder, quotient;
    char* binary = (char*)malloc(sizeof(char) * 100);
    int i = 0;

    while(decimal != 0)
    {
        quotient = decimal / 2;
        remainder = decimal % 2;
        binary[i++] = remainder + '0';
        decimal = quotient;
    }

    binary[i] = '\0';
    return binary;
}

int main()
{
    int decimal;
    char* binary;

    printf("Welcome to the medieval binary converter!\n");
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    binary = binary_converter(decimal);

    printf("\nAh, I see that %d in decimal is %s in binary.\n", decimal, binary);

    free(binary);

    return 0;
}