//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include<stdio.h>

int main() {
    int hexCode, red, green, blue;
    printf("Enter the hexadecimal color code: ");
    scanf("%x", &hexCode);
    
    // bitwise operations to separate the RGB components
    red = (hexCode >> 16) & 0xFF;
    green = (hexCode >> 8) & 0xFF;
    blue = hexCode & 0xFF;
    
    printf("RGB color code: %d, %d, %d\n", red, green, blue);
    
    // convert RGB to CMYK
    float c, m, y, k, r = red / 255.0, g = green / 255.0, b = blue / 255.0;
    if (r == 0 && g == 0 && b == 0) {
        c = m = y = k = 0;
    } else {
        k = 1 - fmax(fmax(r, g), b);
        c = (1 - r - k) / (1 - k);
        m = (1 - g - k) / (1 - k);
        y = (1 - b - k) / (1 - k);
    }
    printf("CMYK color code: %.2f, %.2f, %.2f, %.2f\n", c, m, y, k);
    
    // convert CMYK to RGB
    r = 255 * (1 - c) * (1 - k);
    g = 255 * (1 - m) * (1 - k);
    b = 255 * (1 - y) * (1 - k);
    printf("RGB color code from CMYK: %.0f, %.0f, %.0f\n", r, g, b);
    
    return 0;
}