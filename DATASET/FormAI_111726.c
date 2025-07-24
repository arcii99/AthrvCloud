//FormAI DATASET v1.0 Category: Binary Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

void binary_converter(int decimal_num);

int main()
{
    int decimal_num;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);
    binary_converter(decimal_num);

    return 0;
}

void binary_converter(int decimal_num)
{
    int binary_num[100];
    int i = 0;

    while (decimal_num>0) 
    {
        binary_num[i] = decimal_num % 2;
        decimal_num = decimal_num / 2;
        i++;
    }

    printf("Binary number: ");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary_num[j]);
    }
}