//FormAI DATASET v1.0 Category: Color Code Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>

int main() {
    int r, g, b;
    float h, s, v;

    printf("Enter red value (0-255): ");
    scanf("%d", &r);
    printf("Enter green value (0-255): ");
    scanf("%d", &g);
    printf("Enter blue value (0-255): ");
    scanf("%d", &b);

    // Convert from RGB to HSV
    float r_norm = ((float) r) / 255;
    float g_norm = ((float) g) / 255;
    float b_norm = ((float) b) / 255;

    float cmax = r_norm;
    if (g_norm > cmax) {
        cmax = g_norm;
    }
    if (b_norm > cmax) {
        cmax = b_norm;
    }

    float cmin = r_norm;
    if (g_norm < cmin) {
        cmin = g_norm;
    }
    if (b_norm < cmin) {
        cmin = b_norm;
    }

    float delta = cmax - cmin;

    // Calculate hue (in degrees)
    if (delta == 0) {
        h = 0;
    } else if (cmax == r_norm) {
        h = fmod(((g_norm - b_norm) / delta), 6);
    } else if (cmax == g_norm) {
        h = ((b_norm - r_norm) / delta) + 2;
    } else {
        h = ((r_norm - g_norm) / delta) + 4;
    }
    h = h * 60;

    if (h < 0) {
        h += 360;
    }

    // Calculate saturation and value
    if (cmax == 0) {
        s = 0;
    } else {
        s = delta / cmax;
    }

    v = cmax;

    // Convert from HSV to RGB
    cmax = v;
    cmin = v - (s * v);
    delta = cmax - cmin;

    if (h < 60) {
        r = cmax;
        g = cmin + (delta * h / 60);
        b = cmin;
    } else if (h < 120) {
        r = cmin + (delta * (120 - h) / 60);
        g = cmax;
        b = cmin;
    } else if (h < 180) {
        r = cmin;
        g = cmax;
        b = cmin + (delta * (h - 120) / 60);
    } else if (h < 240) {
        r = cmin;
        g = cmin + (delta * (240 - h) / 60);
        b = cmax;
    } else if (h < 300) {
        r = cmin + (delta * (h - 240) / 60);
        g = cmin;
        b = cmax;
    } else {
        r = cmax;
        g = cmin;
        b = cmin + (delta * (360 - h) / 60);
    }

    r = r * 255;
    g = g * 255;
    b = b * 255;

    printf("The color in RGB is: (%d, %d, %d)\n", r, g, b);

    return 0;
}