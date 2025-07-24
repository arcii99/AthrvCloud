//FormAI DATASET v1.0 Category: Color Code Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int red, green, blue;  
    int hex_value;         
    char hex_code[7];     
    printf("Enter the RGB values (0-255) \n");
    printf("Red Value: ");
    scanf("%d", &red);
    printf("Green Value: ");
    scanf("%d", &green);
    printf("Blue Value: ");
    scanf("%d", &blue);
    if ((red > 255 || red < 0) || (green > 255 || green < 0) || (blue > 255 || blue < 0)) {
        printf("Invalid RGB values \n");
        exit(0);
    }
  
    hex_value = (red << 16) + (green << 8) + blue;  
    sprintf(hex_code, "#%06x", hex_value);  
    
    printf("\nHex Code: %s\n", hex_code);
    return 0;
}