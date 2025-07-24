//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>

//function to convert decimal to hexadecimal
void decToHex(int dec_num, char hex_num[])
{
    int quot, rem, i = 0, j;
    char temp;
    quot = dec_num;
    while (quot != 0)
    {
        rem = quot % 16;
        if (rem < 10)
            hex_num[i++] = rem + 48;
        else
            hex_num[i++] = rem + 55;
        quot = quot / 16;
    }
    //reverse the hexadecimal number
    for (j = 0; j < i / 2; j++)
    {
        temp = hex_num[j];
        hex_num[j] = hex_num[i - j - 1];
        hex_num[i - j - 1] = temp;
    }
    hex_num[i] = '\0';
}

int main()
{
    int dec_num;
    char hex_num[20];
    printf("Enter a decimal number: ");
    scanf("%d", &dec_num);
    decToHex(dec_num, hex_num);
    printf("The hexadecimal representation of %d is: %s", dec_num, hex_num);
    return 0;
}