//FormAI DATASET v1.0 Category: Color Code Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
void convertToRGB(int, int *, int *, int *);
void convertToHex(int, int, int, char *);

int main() {
    int mode, r, g, b;
    char hex[7];

    printf("Welcome to C Color Code Converter!\n");
    printf("Please select the mode:\n1. RGB to HEX\n2. HEX to RGB\n\n");
    scanf("%d", &mode);

    if (mode == 1) {
        printf("Enter the red value (0-255): ");
        scanf("%d", &r);
        printf("Enter the green value (0-255): ");
        scanf("%d", &g);
        printf("Enter the blue value (0-255): ");
        scanf("%d", &b);
        convertToHex(r, g, b, hex);
        printf("The HEX code is %s\n", hex);
    } else if (mode == 2) {
        printf("Enter the HEX code (e.g. FFFFFF): ");
        scanf("%s", hex);
        convertToRGB(atoi(hex), &r, &g, &b);
        printf("The RGB code is (%d, %d, %d)\n", r, g, b);
    } else {
        printf("Invalid mode selected.\n");
    }

    return 0;
}

/* Function to convert RGB to HEX */
void convertToHex(int r, int g, int b, char *hex) {
    sprintf(hex, "%02X%02X%02X", r, g, b);
}

/* Function to convert HEX to RGB */
void convertToRGB(int hex, int *r, int *g, int *b) {
    *r = (hex >> 16) & 0xFF;
    *g = (hex >> 8) & 0xFF;
    *b = hex & 0xFF;
}