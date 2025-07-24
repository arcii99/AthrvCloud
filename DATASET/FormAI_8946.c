//FormAI DATASET v1.0 Category: Color Code Converter ; Style: safe
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to convert RGB color code to HEX color code
char* rgb_to_hex(int r, int g, int b) {
    static char hex[8];
    sprintf(hex, "#%02X%02X%02X", r, g, b);
    return hex;
}

// Function to convert HEX color code to RGB color code
bool hex_to_rgb(const char* hex, int* r, int* g, int* b) {
    if (strlen(hex) != 7 || hex[0] != '#') {
        return false; // Invalid HEX color code format
    }
    unsigned int hex_value;
    if (sscanf(hex + 1, "%x", &hex_value) != 1) {
        return false; // Failed to parse HEX color code
    }
    *r = hex_value >> 16;
    *g = (hex_value >> 8) & 0xFF;
    *b = hex_value & 0xFF;
    return true;
}

int main() {
    // Convert RGB color code to HEX color code
    int r = 255, g = 165, b = 0;
    char* hex = rgb_to_hex(r, g, b);
    printf("RGB(%d,%d,%d) = %s\n", r, g, b, hex);

    // Convert HEX color code to RGB color code
    const char* hex_code = "#FFA500";
    int r_new, g_new, b_new;
    bool success = hex_to_rgb(hex_code, &r_new, &g_new, &b_new);
    if (success) {
        printf("HEX(%s) = RGB(%d,%d,%d)\n", hex_code, r_new, g_new, b_new);
    } else {
        printf("Failed to convert HEX code %s to RGB\n", hex_code);
    }
    return 0;
}