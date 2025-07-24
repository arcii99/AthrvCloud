//FormAI DATASET v1.0 Category: Color Code Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Get user input for RGB values
    int red;
    do {
        printf("Enter an integer value for red (0-255): ");
        scanf("%d", &red);
    } while (red < 0 || red > 255);

    int green;
    do {
        printf("Enter an integer value for green (0-255): ");
        scanf("%d", &green);
    } while (green < 0 || green > 255);

    int blue;
    do {
        printf("Enter an integer value for blue (0-255): ");
        scanf("%d", &blue);
    } while (blue < 0 || blue > 255);

    // Convert RGB to HEX
    char hex[7];
    sprintf(hex, "#%02X%02X%02X", red, green, blue);
    printf("The HEX code is: %s\n", hex);

    // Convert RGB to CMYK
    float c, m, y, k;
    float r = red / 255.0;
    float g = green / 255.0;
    float b = blue / 255.0;
    k = 1 - fmax(fmax(r, g), b);
    if (k != 1) {
        c = (1 - r - k) / (1 - k);
        m = (1 - g - k) / (1 - k);
        y = (1 - b - k) / (1 - k);
    } else {
        c = m = y = 0;
    }
    printf("The CMYK code is: %.2f %.2f %.2f %.2f\n", c, m, y, k);

    return 0;
}