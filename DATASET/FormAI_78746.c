//FormAI DATASET v1.0 Category: Color Code Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
    char hex_code[8];
    int red, green, blue;
    printf("Enter a hex color code: ");
    scanf("%s", hex_code);

    // convert the hex code to decimal values
    red = atoi(hex_code[0])*16 + atoi(hex_code[1]);
    green = atoi(hex_code[2])*16 + atoi(hex_code[3]);
    blue = atoi(hex_code[4])*16 + atoi(hex_code[5]);

    // display the RGB values
    printf("\nRGB Values: R = %d, G = %d, B = %d\n", red, green, blue);

    // generate the C color code
    printf("C Color Code: #%02x%02x%02x", red, green, blue);
    return 0;
}