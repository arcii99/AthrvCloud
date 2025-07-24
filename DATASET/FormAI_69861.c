//FormAI DATASET v1.0 Category: Color Code Converter ; Style: unmistakable
#include <stdio.h>

int main() {
    // Request user input
    printf("Enter a valid color code in HEX format (e.g., #FF0000): ");
    char color_code[7];
    scanf("%s", color_code);

    // Convert HEX to RGB
    int r, g, b;
    sscanf(color_code, "#%02x%02x%02x", &r, &g, &b);

    // Print RGB values
    printf("RGB value: (%d, %d, %d)\n", r, g, b);

    // Convert RGB to HSL
    float h = 0, s = 0, l = 0;
    float r_norm = r / 255.0, g_norm = g / 255.0, b_norm = b / 255.0;
    float c_max = fmax(r_norm, fmax(g_norm, b_norm));
    float c_min = fmin(r_norm, fmin(g_norm, b_norm));
    float delta_c = c_max - c_min;

    if (delta_c == 0) {
        h = 0;
    } else if (c_max == r_norm) {
        h = 60 * fmod(((g_norm - b_norm) / delta_c), 6);
    } else if (c_max == g_norm) {
        h = 60 * (((b_norm - r_norm) / delta_c) + 2);
    } else {
        h = 60 * (((r_norm - g_norm) / delta_c) + 4);
    }

    if (h < 0) {
        h += 360;
    }

    l = (c_max + c_min) / 2;

    if (delta_c == 0) {
        s = 0;
    } else {
        s = delta_c / (1 - fabs(2 * l - 1));
    }

    // Print HSL values
    printf("HSL value: (%.2f, %.2f, %.2f)\n", h, s, l);

    return 0;
}