//FormAI DATASET v1.0 Category: Color Code Converter ; Style: artistic
#include <stdio.h>

//Function to convert RGB to hexadecimal color code
void rgb_to_hex(int r, int g, int b)
{
    //Stores the hexadecimal code in a string
    char hex_code[8];
    sprintf(hex_code, "#%02x%02x%02x", r, g, b);

    printf("The hexadecimal color code is: %s\n", hex_code);
}

//Function to convert hexadecimal to RGB color code
void hex_to_rgb(char hex[])
{
    int r, g, b;

    //Parses the hexadecimal code and stores the RGB values
    sscanf(hex, "#%02x%02x%02x", &r, &g, &b);

    printf("The RGB color code is: %d, %d, %d\n", r, g, b);
}

int main()
{
    int r, g, b;
    char hex[8];

    printf("Enter the RGB color code (separated by spaces): ");
    scanf("%d %d %d", &r, &g, &b);

    rgb_to_hex(r, g, b);

    printf("Enter the hexadecimal color code (with the '#' symbol): ");
    scanf("%s", hex);

    hex_to_rgb(hex);

    return 0;
}