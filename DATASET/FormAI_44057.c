//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

void decimal_to_hexadecimal(int decimal_number);

int main()
{
    int decimal_number; 
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_number);
    printf("\nHexadecimal equivalent: ");
    decimal_to_hexadecimal(decimal_number);
    return 0;
}

void decimal_to_hexadecimal(int decimal_number)
{
    int remainder;
    char hex[100];
    int index = 0;

    while(decimal_number>0)
    {
        remainder = decimal_number % 16;
        if(remainder<10)
            hex[index++] = 48 + remainder;
        else
            hex[index++] = 55 + remainder;
        decimal_number = decimal_number / 16;
    }
    for(int i=index-1; i>=0; i--)
    {
        printf("%c", hex[i]);
    }
}