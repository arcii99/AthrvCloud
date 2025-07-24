//FormAI DATASET v1.0 Category: Color Code Converter ; Style: immersive
#include <stdio.h>

int main() {

    char hex[6]; // create an array to store 6 characters for the hex code
    printf("Please enter a Hex color code (eg. FFFFFF): ");
    scanf("%s", hex);

    // convert the hex code to RGB values
    int r, g, b;
    sscanf(hex, "%2x%2x%2x", &r, &g, &b);

    printf("The RGB color code is: %d,%d,%d\n", r, g, b);

    // convert the RGB values to CMYK values
    double c, m, y, k;
    c = 1 - (double)r/255;
    m = 1 - (double)g/255;
    y = 1 - (double)b/255;
    double min = (c < m) ? c : m;
    min = (min < y) ? min : y;
    k = min;
    if (k == 1) { // avoid division by zero
        c = 0;
        m = 0;
        y = 0;
    } else {
        c = (c - k)/(1 - k);
        m = (m - k)/(1 - k);
        y = (y - k)/(1 - k);
    }

    printf("The CMYK color code is: %.2f, %.2f, %.2f, %.2f\n", c, m, y, k);

    return 0;
}