//FormAI DATASET v1.0 Category: Color Code Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char hex[7], rgb[15];
    int r, g, b;
    printf("Enter 6-digit hexadecimal code: "); 
    scanf("%s", &hex);

    // Convert hex code to RGB values
    sscanf(hex, "%02x%02x%02x", &r, &g, &b);

    // Convert RGB values to C Color code
    sprintf(rgb, "RGB(%d,%d,%d)", r, g, b);
    printf("%s\n", rgb);

    return 0;
}