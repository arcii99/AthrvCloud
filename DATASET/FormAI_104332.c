//FormAI DATASET v1.0 Category: Color Code Converter ; Style: creative
#include <stdio.h>

// This function converts RGB values into hexadecimal color code
char* RGBtoHex(int red, int green, int blue) {
    char hex[8];
    sprintf(hex, "#%02X%02X%02X", red, green, blue);
    return hex;
}

// This function converts hexadecimal color code into RGB values
void HextoRGB(char* hex, int* red, int* green, int* blue) {
    sscanf(hex, "#%2x%2x%2x", red, green, blue);
}

int main() {
    printf("Enter RGB values (0-255): \n");
    int r, g, b;
    scanf("%d %d %d", &r, &g, &b);

    // Convert RGB to hexadecimal color code
    char* hexCode = RGBtoHex(r, g, b);
    printf("Hexadecimal Color: %s\n", hexCode);

    // Convert hexadecimal color code to RGB
    printf("Enter Hexadecimal Color Code: \n");
    char hex[8];
    scanf("%s", hex);
    int red, green, blue;
    HextoRGB(hex, &red, &green, &blue);
    printf("RGB Color: (%d, %d, %d)\n", red, green, blue);

    return 0;
}