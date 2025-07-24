//FormAI DATASET v1.0 Category: Color Code Converter ; Style: cheerful
#include <stdio.h>

int main() {
    printf("Hi there! Let's convert some color codes today!\n\n");

    // Taking input from the user
    int r, g, b;
    printf("Enter the Red value (between 0-255): ");
    scanf("%d", &r);
    printf("Enter the Green value (between 0-255): ");
    scanf("%d", &g);
    printf("Enter the Blue value (between 0-255): ");
    scanf("%d", &b);

    // Converting the RGB values to hexadecimal
    int hex = ((r & 0xFF) << 16) + ((g & 0xFF) << 8) + (b & 0xFF);

    printf("\nYour RGB values of (%d,%d,%d) are converted to the hexadecimal color code: #%06X\n", r, g, b, hex);
    printf("Isn't that exciting?!\n");

    return 0;
}