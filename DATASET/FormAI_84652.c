//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
    /* This program converts color codes from RGB to hexadecimal */

    int red, green, blue;

    printf("Enter the red value (0-255): ");
    scanf("%d", &red);

    printf("Enter the green value (0-255): ");
    scanf("%d", &green);

    printf("Enter the blue value (0-255): ");
    scanf("%d", &blue);

    if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255) {
        printf("Invalid color values. Please enter values between 0 and 255.\n");
        return 1;
    }

    int hex_red = red / 16;
    int hex_green = green / 16;
    int hex_blue = blue / 16;

    printf("The hexadecimal value is #%X%X%X\n", hex_red, hex_green, hex_blue);

    return 0;
}