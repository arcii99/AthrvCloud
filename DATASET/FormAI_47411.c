//FormAI DATASET v1.0 Category: Color Code Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char color[7];
    int red, green, blue;
    
    printf("Enter color code (in format RRGGBB): ");
    scanf("%s", color);
    
    // Convert color code to RGB values
    sscanf(color, "%02x%02x%02x", &red, &green, &blue);
    
    // Output RGB values
    printf("RGB values: (%d, %d, %d)\n", red, green, blue);
    
    // Convert RGB values to CYMK values
    float c, m, y, k;
    c = 1 - (float)red/255;
    m = 1 - (float)green/255;
    y = 1 - (float)blue/255;
    k = c < m ? c : m;
    k = k < y ? k : y;
    c = (c - k) / (1 - k);
    m = (m - k) / (1 - k);
    y = (y - k) / (1 - k);
    
    // Output CMYK values
    printf("CMYK values: (%.2f, %.2f, %.2f, %.2f)\n", c, m, y, k);
    
    return 0;
}