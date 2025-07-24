//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Claude Shannon
#include <stdio.h>

int main() {
    // Input variables
    int red, green, blue;

    // Prompt the user for RGB values
    printf("Enter the Red value (0-255): ");
    scanf("%d", &red);
    printf("Enter the Green value (0-255): ");
    scanf("%d", &green);
    printf("Enter the Blue value (0-255): ");
    scanf("%d", &blue);

    // Convert RGB to hexadecimal
    int hex = (red << 16) + (green << 8) + blue;

    // Output the hexadecimal value
    printf("The hexadecimal value is #%06x", hex);

    return 0;
}