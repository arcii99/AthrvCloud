//FormAI DATASET v1.0 Category: Color Code Converter ; Style: curious
#include <stdio.h>
#include <string.h>

int main() {
    char hex[7];
    printf("Input your hexadecimal color code:\n");
    scanf("%s", hex);

    // remove '#' if present
    if (hex[0] == '#') {
        memmove(hex, hex + 1, strlen(hex));
    }

    int r, g, b;
    sscanf(hex, "%02x%02x%02x", &r, &g, &b);
    
    printf("\nConverted RGB values:\n");
    printf("Red: %d\n", r);
    printf("Green: %d\n", g);
    printf("Blue: %d\n", b);

    // convert RGB to CMYK
    float c = 1 - (float)r / 255;
    float m = 1 - (float)g / 255;
    float y = 1 - (float)b / 255;
    float k = fminf(c, fminf(m, y));
    c = (c - k) / (1 - k);
    m = (m - k) / (1 - k);
    y = (y - k) / (1 - k);

    printf("\nConverted CMYK values:\n");
    printf("Cyan: %f\n", c);
    printf("Magenta: %f\n", m);
    printf("Yellow: %f\n", y);
    printf("Key (Black): %f\n", k);

    return 0;
}