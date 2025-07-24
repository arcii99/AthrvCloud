//FormAI DATASET v1.0 Category: Color Code Converter ; Style: irregular
#include <stdio.h>

void convertToRGB(int hex_value) {
    int red = (hex_value & 0xFF0000) >> 16;
    int green = (hex_value & 0x00FF00) >> 8;
    int blue = (hex_value & 0x0000FF);
    printf("\nThe RGB color for the given hex code is: R=%d, G=%d, B=%d\n", red, green, blue);
}

void convertToHex(int r, int g, int b) {
    int hex_value = ((r << 16) & 0xFF0000) + ((g << 8) & 0x00FF00) + (b & 0x0000FF);
    printf("\nThe hex code for the given RGB color is: #%06X\n", hex_value);
}

int main() {
    int user_choice, red, green, blue, hex_value;
    printf("Welcome to the RGB to Hex & Hex to RGB Color Code Converter!\n");
    printf("Please select the type of conversion you want to perform:\n");
    printf("1. RGB to Hex Conversion\n");
    printf("2. Hex to RGB Conversion\n");
    printf("Your choice: ");
    scanf("%d", &user_choice);
    if (user_choice == 1) {
        printf("\nRGB to Hex Conversion:\n");
        printf("Enter the Red, Green, and Blue values of the color you want to convert (0-255):\n");
        printf("Red: ");
        scanf("%d", &red);
        printf("Green: ");
        scanf("%d", &green);
        printf("Blue: ");
        scanf("%d", &blue);
        convertToHex(red, green, blue);
    } else if (user_choice == 2) {
        printf("\nHex to RGB Conversion:\n");
        printf("Enter the hex code of the color you want to convert (without #): ");
        scanf("%d", &hex_value);
        convertToRGB(hex_value);
    } else {
        printf("\nInvalid input! Please choose either 1 or 2.\n");
    }
    printf("\nThank you for using the Color Code Converter!\n");
    return 0;
}