//FormAI DATASET v1.0 Category: Color Code Converter ; Style: retro
#include <stdio.h>

int main()
{
    char hex[7];
    int red, green, blue;
    
    printf("Enter a 6-digit hexadecimal color code: ");
    scanf("%s", hex);
    printf("\n");
    
    // Convert hex color code to RGB values
    sscanf(hex, "%02x%02x%02x", &red, &green, &blue);
    
    // Output RGB values
    printf("RGB values: R=%d, G=%d, B=%d\n", red, green, blue);
    
    // Convert RGB values to hex color code
    sprintf(hex, "%02X%02X%02X", red, green, blue);
    
    // Output hex color code
    printf("Hex color code: %s\n", hex);
    
    return 0;
}