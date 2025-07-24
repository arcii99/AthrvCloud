//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToHex(int decimal)
{
    int rem, i = 0;
    char hexadecimal[20];
    while(decimal != 0)
    {
        rem = decimal % 16;
        if(rem < 10)
            hexadecimal[i] = rem + 48;
        else
            hexadecimal[i] = rem + 55;
        i++;
        decimal /= 16;
    }
    printf("The hexadecimal equivalent is: ");
    for(int j = i - 1; j >= 0; j--)
        printf("%c", hexadecimal[j]);
}

int main()
{
    printf("*******Futuristic Hexadecimal Converter********\n\n");
    printf("Enter a decimal number to be converted: ");
    int decimal;
    scanf("%d", &decimal);

    printf("\nLoading conversion algorithm...\n");
    // some futuristic animation here

    printf("\nStarting quantum calculation for conversion...\n");
    // some futuristic quantum computing animation here

    printf("\nConversion completed in 2 seconds. \n\n");
    printf("Decimal number %d has been converted to: \n", decimal);
    convertToHex(decimal);

    printf("\n\nThank you for using our Futuristic Hexadecimal Converter!");
    // some futuristic goodbye message here
    return 0;
}