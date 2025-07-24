//FormAI DATASET v1.0 Category: Color Code Converter ; Style: recursive
#include <stdio.h>

// Recursive function to calculate the hexadecimal value of a single digit
int getHexValue(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    else if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    else
        return -1;
}

// Recursive function to calculate the decimal value of a hexadecimal string
int hexToDec(char hex[], int size)
{
    if (size == 0) // base condition
        return 0;

    int value = getHexValue(hex[size - 1]);
    if (value == -1) // invalid character
        return -1;

    return value + 16 * hexToDec(hex, size - 1);
}

int main()
{
    char hexColor[7];
    printf("Enter a hexadecimal color code: ");
    scanf("%s", hexColor);

    int red = hexToDec(hexColor, 2);
    int green = hexToDec(hexColor + 2, 2);
    int blue = hexToDec(hexColor + 4, 2);

    if (red == -1 || green == -1 || blue == -1) // invalid input
    {
        printf("Invalid hexadecimal color code");
        return 1;
    }

    printf("RGB color values: (%d, %d, %d)\n", red, green, blue);

    return 0;
}