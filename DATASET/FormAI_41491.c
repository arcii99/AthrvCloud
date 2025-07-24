//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char hex[17], chr;
    int num, i, length;

    printf("Welcome to the Hexadecimal Converter Program!\n");
    printf("Enter a hexadecimal number:\n");
    scanf("%s", hex);

    length = strlen(hex);
    num = 0;

    for(i = 0; hex[i] != '\0'; i++)
    {
        chr = hex[i];

        if(chr >= '0' && chr <= '9')
        {
            num = num * 16 + (chr - '0');
        }
        else if(chr >= 'a' && chr<= 'f')
        {
            num = num * 16 + (chr - 'a' + 10);
        }
        else if(chr >= 'A' && chr<= 'F')
        {
            num = num * 16 + (chr - 'A' + 10);
        }
        else
        {
            printf("Invalid input!\n");
            exit(0);
        }
    }

    printf("The decimal equivalent of %s is %d.\n", hex, num);
    printf("Surprise! The binary equivalent of %d is %ld.\n", num, strtol(hex, NULL, 16));

    return 0;
}