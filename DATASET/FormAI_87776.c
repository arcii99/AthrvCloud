//FormAI DATASET v1.0 Category: Color Code Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char hexCode[8];
    printf("Enter the hexadecimal color code (format: #RRGGBB): ");
    scanf("%s", hexCode);

    if (strlen(hexCode) != 7 || hexCode[0] != '#') {
        printf("Invalid color code!\n");
        return 0;
    }

    char redHex[3], greenHex[3], blueHex[3];
    strncpy(redHex, hexCode + 1, 2);
    redHex[2] = '\0';
    strncpy(greenHex, hexCode + 3, 2);
    greenHex[2] = '\0';
    strncpy(blueHex, hexCode + 5, 2);
    blueHex[2] = '\0';

    int red = strtol(redHex, NULL, 16);
    int green = strtol(greenHex, NULL, 16);
    int blue = strtol(blueHex, NULL, 16);

    printf("RGB color code: (%d,%d,%d)\n", red, green, blue);

    return 0;
}