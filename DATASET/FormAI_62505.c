//FormAI DATASET v1.0 Category: Color Code Converter ; Style: realistic
#include <stdio.h>

void hex_to_rgb(char hex[], int *r, int *g, int *b) {
    sscanf(hex, "%02x%02x%02x", r, g, b);
}

void rgb_to_hex(int r, int g, int b, char hex[]) {
    sprintf(hex, "#%02X%02X%02X", r, g, b);
}

int main() {
    char hex[] = "#00FF00";
    int r, g, b;
    hex_to_rgb(hex, &r, &g, &b);
    printf("Hex: %s\nRGB: (%d,%d,%d)\n", hex, r, g, b);

    r = 255; g = 0; b = 0;
    char hex_result[7];
    rgb_to_hex(r, g, b, hex_result);
    printf("RGB: (%d,%d,%d)\nHex: %s\n", r, g, b, hex_result);

    return 0;
}