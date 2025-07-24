//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: excited
#include <stdio.h>

int main()
{
    printf("Welcome to the Exciting World of Hexadecimal Conversion!\n");

    int num;
    char hex[50];
    int i = 0;

    printf("Enter a decimal number: ");

    scanf("%d", &num);

    printf("\nConverting decimal number %d to hexadecimal...\n\n", num);

    while (num != 0)
    {
        int rem = num % 16;

        if (rem < 10)
        {
            hex[i] = rem + 48;
            i++;
        }
        else
        {
            hex[i] = rem + 55;
            i++;
        }

        num /= 16;
    }

    printf("The hexadecimal equivalent of the decimal number is: \n");

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", hex[j]);
    }

    printf("\n\nConversion Successful!!\n");

    return 0;
}