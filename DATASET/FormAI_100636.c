//FormAI DATASET v1.0 Category: Color Code Converter ; Style: authentic
#include <stdio.h>
#include <string.h>

// Function to convert RGB color code to HEX color code
void RGBtoHEX(int r, int g, int b, char* hexCode) {
    sprintf(hexCode, "#%02X%02X%02X", r, g, b);
}

// Function to convert HEX color code to RGB color code
void HEXtoRGB(char* hexCode, int* r, int* g, int* b) {
    sscanf(hexCode, "#%02X%02X%02X", r, g, b);
}

int main() {
    char hexCode[7];
    int r = 255;
    int g = 128;
    int b = 0;

    // Converting RGB color code to HEX color code
    RGBtoHEX(r, g, b, hexCode);

    printf("RGB color code: (%d, %d, %d)\n", r, g, b);
    printf("HEX color code: %s\n", hexCode);

    // Converting HEX color code to RGB color code
    HEXtoRGB(hexCode, &r, &g, &b);

    printf("HEX color code: %s\n", hexCode);
    printf("RGB color code: (%d, %d, %d)\n", r, g, b);

    return 0;
}