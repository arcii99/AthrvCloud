//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: inquisitive
#include <stdio.h>

int main()
{
    int decimal, remainder, i = 0;
    char hexadecimal[100];

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    while(decimal != 0)
    {
        remainder = decimal % 16;

        if(remainder < 10)
        {
            hexadecimal[i] = remainder + 48; 
        }
        else
        {
            hexadecimal[i] = remainder + 55; 
        }

        i++;
        decimal /= 16;
    }

    printf("Hexadecimal number is: ");

    for(int j = i - 1; j >= 0; j--)
    {
        printf("%c", hexadecimal[j]);
    }

    return 0;
}