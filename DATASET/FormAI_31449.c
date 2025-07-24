//FormAI DATASET v1.0 Category: Color Code Converter ; Style: curious
#include <stdio.h>

int main() {

    int rgb[3];

    // Prompt the user for RGB values
    printf("Please enter the RGB values separated by spaces: ");
    scanf("%d %d %d", &rgb[0], &rgb[1], &rgb[2]);

    // Convert RGB to C color code
    int c_color_code = (rgb[0] << 16) + (rgb[1] << 8) + rgb[2];

    // Print the C color code
    printf("\nC color code: %06X", c_color_code);

    // Ask the user if they want the color code broken down
    printf("\n\nDo you want to break down the C color code? (y/n): ");
    char answer;
    scanf("%s", &answer);

    // If the user wants to break down the color code
    if (answer == 'y' || answer == 'Y') {

        // Calculate the hex values for each RGB component
        int red_hex = (c_color_code & 0xFF0000) >> 16;
        int green_hex = (c_color_code & 0x00FF00) >> 8;
        int blue_hex = c_color_code & 0x0000FF;

        // Convert hex values to decimal values
        int red = red_hex;
        int green = green_hex;
        int blue = blue_hex;

        // Print the breakdown of the C color code
        printf("\n\nBreakdown of C color code:");
        printf("\nRed: %d (%02X)", red, red_hex);
        printf("\nGreen: %d (%02X)", green, green_hex);
        printf("\nBlue: %d (%02X)", blue, blue_hex);

    }

    return 0;

}