//FormAI DATASET v1.0 Category: Color Code Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

void hexToRgb(char hex[], int rgb[]) {
    // Convert two-digit hex values to decimal and store in rgb array
    for (int i = 0; i < 3; i++) {
        char hexValue[3] = {hex[i*2], hex[(i*2)+1], '\0'};
        rgb[i] = strtol(hexValue, NULL, 16);
    }
}

void rgbToHex(int rgb[], char hex[]) {
    // Convert decimal values to two-digit hex and store in hex array
    for (int i = 0; i < 3; i++) {
        snprintf(hex+(i*2), 3, "%02X", rgb[i]);
    }
}

int main() {
    char input[8];
    int rgb[3];
    char output[8];

    // Prompt user for input
    printf("Enter a 6-digit hexadecimal color code or an RGB value in the format 'R, G, B': ");
    fgets(input, sizeof(input), stdin);

    // Determine input format and convert to RGB array
    if (input[0] == '#') {
        hexToRgb(&input[1], rgb);
    } else {
        sscanf(input, "%d, %d, %d", &rgb[0], &rgb[1], &rgb[2]);
    }

    // Convert RGB array to hexadecimal color code
    rgbToHex(rgb, output);

    // Print output
    printf("Output: #%s\n", output);

    return 0;
}