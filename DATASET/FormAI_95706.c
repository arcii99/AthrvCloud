//FormAI DATASET v1.0 Category: Color Code Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

int main() {
    char hexCode[8], redHex[3], greenHex[3], blueHex[3];
    int red, green, blue;

    // Get color hex code from user
    printf("Enter a 6-digit hex color code (e.g. FF0000 for red): ");
    scanf("%s", hexCode);

    // Split hex code into red, green, and blue components
    redHex[0] = hexCode[0];
    redHex[1] = hexCode[1];
    redHex[2] = '\0';
    greenHex[0] = hexCode[2];
    greenHex[1] = hexCode[3];
    greenHex[2] = '\0';
    blueHex[0] = hexCode[4];
    blueHex[1] = hexCode[5];
    blueHex[2] = '\0';

    // Convert hex code to decimal values
    red = strtol(redHex, NULL, 16);
    green = strtol(greenHex, NULL, 16);
    blue = strtol(blueHex, NULL, 16);

    // Print RGB values
    printf("RGB color code: (%d, %d, %d)\n", red, green, blue);

    return 0;
}