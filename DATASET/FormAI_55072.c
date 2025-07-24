//FormAI DATASET v1.0 Category: Color Code Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Color Code Converter! Let's get surreal!\n\n");

    int r, g, b, hex;
    char choice;

    printf("Enter 'h' to convert from RGB to Hex code, or 'r' to convert from Hex code to RGB: ");
    scanf("%c", &choice);

    if (choice == 'h')
    {
        printf("\nEnter the Red value (0-255): ");
        scanf("%d", &r);
        printf("\nEnter the Green value (0-255): ");
        scanf("%d", &g);
        printf("\nEnter the Blue value (0-255): ");
        scanf("%d", &b);

        hex = (r << 16) | (g << 8) | b;

        printf("\nThe Hex code is: #%06X\n", hex);
    }
    else if (choice == 'r')
    {
        printf("\nEnter the Hex code (e.g. 0xFFFFFF): ");
        scanf("%X", &hex);

        r = (hex >> 16) & 0xFF;
        g = (hex >> 8) & 0xFF;
        b = hex & 0xFF;

        printf("\nThe RGB values are: %d, %d, %d\n", r, g, b);
    }
    else
    {
        printf("\nThat is not a valid option. Goodbye.\n");
        return 0;
    }

    printf("\nThank you for using the Color Code Converter. Reality is just a pixelated dream.\n");

    return 0;
}