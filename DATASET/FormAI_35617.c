//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char hex[10], rgb[10], hexCode[7];
    int r = 0, g = 0, b = 0, i;

    printf("Enter a hex color code: ");
    fgets(hexCode, 7, stdin);
    sscanf(hexCode, "%x", &i);

    r = (i >> 16) & 0xFF;
    g = (i >> 8) & 0xFF;
    b = i & 0xFF;

    printf("\nColor converted from hex to RGB: %d, %d, %d\n", r, g, b);

    printf("\nEnter an RGB color code separated by commas: ");
    fgets(rgb, 10, stdin);
    sscanf(rgb, "%d,%d,%d", &r, &g, &b);

    sprintf(hex, "%02x%02x%02x", r, g, b);

    printf("\nColor converted from RGB to hex: #%s\n", hex);

    return 0;
}