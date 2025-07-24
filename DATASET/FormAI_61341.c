//FormAI DATASET v1.0 Category: Color Code Converter ; Style: modular
#include <stdio.h>

void rgbToHex(int red, int green, int blue);
void hexToRgb(char hex[]);

int main() {
    int red, green, blue;
    char hex[7];

    printf("Enter RGB values (comma-separated): ");
    scanf("%d,%d,%d", &red, &green, &blue);
    rgbToHex(red, green, blue);

    printf("Enter hexadecimal color code: ");
    scanf("%s", hex);
    hexToRgb(hex);

    return 0;
}

void rgbToHex(int red, int green, int blue) {
    char hex[7];
    sprintf(hex, "#%02X%02X%02X", red, green, blue);
    printf("Hexadecimal color code: %s\n", hex);
}

void hexToRgb(char hex[]) {
    int red, green, blue;
    sscanf(hex, "#%02X%02X%02X", &red, &green, &blue);
    printf("RGB values: %d, %d, %d\n", red, green, blue);
}