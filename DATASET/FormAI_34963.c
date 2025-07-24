//FormAI DATASET v1.0 Category: Color Code Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Function to convert hex color code to RGB color values
void hexToRGB(char hex[], int *red, int *green, int *blue) {
    // Convert hex code to decimal values
    int r = 0, g = 0, b = 0;
    sscanf(hex, "%02x%02x%02x", &r, &g, &b);
    
    // Store decimal values in pointers
    *red = r;
    *green = g;
    *blue = b;
}

// Function to convert RGB color values to hex color code
void RGBToHex(int red, int green, int blue, char hex[]) {
    // Convert decimal values to hex code
    sprintf(hex, "%02x%02x%02x", red, green, blue);
}

int main() {
    // User input: hex color code
    char hexCode[7];
    printf("Enter a hex color code (e.g. FFFFFF): ");
    scanf("%s", hexCode);
    
    // Convert hex color code to RGB
    int red, green, blue;
    hexToRGB(hexCode, &red, &green, &blue);
    
    // Output RGB values
    printf("RGB values: R=%d, G=%d, B=%d\n", red, green, blue);
    
    // Convert RGB to hex color code
    char hex[7];
    RGBToHex(red, green, blue, hex);
    
    // Output hex color code
    printf("Hex color code: #%s\n", hex);

    return 0;
}