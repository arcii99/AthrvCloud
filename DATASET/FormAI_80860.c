//FormAI DATASET v1.0 Category: Color Code Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Function to convert RGB to HEX
void convertRGBtoHEX(int r, int g, int b) {
    char hexValue[7];
    sprintf(hexValue, "#%02X%02X%02X", r, g, b);
    printf("The hex code is %s\n", hexValue);
}

// Function to convert HEX to RGB
void convertHEXtoRGB(char hex[]) {
    int r, g, b;
    sscanf(hex, "#%02x%02x%02x", &r, &g, &b);
    printf("The RGB value is (%d, %d, %d)\n", r, g, b);
}

int main() {

    int choice;
    printf("Please choose an option:\n");
    printf("1. Convert RGB to HEX\n");
    printf("2. Convert HEX to RGB\n");
    scanf("%d", &choice);

    if (choice == 1) {
        int r, g, b;
        printf("Please enter the RGB value:\n");
        printf("R value (0-255): ");
        scanf("%d", &r);
        printf("G value (0-255): ");
        scanf("%d", &g);
        printf("B value (0-255): ");
        scanf("%d", &b);
        convertRGBtoHEX(r, g, b);

    } else if (choice == 2) {
        char hexValue[7];
        printf("Please enter the hex code:\n");
        scanf("%s", hexValue);
        convertHEXtoRGB(hexValue);

    } else {
        printf("Invalid choice. Please try again.\n");
        return 0;
    }

    return 0;
}