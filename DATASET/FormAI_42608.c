//FormAI DATASET v1.0 Category: Color Code Converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
    char color[7]; // Declare an array to store color code
    printf("Enter the hex color code (example: #FF5733): ");
    scanf("%s", color); // Read hex color code input from user into 'color' array
    
    // Initializing RGB color values to zero
    int red = 0;
    int green = 0;
    int blue = 0;

    // Converting hex color code to RGB color values
    sscanf(color, "%02x%02x%02x", &red, &green, &blue);

    // Outputting RGB color values
    printf("RGB color code: (%d, %d, %d)", red, green, blue);

    return 0;
}