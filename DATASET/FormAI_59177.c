//FormAI DATASET v1.0 Category: Binary Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int decimal_number = 0;
    int binary_number[32];
    int i = 0;

    printf("Enter decimal number: ");
    scanf("%u", &decimal_number);

    while(decimal_number > 0)
    {
        binary_number[i] = decimal_number % 2;
        decimal_number = decimal_number / 2;
        i++;
    }

    printf("The binary equivalent is: ");
    for(int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary_number[j]);
    }
    printf("\n");
    return 0;
}