//FormAI DATASET v1.0 Category: Color Code Converter ; Style: modular
#include <stdio.h>

// Function to convert RGB color code to hexadecimal
int rgbToHex(int red, int green, int blue) {
    int hexColor = (red << 16) + (green << 8) + blue;
    return hexColor;
}

// Function to convert hexadecimal color code to RGB
void hexToRgb(int hexColor, int *red, int *green, int *blue) {
    *red = (hexColor >> 16) & 0xFF;
    *green = (hexColor >> 8) & 0xFF;
    *blue = hexColor & 0xFF;
}

int main() {
    int red, green, blue, hexColor;
    printf("Enter RGB color code (comma-separated): ");
    scanf("%d,%d,%d", &red, &green, &blue);
    
    // Convert RGB to hexadecimal
    hexColor = rgbToHex(red, green, blue);
    printf("Hexadecimal color code: #%06X\n", hexColor);
    
    // Convert hexadecimal to RGB
    hexToRgb(hexColor, &red, &green, &blue);
    printf("RGB color code: (%d,%d,%d)\n", red, green, blue);
    
    return 0;
}