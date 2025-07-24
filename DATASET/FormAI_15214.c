//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: realistic
#include <stdio.h>
#include <math.h>

int main()
{
    unsigned int decimal;
    char hex[20];
    int i = 0, rem;

    printf("Enter a decimal number: ");
    scanf("%u", &decimal);

    while(decimal > 0)
    {
        rem = decimal % 16;
        if(rem < 10)
            hex[i++] = rem + 48;
        else
            hex[i++] = rem + 55;

        decimal /= 16;
    }

    printf("The hexadecimal equivalent is: 0x");

    for(int j = i - 1; j >= 0; j--)
        printf("%c", hex[j]);

    return 0;
}