//FormAI DATASET v1.0 Category: Color Code Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

int main() {
    char hex[7], red[3], green[3], blue[3];
    int r, g, b;

    printf("Enter hex color code: ");
    scanf("%s", hex);

    // Extract red, green, blue values from the hex code
    red[0] = hex[0];
    red[1] = hex[1];
    green[0] = hex[2];
    green[1] = hex[3];
    blue[0] = hex[4];
    blue[1] = hex[5];

    // Convert red, green, blue values from hex to decimal
    r = strtol(red, NULL, 16);
    g = strtol(green, NULL, 16);
    b = strtol(blue, NULL, 16);

    // Print the RGB values
    printf("RGB color code: (%d, %d, %d)\n", r, g, b);

    // Convert RGB values to CYMK
    float c, m, y, k;
    c = (1 - r / 255.0);
    m = (1 - g / 255.0);
    y = (1 - b / 255.0);
    
    if (c == 1 && m == 1 && y == 1) {
        k = 1;
    } else {
        k = fminf(c, fminf(m, y));
        c = (c - k) / (1 - k);
        m = (m - k) / (1 - k);
        y = (y - k) / (1 - k);
    }

    // Print the CMYK values
    printf("CMYK color code: (%.2f, %.2f, %.2f, %.2f)\n", c, m, y, k);

    return 0;
}