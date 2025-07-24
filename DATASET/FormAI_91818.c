//FormAI DATASET v1.0 Category: Color Code Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hex_to_rgb(char hex[], int *r, int *g, int *b) {
    // Convert hex string to integer
    int hex_value = (int) strtol(hex+1, NULL, 16);

    // Extract R, G and B values from the integer
    *r = (hex_value & 0xff0000) >> 16;
    *g = (hex_value & 0x00ff00) >> 8;
    *b = (hex_value & 0x0000ff);
}

void rgb_to_hex(int r, int g, int b, char hex[]) {
    // Convert R, G and B values to hex string
    snprintf(hex, 7, "#%02x%02x%02x", r, g, b);
}

int main() {
    char input[10];

    printf("Enter a color code in hex format: #");
    scanf("%s", input);

    // Check if the input is valid hex code
    if(strlen(input) != 6) {
        printf("Invalid hex code. Please enter a valid hex code.\n");
        return 1;
    }

    // Convert hex code to RGB values
    int r, g, b;
    hex_to_rgb(input, &r, &g, &b);

    // Print RGB values
    printf("R: %d, G: %d, B: %d\n", r, g, b);

    // Convert RGB values to hex code
    char hex[7];
    rgb_to_hex(r, g, b, hex);

    // Print hex code
    printf("Hex code: %s\n", hex);

    return 0;
}