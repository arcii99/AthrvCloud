//FormAI DATASET v1.0 Category: Color Code Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main() {
    int red, green, blue;

    printf("Enter the values of red, green and blue separated by spaces: ");
    scanf("%d %d %d", &red, &green, &blue);

    // Conversion from RGB to HEX
    int hexValue = (red << 16) + (green << 8) + blue;

    printf("The HEX code for the RGB value is: %06X\n", hexValue);

    // Conversion from HEX to RGB
    int r = (hexValue >> 16) & 0xFF;
    int g = (hexValue >> 8) & 0xFF;
    int b = hexValue & 0xFF;

    printf("The RGB values for the HEX code are: %d %d %d\n", r, g, b);

    return 0;
}