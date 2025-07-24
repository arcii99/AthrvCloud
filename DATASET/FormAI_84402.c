//FormAI DATASET v1.0 Category: Color Code Converter ; Style: lively
#include <stdio.h>

// Function to convert RGB to hexadecimal color code
int rgbToHex(int r, int g, int b) {
    int hexCode = (r << 16) | (g << 8) | b;
    return hexCode;
}

// Function to convert hexadecimal color code to RGB values
void hexToRGB(int hexCode, int *r, int *g, int *b) {
    *r = (hexCode >> 16) & 0xFF;
    *g = (hexCode >> 8) & 0xFF;
    *b = hexCode & 0xFF;
}

// Main function
int main() {
    int choice = 0;
    printf("Welcome to the RGB to Hex and Hex to RGB color code converter!\n\n");
    
    do {
        int r, g, b, hexCode;
        printf("Please enter 1 to convert RGB to Hex code or 2 to convert Hex code to RGB: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("\nRGB to Hex code converter:\n");
            printf("Enter the values of R, G and B (each between 0 and 255, inclusive):\n");
            scanf("%d %d %d", &r, &g, &b);
            hexCode = rgbToHex(r, g, b);
            printf("The hexadecimal color code for RGB(%d,%d,%d) is #%06X\n\n", r, g, b, hexCode);
        } else if (choice == 2) {
            printf("\nHex code to RGB converter:\n");
            printf("Enter the hexadecimal color code (in the format of a 6-digit hexadecimal number, without the # symbol):\n");
            scanf("%X", &hexCode);
            hexToRGB(hexCode, &r, &g, &b);
            printf("The RGB values for #%06X are (%d,%d,%d)\n\n", hexCode, r, g, b);
        } else {
            printf("Invalid input. Please enter either 1 or 2.\n\n");
        }
    } while(choice != 1 && choice != 2);
    
    printf("Thank you for using the RGB to Hex and Hex to RGB color code converter!\n");
    
    return 0;
}