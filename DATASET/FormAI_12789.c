//FormAI DATASET v1.0 Category: Color Code Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int red, green, blue;
    double cyan, magenta, yellow, black, white;
    
    // Get RGB values from user input
    printf("Enter the RGB values (0-255):\n");
    printf("Red: ");
    scanf("%d", &red);
    printf("Green: ");
    scanf("%d", &green);
    printf("Blue: ");
    scanf("%d", &blue);
    
    // Convert RGB to CMYK
    cyan = 1 - (red / 255.0);
    magenta = 1 - (green / 255.0);
    yellow = 1 - (blue / 255.0);
    
    // Find the minimum value for black
    if (cyan < magenta) {
        black = cyan;
    } else {
        black = magenta;
    }
    
    if (yellow < black) {
        black = yellow;
    }
    
    // Calculate the white value
    white = 1 - black;
    
    // Convert CMYK to RGB
    red = (int) ((1 - cyan) * white * 255.0);
    green = (int) ((1 - magenta) * white * 255.0);
    blue = (int) ((1 - yellow) * white * 255.0);
    
    // Print the results
    printf("\n");
    printf("RGB: %d,%d,%d\n", red, green, blue);
    printf("CMYK: %.2f,%.2f,%.2f,%.2f\n", cyan, magenta, yellow, black);
    
    return 0;
}