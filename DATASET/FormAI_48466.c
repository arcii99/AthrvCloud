//FormAI DATASET v1.0 Category: Color Code Converter ; Style: detailed
#include <stdio.h>
#include <string.h>

// Function to convert hex string to int
int hexToInt(char c)
{
    if(c >= '0' && c <= '9')
        return c - '0';
    else if(c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    else if(c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    else
        return -1;
}

// Function to convert RGB string to hexadecimal
char* RGBtoHex(int red, int green, int blue)
{
    char hex[7];
    sprintf(hex, "#%02X%02X%02X", red, green, blue);
    char* result = strdup(hex);
    return result;
}

// Function to convert hexadecimal string to RGB
void HexToRGB(char* hex, int* red, int* green, int* blue)
{
    if(hex[0] == '#')
        hex++;      // Ignore '#' if present
        
    int len = strlen(hex);
    
    // Convert string to RGB values
    sscanf(hex, "%02x%02x%02x", red, green, blue);
}

int main()
{
    int red, green, blue;
    char hex[7];
    
    printf("Please enter an RGB color code (e.g. '255,255,255'): ");
    scanf("%d,%d,%d", &red, &green, &blue);
    
    // Convert RGB to hex
    char* hexColor = RGBtoHex(red, green, blue);
    printf("Hex color code: %s\n", hexColor);
    
    printf("Please enter a hexadecimal color code (e.g. '#FFFFFF'): ");
    scanf("%s", hex);
    
    // Convert hex to RGB
    HexToRGB(hex, &red, &green, &blue);
    printf("RGB color code: %d,%d,%d\n", red, green, blue);
    
    return 0;
}