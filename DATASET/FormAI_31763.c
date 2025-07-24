//FormAI DATASET v1.0 Category: Color Code Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hexToDecimal(char hex[]);
void decimalToRGB(int decimal, int RGB[]);
void printRGB(int RGB[]);

int main()
{
    char hex[7];
    int RGB[3];

    // Take input from the user
    printf("Enter a 6-digit hexadecimal color code (without the # symbol): ");
    scanf("%s", hex);

    int decimal = hexToDecimal(hex); // Convert hex code to decimal code
    
    decimalToRGB(decimal, RGB); // Convert decimal code to RGB values
    
    printRGB(RGB); // Print the RGB values in the format "(R, G, B)"

    return 0;
}

// Function to convert hexadecimal code to decimal code
int hexToDecimal(char hex[])
{
    int decimal = (int) strtol(hex, NULL, 16);
    return decimal;
}

// Function to convert decimal code to RGB values
void decimalToRGB(int decimal, int RGB[])
{
    RGB[0] = (decimal >> 16) & 0xFF; // Get the red value
    RGB[1] = (decimal >> 8) & 0xFF; // Get the green value
    RGB[2] = decimal & 0xFF; // Get the blue value
}

// Function to print the RGB values in the format "(R, G, B)"
void printRGB(int RGB[])
{
    printf("RGB values: (%d, %d, %d)\n", RGB[0], RGB[1], RGB[2]);
}