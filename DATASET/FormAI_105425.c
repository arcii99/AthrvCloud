//FormAI DATASET v1.0 Category: Color Code Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Function to convert RGB to HEX
void rgbToHex(int r, int g, int b, char hex[])
{
    // Convert RGB values to HEX
    sprintf(hex, "%02X%02X%02X", r, g, b);
}

// Function to convert HEX to RGB
void hexToRgb(char hex[], int* r, int* g, int* b)
{
    // Convert HEX value to RGB
    sscanf(hex, "%02X%02X%02X", r, g, b);
}

int main()
{
    int r, g, b;
    char hex[7];

    printf("RGB to HEX Converter\n");
    printf("====================\n");

    // Input RGB value from user
    printf("Enter Red value (0-255): ");
    scanf("%d", &r);

    printf("Enter Green value (0-255): ");
    scanf("%d", &g);

    printf("Enter Blue value (0-255): ");
    scanf("%d", &b);

    // Convert RGB to HEX
    rgbToHex(r, g, b, hex);
    printf("Hex Code: #%s\n", hex);

    // Input HEX value from user
    printf("\nHEX to RGB Converter\n");
    printf("====================\n");

    printf("Enter Hex Code (without #): ");
    scanf("%s", hex);

    // Convert HEX to RGB
    hexToRgb(hex, &r, &g, &b);
    printf("Red: %d\nGreen: %d\nBlue: %d\n", r, g, b);

    return 0;
}