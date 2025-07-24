//FormAI DATASET v1.0 Category: Color Code Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main() {
    char colorCode[7];
    printf("Enter a color code (format: RRGGBB): ");
    scanf("%s", colorCode);

    int red = strtol(colorCode, NULL, 16) >> 16;
    int green = (strtol(colorCode, NULL, 16) & 0x00FF00) >> 8;
    int blue = strtol(colorCode, NULL, 16) & 0x0000FF;

    printf("RGB values: R=%d G=%d B=%d\n", red, green, blue);

    return 0;
}