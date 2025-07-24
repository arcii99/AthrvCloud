//FormAI DATASET v1.0 Category: Color Code Converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main() {
    char hex[7];
    int red, green, blue;

    printf("Enter a hexadecimal color code: ");
    scanf("%s", hex);

    // Convert the hexadecimal color code to RGB values
    sscanf(hex, "%2x%2x%2x", &red, &green, &blue);

    // Convert the RGB values to decimal and print them out
    int decimal_red = red * 65536;
    int decimal_green = green * 256;
    int decimal_blue = blue;

    printf("RGB values: (%d, %d, %d)\n", decimal_red, decimal_green, decimal_blue);

    // Convert the decimal RGB values back to hexadecimal and print them out
    printf("Hexadecimal color code: #%02x%02x%02x\n", red, green, blue);

    return 0;
}