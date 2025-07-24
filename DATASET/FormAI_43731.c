//FormAI DATASET v1.0 Category: Color Code Converter ; Style: detailed
#include <stdio.h>

int main() {
    int red, green, blue;
    printf("Enter the RGB values (0-255) of a color: ");
    scanf("%d %d %d", &red, &green, &blue);

    int hex1 = red / 16;
    int hex2 = red % 16;
    int hex3 = green / 16;
    int hex4 = green % 16;
    int hex5 = blue / 16;
    int hex6 = blue % 16;

    char hex_code[7];
    sprintf(hex_code, "#%X%X%X%X%X%X", hex1, hex2, hex3, hex4, hex5, hex6);

    printf("The HTML color code for (%d, %d, %d) is: %s\n", red, green, blue, hex_code);

    return 0;
}