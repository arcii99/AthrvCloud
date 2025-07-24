//FormAI DATASET v1.0 Category: Color Code Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void hex_to_rgb(char hex[], int* red, int* green, int* blue) {
    // Convert hex string to RGB values
    sscanf(hex, "%02x%02x%02x", red, green, blue);
}

void rgb_to_hex(int red, int green, int blue, char hex[]) {
    // Convert RGB values to hex string
    sprintf(hex, "%02x%02x%02x", red, green, blue);
}

int is_hex(char hex[]) {
    // Check if string is a valid hex code
    int i;
    for (i = 0; i < strlen(hex); i++) {
        if (!isxdigit(hex[i])) return 0;
    }
    return 1;
}

int main() {
    char input[15], output[15];
    int r, g, b;
    printf("Color Code Converter\n");
    printf("--------------------\n");
    printf("Enter a HEX code or RGB values (e.g. #FF0000 or 255,0,0): ");
    fgets(input, 15, stdin);
    // Convert input to uppercase
    int i;
    for (i = 0; i < strlen(input); i++) {
        input[i] = toupper(input[i]);
    }
    if (input[0] == '#') {
        // HEX to RGB conversion
        if (!is_hex(input+1)) {
            printf("Invalid HEX code!\n");
            return 1;
        }
        hex_to_rgb(input+1, &r, &g, &b);
        printf("RGB values: %d,%d,%d\n", r, g, b);
    } else {
        // RGB to HEX conversion
        if (sscanf(input, "%d,%d,%d", &r, &g, &b) < 3) {
            printf("Invalid RGB values!\n");
            return 1;
        }
        if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
            printf("Invalid RGB values!\n");
            return 1;
        }
        rgb_to_hex(r, g, b, output);
        printf("HEX code: #%s\n", output);
    }
    return 0;
}