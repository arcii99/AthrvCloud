//FormAI DATASET v1.0 Category: Color Code Converter ; Style: retro
#include <stdio.h>

int main() {
    printf("Welcome to the Retro Color Converter!\n\n");

    int hexColor;
    char rgbColor[6];

    printf("Enter a 6-digit hexadecimal code: ");
    scanf("%x", &hexColor);

    sprintf(rgbColor, "%02X%02X%02X", ((hexColor >> 16) & 0xFF), ((hexColor >> 8) & 0xFF), (hexColor & 0xFF));

    printf("\nRGB Color Code: #%s\n\n", rgbColor);

    int red, green, blue;

    printf("Enter RGB color code (comma-separated): ");
    scanf("%d,%d,%d", &red, &green, &blue);

    hexColor = (red << 16) + (green << 8) + blue;

    printf("\nHexadecimal Color Code: #%06X\n\n", hexColor);

    return 0;
}