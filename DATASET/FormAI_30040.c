//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Sherlock Holmes
#include <stdio.h>

int main()
{
    int red, green, blue, hex;

    printf("Enter the RGB values (0-255):\n");
    printf("Red: ");
    scanf("%d", &red);
    printf("Green: ");
    scanf("%d", &green);
    printf("Blue: ");
    scanf("%d", &blue);

    // Convert RGB to HEX
    hex = (red << 16) | (green << 8) | blue;

    printf("\nHEX code: #%06X\n", hex);

    // Convert HEX to RGB
    printf("\nEnter the HEX code (use format #RRGGBB):\n");
    scanf("#%06X", &hex);

    red = (hex >> 16) & 0xFF;
    green = (hex >> 8) & 0xFF;
    blue = hex & 0xFF;

    printf("\nRGB values: %d, %d, %d\n", red, green, blue);

    return 0;
}