//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Alan Touring
// This program converts a given color in RGB format to its equivalent hexadecimal color code.

#include <stdio.h>

int main() {
    int r, g, b;
    printf("Please enter the RGB values of the color:\n");
    printf("Red: ");
    scanf("%d", &r);
    printf("Green: ");
    scanf("%d", &g);
    printf("Blue: ");
    scanf("%d", &b);

    // Converting to hexadecimal code
    char hex[7];
    sprintf(hex, "#%02X%02X%02X", r, g, b);

    printf("The color code for RGB(%d, %d, %d) is %s\n", r, g, b, hex);
    return 0;
}