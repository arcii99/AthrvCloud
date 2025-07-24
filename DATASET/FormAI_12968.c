//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include<stdio.h>

int main()
{
    // Displaying options
    printf("Choose the color code conversion\n");
    printf("Press 1 for RGB to HEX\n");
    printf("Press 2 for HEX to RGB\n");

    // Taking input choice
    int choice;
    scanf("%d", &choice);

    if(choice == 1)
    {
        // RGB to HEX conversion
        int r, g, b;
        printf("Enter the RGB values (0-255)\n");
        scanf("%d %d %d", &r, &g, &b);

        // Converting to HEX
        int hex = (r << 16) + (g << 8) + b;

        // Displaying the result
        printf("The HEX value is #%06X\n", hex);
    }
    else if(choice == 2)
    {
        // HEX to RGB conversion
        int hex;
        printf("Enter the HEX value: \n");
        scanf("%x", &hex);

        // Extracting the RGB values
        int r = (hex >> 16) & 0xFF;
        int g = (hex >> 8) & 0xFF;
        int b = hex & 0xFF;

        // Displaying the result
        printf("The RGB values are: %d %d %d\n", r, g, b);
    }
    else
    {
        // Invalid choice
        printf("Invalid choice!\n");
   }

    return 0;
}