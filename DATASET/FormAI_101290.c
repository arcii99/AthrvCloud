//FormAI DATASET v1.0 Category: Color Code Converter ; Style: lively
#include <stdio.h>
#include <string.h>

int main() {
    char hexColor[7];
    printf("Enter a hex color code: ");
    scanf("%s", hexColor);

    if (strlen(hexColor) != 6) {
       printf("Invalid hex color code.\n");
       return 1;
    }

    int r = (int)strtol(hexColor, NULL, 16) >> 16;
    int g = (int)strtol(hexColor, NULL, 16) >> 8 & 0xff;
    int b = (int)strtol(hexColor, NULL, 16) & 0xff;

    float R = r / 255.0;
    float G = g / 255.0;
    float B = b / 255.0;

    printf("\nRGB color code: (%d, %d, %d)\n", r, g, b);
    printf("Floating point values: (%.2f, %.2f, %.2f)\n", R, G, B);

    return 0;
}