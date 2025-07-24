//FormAI DATASET v1.0 Category: Color Code Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Function to convert RGB to HEX color code
char* RGBtoHEX(int r, int g, int b)
{
    char* hex = (char*)malloc(sizeof(char) * 7);
    sprintf(hex, "#%02X%02X%02X", r, g, b);
    return hex;
}

// Function to convert HEX to RGB color code
void HEXtoRGB(char* hex, int* r, int* g, int* b)
{
    if (hex[0] == '#') hex++;

    if (strlen(hex) == 6)
    {
        sscanf(hex, "%02x%02x%02x", r, g, b);
    }
}

// Main function to demonstrate the use of the color code converter
int main()
{
    printf("Color Code Converter\n");

    // Converting RGB to HEX
    int r = 255, g = 255, b = 255;
    char* hex = RGBtoHEX(r, g, b);
    printf("RGB (%d, %d, %d) --> HEX %s\n", r, g, b, hex);
    free(hex);

    // Converting HEX to RGB
    char* hexCode = "#FF69B4";
    int red = 0, green = 0, blue = 0;
    HEXtoRGB(hexCode, &red, &green, &blue);
    printf("HEX %s --> RGB (%d, %d, %d)\n", hexCode, red, green, blue);

    return 0;
}