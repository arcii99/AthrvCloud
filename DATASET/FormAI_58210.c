//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program takes an input decimal number and converts it to hexadecimal display */

int main()
{
    int num;

    printf("Welcome to the C Hexadecimal Converter\n");
    printf("Enter a decimal number to convert: ");
    scanf("%d", &num);
    printf("\n");

    char hex[20]; // Array for storing hex digits
    int i = 0; // Counter for hex array

    while(num != 0)
    {
        int remainder = num % 16;

        if(remainder < 10)
        {
            hex[i] = remainder + 48; // Convert digit to ASCII code
        }
        else
        {
            hex[i] = remainder + 55; // Convert number to letter in ASCII code
        }

        i++;
        num = num / 16;
    }

    /* Reverse the order of the hex digits */
    int j;
    for(j = 0; j < i / 2; j++)
    {
        char temp = hex[j];
        hex[j] = hex[i - j - 1];
        hex[i - j - 1] = temp;
    }

    printf("The hexadecimal representation of %d is: 0x%s\n", num, hex);

    return 0;
}