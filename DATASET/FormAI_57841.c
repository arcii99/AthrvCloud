//FormAI DATASET v1.0 Category: Color Code Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* hex_to_rgb(char*);
char* rgb_to_hex(char*);

int main() {
    char hex[7];
    char rgb[12];

    printf("Enter a hex color code (with #): ");
    scanf("%s", hex);

    char* rgb_code = hex_to_rgb(hex);
    printf("RGB color code: %s\n", rgb_code);
    free(rgb_code);

    printf("Enter an RGB color code (with commas): ");
    scanf("%s", rgb);

    char* hex_code = rgb_to_hex(rgb);
    printf("Hex color code: %s\n", hex_code);
    free(hex_code);

    return 0;
}

char* hex_to_rgb(char* hex) {
    char* rgb = malloc(sizeof(char) * 12);
    int r, g, b;
    sscanf(hex, "#%02x%02x%02x", &r, &g, &b);
    sprintf(rgb, "%d,%d,%d", r, g, b);
    return rgb;
}

char* rgb_to_hex(char* rgb) {
    char* hex = malloc(sizeof(char) * 7);
    int r, g, b;
    sscanf(rgb, "%d,%d,%d", &r, &g, &b);
    sprintf(hex, "#%02x%02x%02x", r, g, b);
    return hex;
}