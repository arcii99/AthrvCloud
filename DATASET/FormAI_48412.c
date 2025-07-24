//FormAI DATASET v1.0 Category: Color Code Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

typedef struct Color {
    int red, green, blue;
} Color;

Color hexToRGB(char hex[]) {
    Color rgb;
    int r, g, b;
    sscanf(hex, "%02x%02x%02x", &r, &g, &b);
    rgb.red = r;
    rgb.green = g;
    rgb.blue = b;
    return rgb;
}

char* RGBToHex(Color rgb) {
    char* hex = malloc(sizeof(char) * 7);
    sprintf(hex, "#%02x%02x%02x", rgb.red, rgb.green, rgb.blue);
    return hex;
}

int main() {
    char hex[7];
    printf("Enter a hex color code: ");
    scanf("%s", hex);
    Color rgb = hexToRGB(hex);
    printf("RGB color: (%d, %d, %d)\n", rgb.red, rgb.green, rgb.blue);
    printf("Hex color: %s\n", RGBToHex(rgb));
    free(RGBToHex(rgb));
    return 0;
}