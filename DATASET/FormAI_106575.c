//FormAI DATASET v1.0 Category: Color Code Converter ; Style: futuristic
#include <stdio.h>

int main() {
    int red, green, blue, hex_code;
    
    printf("Enter the red component (0-255): ");
    scanf("%d", &red);
    
    printf("Enter the green component (0-255): ");
    scanf("%d", &green);
    
    printf("Enter the blue component (0-255): ");
    scanf("%d", &blue);
    
    hex_code = (red << 16) | (green << 8) | blue;
    
    printf("The hex code for RGB(%d,%d,%d) is #%06X\n", red, green, blue, hex_code);
    
    return 0;
}