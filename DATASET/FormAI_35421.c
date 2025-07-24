//FormAI DATASET v1.0 Category: Color Code Converter ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
    char hex[7];
    int r, g, b;

    printf("Welcome to the Color Code Converter!\n");
    printf("Enter a 6-digit hexadecimal color code: ");
    scanf("%s", hex);

    if (strlen(hex) != 6) {
        printf("Invalid color code entered. Please enter a 6-digit hexadecimal color code.\n");
        return 1;
    }

    // Convert hex to RGB values
    sscanf(hex, "%02x%02x%02x", &r, &g, &b);

    // Print RGB values
    printf("The RGB values for color code #%s are: %d, %d, %d\n", hex, r, g, b);

    // Convert RGB to CMYK values
    double c = 1 - ((double)r / 255);
    double m = 1 - ((double)g / 255);
    double y = 1 - ((double)b / 255);
    double k = fmin(c, fmin(m, y));

    c = (c - k) / (1 - k);
    m = (m - k) / (1 - k);
    y = (y - k) / (1 - k);

    // Print CMYK values
    printf("The CMYK values for color code #%s are: %.2f%%, %.2f%%, %.2f%%, %.2f%%\n", hex, c * 100, m * 100, y * 100, k * 100);

    return 0;
}