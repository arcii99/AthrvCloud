//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Donald Knuth
// Donald Knuth Style C Color Code Converter

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hexToRGB(char* hex, int rgb[]) {
    sscanf(hex, "%02x%02x%02x", &rgb[0], &rgb[1], &rgb[2]);
}

int main() {
    char hex[7];
    int rgb[3];

    printf("Enter 6 digit hexadecimal color code: ");
    fgets(hex, sizeof(hex), stdin);
    hex[strlen(hex) - 1] = '\0';

    hexToRGB(hex, rgb);

    printf("RGB value of %s is (%d, %d, %d)\n", hex, rgb[0], rgb[1], rgb[2]);

    return 0;
}