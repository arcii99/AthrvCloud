//FormAI DATASET v1.0 Category: Color Code Converter ; Style: optimized
#include <stdio.h>

int main() {
    int RgbColorCode, RgbColorRed, RgbColorGreen, RgbColorBlue;
    char hexChar[7];
    
    // Prompt user to enter RGB color code
    printf("Enter RGB color code (in the format R,G,B): ");
    scanf("%d,%d,%d", &RgbColorRed, &RgbColorGreen, &RgbColorBlue);
    
    // Convert RGB color code to Hexadecimal color code
    sprintf(hexChar, "#%02X%02X%02X", RgbColorRed, RgbColorGreen, RgbColorBlue);
    
    // Display Hexadecimal color code
    printf("Hexadecimal color code is: %s\n", hexChar);
    
    // Convert Hexadecimal color code to RGB color code
    sscanf(hexChar, "#%02X%02X%02X", &RgbColorRed, &RgbColorGreen, &RgbColorBlue);
    
    // Display RGB color code
    printf("RGB color code is: (%d,%d,%d)", RgbColorRed, RgbColorGreen, RgbColorBlue);
    
    return 0;
}