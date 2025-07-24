//FormAI DATASET v1.0 Category: Color Code Converter ; Style: energetic
#include <stdio.h>

int main() {
    // Variable to store RGB color values
    int red, green, blue;

    printf("Welcome to the Color Code Converter App!\n\n");

    printf("Please enter the Red component value (0-255): ");
    scanf("%d", &red);

    printf("Please enter the Green component value (0-255): ");
    scanf("%d", &green);

    printf("Please enter the Blue component value (0-255): ");
    scanf("%d", &blue);

    // Convert RGB to HEX
    int hexValue = ((red << 16) | (green << 8) | (blue));

    printf("\nYour RGB color code is: (%d, %d, %d)\n", red, green, blue);
    printf("Your HEX color code is: #%06x", hexValue);
    printf("\n\nThank you for using the Color Code Converter App!\n");

    return 0;
}