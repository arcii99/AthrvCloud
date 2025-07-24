//FormAI DATASET v1.0 Category: Binary Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* function to convert binary to decimal */
int binaryToDecimal(char *binary)
{
    int decimal = 0;
    int len = strlen(binary);
    for (int i = 0; i < len; i++)
    {
        if (binary[i] == '1')
        {
            decimal += pow(2, len - i - 1);
        }
    }
    return decimal;
}

/* function to convert decimal to binary */
void decimalToBinary(int decimal)
{
    int binary[32];
    int i = 0;
    while (decimal > 0)
    {
        binary[i++] = decimal % 2;
        decimal /= 2;
    }
    printf("Binary: ");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
    }
    printf("\n");
}

/* main function */
int main()
{
    char binary[32];
    printf("Enter a binary number: ");
    scanf("%s", binary);
    int decimal = binaryToDecimal(binary);
    printf("Decimal: %d\n", decimal);
    decimalToBinary(decimal);
    return 0;
}