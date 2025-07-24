//FormAI DATASET v1.0 Category: Color Code Converter ; Style: beginner-friendly
#include <stdio.h>

// function to convert RGB color values to HEX code
void convertToHex(int red, int green, int blue) {
    int hex;
    hex = (red << 16) + (green << 8) + blue;
    printf("The HEX code for RGB (%d, %d, %d) is: #%06X\n", red, green, blue, hex);
}

// function to convert HEX code to RGB color values
void convertToRGB(int hex) {
    int r = hex >> 16;
    int g = (hex >> 8) & 0xFF;
    int b = hex & 0xFF;
    printf("The RGB values for HEX #%06X are: (%d, %d, %d)\n", hex, r, g, b);
}

int main() {
    int choice;
    printf("Choose an option:\n");
    printf("1. Convert RGB to HEX\n");
    printf("2. Convert HEX to RGB\n");
    scanf("%d", &choice);
    if (choice == 1) {
        int red, green, blue;
        printf("Enter the RGB values (separated by spaces): ");
        scanf("%d %d %d", &red, &green, &blue);
        convertToHex(red, green, blue);
    }
    else if (choice == 2) {
        int hex;
        printf("Enter the HEX code (without the # symbol): ");
        scanf("%X", &hex);
        convertToRGB(hex);
    }
    else {
        printf("Invalid choice.\n");
    }
    return 0;
}