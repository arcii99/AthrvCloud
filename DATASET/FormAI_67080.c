//FormAI DATASET v1.0 Category: Color Code Converter ; Style: introspective
#include <stdio.h>

int main() {
    
    int red, green, blue; // integer variables for RGB values
    
    printf("Enter the RGB values (0-255) separated by a space: ");
    scanf("%d %d %d", &red, &green, &blue); // read input values
    
    // convert RGB values to hex code
    int hexCode = ((red << 16) | (green << 8) | blue);
    
    printf("\nHex Code: #%06X\n", hexCode); // print hex code
    
    // convert hex code back to RGB values
    red = (hexCode >> 16) & 0xFF;
    green = (hexCode >> 8) & 0xFF;
    blue = hexCode & 0xFF;
    
    printf("RGB Values: %d %d %d\n", red, green, blue); // print RGB values
    
    return 0;
}