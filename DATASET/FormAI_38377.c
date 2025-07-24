//FormAI DATASET v1.0 Category: Color Code Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Structure for Color RGB Values
typedef struct {
    int red;
    int green;
    int blue;
} ColorRGB;

// Define Structure for Color Hex Values
typedef struct {
    char hex[7];
} ColorHex;

// Function to Convert Color RGB to Hex
void rgbToHex(ColorRGB *color, ColorHex *hex) {
    sprintf(hex->hex, "#%02X%02X%02X", color->red, color->green, color->blue);
}

// Function to Convert Color Hex to RGB
void hexToRgb(ColorHex *hex, ColorRGB *color) {
    sscanf(hex->hex, "#%02X%02X%02X", &color->red, &color->green, &color->blue);
}

int main() {
    char input[10];
    ColorRGB colorRGB;
    ColorHex colorHex;

    printf("Enter C for converting from RGB to Hex or H for converting from Hex to RGB: ");
    fgets(input, sizeof(input), stdin);

    if(input[0] == 'C' || input[0] == 'c') {
        printf("Enter RGB Values (e.g 255,255,255): ");
        scanf("%d,%d,%d", &colorRGB.red, &colorRGB.green, &colorRGB.blue);

        // Convert from RGB to Hex
        rgbToHex(&colorRGB, &colorHex);
        printf("Hex Value: %s\n", colorHex.hex);
    } else if (input[0] == 'H' || input[0] == 'h') {
        printf("Enter Hex Value (e.g #FFFFFF): ");
        scanf("%s", &colorHex.hex);

        // Convert from Hex to RGB
        hexToRgb(&colorHex, &colorRGB);
        printf("RGB Value: %d,%d,%d\n", colorRGB.red, colorRGB.green, colorRGB.blue);
    } else {
        printf("Invalid input.\n");
    }

    return 0;
}