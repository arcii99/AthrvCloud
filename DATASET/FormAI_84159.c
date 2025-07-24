//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: authentic
#include<stdio.h>

void main()
{
    int bin, dec = 0, rem, i = 1, temp;
    char hex[20];

    printf("Enter the binary number: ");
    scanf("%d", &bin);

    temp = bin;

    // Converting binary to decimal
    while (bin != 0)
    {
        rem = bin % 10;
        dec = dec + rem * i;
        i = i * 2;
        bin = bin / 10;
    }

    // Converting decimal to hexadecimal
    i = 0;
    while (dec != 0)
    {
        rem = dec % 16;
        if (rem < 10)
            hex[i++] = rem + 48;
        else
            hex[i++] = rem + 55;
        dec = dec / 16;
    }
    printf("The hexadecimal equivalent of %d is: ", temp);
    for (i = i - 1; i >= 0; i--)
        printf("%c", hex[i]);
}