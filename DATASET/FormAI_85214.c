//FormAI DATASET v1.0 Category: Color Code Converter ; Style: enthusiastic
#include <stdio.h>

int main() {
    int hex, red, green, blue;

    printf("Enter the hexadecimal value: ");
    scanf("%x", &hex);

    red = (hex & 0xFF0000) >> 16;
    green = (hex & 0x00FF00) >> 8;
    blue = hex & 0x0000FF;

    printf("The RGB color is: %02X %02X %02X\n", red, green, blue);

    return 0;
}